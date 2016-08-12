/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP by a factor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int factor = atoi(argv[1]);

    //Cheking for the factor to be true
    if (factor < 1 || factor > 100)
    {
        printf("please, enter a factor from 1 to 100\n");
        return 5;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // saving the old headers
    int prepadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int prewidth = bi.biWidth;
    int preheight = bi.biHeight;

    //Modifing the headers
    bi.biHeight = bi.biHeight * factor;
    bi.biWidth = bi.biWidth * factor;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bf.bfSize = bf.bfOffBits + abs(bi.biHeight) * (bi.biWidth * 3 + padding) ;
    bi.biSizeImage = abs(bi.biHeight) *( bi.biWidth * 3 + padding);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(preheight); i < biHeight; i++)
    {   
        for(int o = 0 ; o < factor  ; o++)
        {   
            // iterate over pixels in scanline
            for (int j = 0; j < prewidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for(int l = 0 ; l < factor ; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            if (o != (factor-1)) 
            {
                fseek(inptr, prewidth* -3  , SEEK_CUR);
            }
        }
         
        // skip over padding, if any
        fseek(inptr, prepadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

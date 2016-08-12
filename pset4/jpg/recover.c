/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //Opens the recovery file
    FILE* card = fopen("card.raw", "r");
    
    //Checks for the correctness of the file pointer
    if (card == NULL)
    {
        printf("Could not open the file\n");
        return 1;
    }
    
    //Declaring variables
    unsigned char buffer[512];
    int first_read = 0;
    int counter = 1;
    FILE* pic;
    char file_name[7];
    
    
    while (fread(&buffer, sizeof(buffer), 1, card))
    {
        if  (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)) 
        {
            //checks for the first read to open the file pointer
            if (first_read == 1)
            {
                fclose(pic);
                sprintf(file_name,"%03d.jpg",counter);
                counter++;
                pic = fopen(file_name, "w");
            }
            else
            {
                first_read = 1;
                pic = fopen("000.jpg","w");
            }
        }
        else
        {
            if (first_read == 0)
            {
                continue;
            }
        }
        //writes the size of a sector to the file
        fwrite(&buffer,sizeof(buffer),1,pic);
    }
    fclose(pic);
    fclose(card);
    return 0;
}

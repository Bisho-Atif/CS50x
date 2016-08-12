#include <stdio.h>
#include "cs50.h"

int main()
{
    int i,j,k,height;

    //Taking the input from the User
    do{
        printf("Height: ");
        height = GetInt();
    } while (height < 0 || height > 23);

    //Mapping the height into mario's pyramid
    for(i = 0; i< height; i++){
        for(j = 0 ; j< height-i-1 ; j++){
            printf(" ");
        }

        for(k = 0 ; k < i+2;k++){
            printf("#");
        }

        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include "cs50.h"

int main()
{
    //User Input
    printf("minutes: ");
    int time = GetInt();

    //Calculating the number of bottles
    int bottles = time * 12;
    printf("bottles: %d\n",bottles);
    return 0;
}

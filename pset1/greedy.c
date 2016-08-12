#include <stdio.h>
#include "cs50.h"
#include <math.h>

//Global Variables
int bites = 0;
float change ;

void change_bites(int coin);


int main()
{
    //Taking the input
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n" );
        change = GetFloat();
    }
    while(change < 0);

    //transforming from dollar to cents
    change = roundf(change*100);

    //Calculating the number of bites
    change_bites(25); //Calculating with 25 cents
    change_bites(10); //Calculating with 10 cents
    change_bites(5);  //Calculating with 5 cents
    change_bites(1);  //Calculating with 1 cents

    printf("%d\n",bites);
    return 0;
}

void change_bites(int coin)
{
    bites += (int)change/coin;
    change = fmod(change,coin);
}

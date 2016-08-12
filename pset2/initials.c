#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(){
    //Getting the input from the user
    string name = GetString();

    //Printing the First character of each word in the user's string
    printf("%c",toupper(name[0]));
    for(int i = 0 , length = strlen(name) ; i < length ; i++){
        if(isspace(name[i]))    printf("%c",toupper(name[i+1]));
    }
    printf("\n");
}

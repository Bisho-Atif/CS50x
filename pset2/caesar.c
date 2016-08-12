#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

//Function Declaration
char change_position(char character , int k);

//Getting the input from user with command line arguments
int main(int argc,string argv[]){

    //Checking for the key input, must be 1 extra command-line-argument and is digit
    if (argc != 2 || !isdigit(argv[1][0])){
        printf("Usage: ./caesar digit\n");
        return 1;
    }

    int k = atoi(argv[1]); // Initializing the key

    //Getting the Plain_text
    string text = GetString();

    //Printing the encrypted text
    for (int i = 0 , n = strlen(text) ; i < n ; i++){
        text[i] = change_position(text[i],k);
        printf("%c",text[i] );
    }
    printf("\n");
}

/*  changing the position of the character by a key
    It also depends on the case of the character , lower or upper case  */
char change_position(char character , int k){
    if(isupper(character)){
        return  64 +(k + character - 64)%26;
    }
    else if(islower(character)){
    return  96 +(k + character - 96)%26;
    }
    else{
        return character;
    }
}

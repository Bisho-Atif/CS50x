#include <stdio.h>
#include "cs50.h"
#include <ctype.h>
#include <string.h>

char change_position(char character , int key);
int key_generator(char x);
int isalpha_string(string s);

int main(int argc, string argv[]){

    //Checking for the input "must accept a single command-line argument composed entirely of alphabetical characters"
    if (argc != 2 || !isalpha_string(argv[1])){
        printf("Please, Try again\n");
        return 1;
    }

    //Getting the input
    string text = GetString();

    //Printing the encrypted text
    for(int i = 0 , j = 0 , key_len = strlen(argv[1]) , text_len = strlen(text) , k ; i < text_len ; i++ ){

        //Making sure that the character of encrypted is alphabetical
        if (!isalpha(text[i])) {
            printf("%c",text[i]);
            continue;
        }

        k = key_generator(argv[1][j]); //Generating the number corresponding to the key's character
        j++; //looping the key inputted
        if (j == key_len) j = 0;
        text[i] = change_position(text[i],k); //Changing the position of the character
        printf("%c",text[i]);
    }
    printf("\n");
    return 0;
    }

//This Function takes the character and the shifting key and returns the shifted character
char change_position(char character , int key){
    if(isupper(character)) return  65 +(key + character - 65)%26;
    if(islower(character)) return  97 +(key + character - 97)%26;
    return 0;
}

//This function is to convert the character of the key to a shift nubmer for encryption
int key_generator(char x){
    if (isupper(x)) return (x - 65);
    if (islower(x)) return (x - 97);
    return 0;
}

//This function is to check that the command-line-argument inputted is only contains alphabetical characters
int isalpha_string(string s){
    for(int i = 0 , l = strlen(s) ; i < l ; i++){
        if (!isalpha(s[i])) return 0;
    }
    return 1;
}

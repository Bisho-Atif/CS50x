/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HASH_LENGTH 400

//global variables
node* hash_table[HASH_LENGTH];
int words_counter = 0;
char new_word[LENGTH+1];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(char* word)
{
    //making the word in lower case to search it in the dictionary 
    for(int i = 0, x = strlen(word); i < x+1; i++)
    {
        new_word[i] = tolower(word[i]);
        
    }
    
    //searching the word in the hash table
    if(search(new_word,hash_table[hash(new_word)])) return true;
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //declaring variables
    char word[LENGTH + 1];
    int hash_value = 0;
    
    //opening the dictionary file
    FILE* fp = fopen(dictionary, "r");
    
    while(!feof(fp))
    {
        //reads a word by word from the dictionary file
        fscanf(fp,"%s\n",word);
        
        //getting the hash value of the word
        hash_value = hash(word);
        
        //making new node for the new word
        node* new_node = malloc(sizeof(node));
        strcpy(new_node->data, word);
        new_node->next = hash_table[hash_value];
        hash_table[hash_value] = new_node;
        
        //Counting the words in the dictionary
        words_counter++;
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
   return words_counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0 ; i < HASH_LENGTH ; i++)
    {
        delete_node(hash_table[i]);
    }
    return true;
}

//Hashing the word to a special integer
int hash(char* s)
{
    int sum = 0;
    for(int i =0; s[i] != '\0'; i++)
    {
        sum += s[i];
    }
    return sum % HASH_LENGTH;
}

//Free the nodes of the hash table 
void delete_node(node* n)
{
    if (n == NULL) return;
    if(n->next != NULL) delete_node(n->next);
    free(n);
}

//Searching for a word in a linked list "index of the hash table"
bool search(char* word, node* head)
{
    while(head != NULL)
    {
        if(!strcmp(word,head->data)) return true;
        head = head->next;
    }
    return false;
}

/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"
#include <stdio.h>

bool binary_search(int value, int values[], int start , int end);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    n = n-1;
    return  binary_search(value , values , 0 , n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int counter = 0;
    for (int i = 1 , temp = 0; i < n ; i++){
        if (values[i-1] > values[i]) {
            temp = values[i-1];
            values[i-1] = values[i];
            values[i] = temp;
            counter++;
        }
    }
    if (counter == 0)  return;
    sort( values,  n);
}

// This is my binary_search function .. it loops in the array and modify the midpoint based on the input value
bool binary_search(int value, int values[], int start , int end){
    int mid;
    while(true){
        if ((end - start) == 1 || (end - start) == 0){
            if ((values[end] == value) || (values[start] == value)){
                return true;
            }
            else{
            return false;
            }
        }
        else if ((end - start) > 1){
            mid = (start+end)/2;
            if (values[mid] == value){
                return true;
            }
            else if (values[mid] > value){
                end = mid -1;
                continue;
            }
            else if (values[mid] < value){
                start = mid + 1;
                continue;
            }
        }
    return false;
    }
}

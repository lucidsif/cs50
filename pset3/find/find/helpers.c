/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include "helpers.h"
#include <stdio.h>
#include <string.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0) {
        return false;
    }
    
    int lowIndex = 0;
    int highIndex = n - 1;
    
    // TODO: implement a searching algorithm
    // while length of array is greater than 0 
    while (highIndex >= lowIndex) {
        int midpoint = (lowIndex + highIndex) / 2;
        if (values[midpoint] == value) {
            return true;
        } else if (values[midpoint] < value) {
            lowIndex = midpoint + 1;
            
        } else {
            highIndex = midpoint - 1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    for (int m = 0; m < n; m++) {
}
    // TODO: implement a sorting algorithm with run time of O(n^2)
    /*
    for (int i = 1; i < n; i++) {
        int temp = values[i];
        int j = i - 1;
        while (values[j] > temp && j >= 0) {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = temp;
    }
    */
    
    // TODO: implement a sorting algorithm with run time of O(n)
    // create a counting array with known range of numbers
    int countingArr[65537];
    for (int k = 0; k < 65537; k++) {
        countingArr[k] = 0;
    }
    // loop through each element in values arr and increment the counter on the counting array for each element 
    for (int i = 0; i < n; i++) {
        int currVal = values[i];
        countingArr[currVal] += 1;
    }
    // construct a sorted array based on the counting array
    int currPosition = 0;
    for (int j = 0; j < 65536; j++) {
        int curVal = j;
        int tallies = countingArr[j];
        while (tallies > 0) {
            values[currPosition] = curVal;
            tallies -= 1;
            currPosition += 1;
        }
    }
}

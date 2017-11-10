#include <stdio.h>
#include <cs50.h> 
#include <string.h> // strlen
#include <ctype.h> // isupper, islower, isalpha

// take command line arguments
int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("enter a key integer\n");
        return 1;
    }
    
    string plaintext;
    // convert key string to integer
    int key = atoi(argv[1]);
    //string ciphertext;
    
    do {
        printf("plaintext:");
        plaintext = get_string();
    }
    while(!plaintext);
    
    // generate cipher text by looping through each char
    // in plaintext and shifting character by key
    printf("ciphertext:");
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        int asciiValue = plaintext[i];
        int alphabeticalIndex;
        char cipherChar;
        char cipherCharConverted;
        
        if (isalpha(plaintext[i]) && islower(plaintext[i])) {
            // convert ascii value of ccharacter to alphabetical index
            alphabeticalIndex = asciiValue - 97;
            // apply caesar's formula to the alphabetical index
            cipherChar = (alphabeticalIndex + key) % 26;
            // convert alphabetical index to ascii value and print
            cipherCharConverted = cipherChar + 97;
            printf("%c", cipherCharConverted);
        } else if (isalpha(plaintext[i]) && isupper(plaintext[i])) {
            // convert ascii value of character to alphabetical index
            alphabeticalIndex = asciiValue - 65;
            // apply caesar's formula to the alphabetical index
            cipherChar = (alphabeticalIndex + key) % 26;
            // convert alphabetical index to ascii value and print
            cipherCharConverted = cipherChar + 65;
            printf("%c", cipherCharConverted);
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
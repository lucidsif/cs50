#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("enter a key integer, noob\n");
        return 1;
    }
    string key = argv[1];
    
    // convert each lowercase character to uppercase
    
    for (int j = 0, n = strlen(key); j < n; j++) {
        if (!isalpha(key[j])) {
            printf("enter a valid string of alphabets for the key\n");
            return 1;
        }
        if (islower(key[j])) {
            char asciiVal = key[j];
            asciiVal -= 32;
            key[j] = asciiVal;
        }
    }
    
    string plaintext;
    
    do {
        printf("plaintext:");
        plaintext = get_string();
    }
    while(!plaintext);
    
    
    printf("ciphertext:");
    // loop through each character in plaintext
    for (int i = 0, l = strlen(plaintext); i < l; i++) {
        // get asciiValue of character in plaintext
        int plainAsciiValue = plaintext[i];
        int plainAlphabeticalIndex;
        int keyIndex = i % strlen(key);
        // get asciivalue of element in current index of key
        int keyAsciiValue = key[keyIndex];
        // get alphabetical index of the key's character's ascii value
        int keyAlphabeticalIndex = keyAsciiValue - 65;
        char cipherAlphabeticalIndex;
        char cipherAsciiValue;
        if (isalpha(plaintext[i]) && islower(plaintext[i])) {
            // get alphabetical index of the plaintext's character's ascii value
            plainAlphabeticalIndex = plainAsciiValue - 97;
            // get cipherchar by adding plaintext char AI and key char AI mod 26
            cipherAlphabeticalIndex = (plainAlphabeticalIndex + keyAlphabeticalIndex) % 26;
            // convert alphabetical index of cipherchar to ascii value
            cipherAsciiValue = cipherAlphabeticalIndex + 97;
            // print
            printf("%c", cipherAsciiValue);
        } else if (isalpha(plaintext[i]) && isupper(plaintext[i])) {
            // get alphabetical index of the plaintext's character's ascii value
            plainAlphabeticalIndex = plainAsciiValue - 65;
            // get cipherchar by adding plaintext char AI and key char AI mod 26
            cipherAlphabeticalIndex = (plainAlphabeticalIndex + keyAlphabeticalIndex) % 26;
            // convert alphabetical index of cipherchar to ascii value
            cipherAsciiValue = cipherAlphabeticalIndex + 65;
            // print
            printf("%c", cipherAsciiValue);
            // increment keyIndex
        } else {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    return 0;
}

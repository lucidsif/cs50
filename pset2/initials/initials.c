#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;
    
    do {
        //printf("Hey, what's your full name?\n");
        name = get_string();
    }
    while (!name);
    
    printf("%c", toupper(name[0]));
    
    // loop through each word in the string and add word to array
    
    for (int i = 0, nameLength = strlen(name); i < nameLength; i++) {
        if (name[i] == ' ' && name[i + 1] != '\0') {
            printf("%c", toupper(name[i + 1]));
            i++;
        }
    }
    printf("\n");
    
}
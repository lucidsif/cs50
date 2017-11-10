#include <cs50.h>
#include <stdio.h>

int main(void) {
    
    int minutesInShower;
    
    do {
        printf("Hey there, you dirty human. How many minutes do you spend showering?\n");
        minutesInShower = get_int();
    }
    while (minutesInShower < 0);
    
    int bottlesUsed = minutesInShower * 12;
    
    printf("You must be dirtier than I thought. You use the equivalent of %i when you shower\n", bottlesUsed);
    
}
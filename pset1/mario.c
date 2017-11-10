#include <cs50.h>
#include <stdio.h>
#include <string.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* createHashSeq(int numOfHashes, int height) {
    // newString holder
    char *hashSeq = "";
    // create a for loop that will run until (height - numOfHashes)
    for (int i = 0; i < height - numOfHashes; i++) {
        // add a space to newString per iteration
        hashSeq = concat(hashSeq, " ");
    }
    // create a for loop that will run until (numOfHashes)
    for (int i = 0; i < numOfHashes; i++) {
        // add a hash to newString per iteration
        hashSeq = concat(hashSeq, "#");
    }
    // create two spaces
    hashSeq = concat(hashSeq, "  ");
    //create a for loop that will run until numOfHashes
        for (int i = 0; i < numOfHashes; i++) {
        // add a hash per iteration
        hashSeq = concat(hashSeq, "#");
    }
    
    //printf("%s\n", hashSeq);    
    return hashSeq;
}

int main(void) {
    int height;
    //char *hashPyramid = "";
    
    do {
        printf("What height do you want your double half-pyramid?\n");
        height = get_int();
    }
    while(height < 0 || height > 23);
    
    // create a loop iterating until the height
    for (int i = 0; i < height; i++) {
        // create that rows hash sequence
        char *hashSeq = createHashSeq(i + 1, height);
        printf("%s\n", hashSeq); 
        //hashPyramid = concat(hashPyramid, hashSeq);
    }
    
    
}

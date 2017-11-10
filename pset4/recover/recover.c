
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// open memory card file
// find beginning of JPEG
// open a new JPEG
// write 512 bytes until a new JPEG is found
// dtect end of file

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "you must add a file to process\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[1];
    FILE *output;
    
    // open file
    FILE *input = fopen(infile, "r");
    if (input == NULL)  {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    int count = 0;
    int open = 0;
    uint8_t buffer[512];
    
    // while there is more than 0 512 blocks 
    while (fread(buffer, 512, 1, input) > 0) {
        
        // check for jpeg signature
        if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0
        ) {
            // create an array of characters for the filename
            char filename[8];
            // create a filename based on the count
            sprintf(filename, "%03i.jpg", count);
            
            // if there are no open files, write buffer to jpeg file
            if (open == 0) {
                output = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                open = 1;
            }
            // if there is an open file, close prior open jpeg file and write buffer to new jpeg file
            if (open == 1) {
				fclose(output);
				output = fopen(filename, "w");
				fwrite(buffer, sizeof(buffer), 1, output);
				count++;
            }
        } else { // if buffer does not match jpeg sig and there is an open file, write buffer to opened jpeg file
				    if (open == 1) {
				        fwrite(buffer, sizeof(buffer), 1, output);
				    }
        }
    }
    // close open files
     if (output) {
      fclose(output);
    }
    // close input file
    fclose(input);
    return 0;
    
    // read through each buffer of the file - fread(block, 512, 1, input)
        // if buffer contain jpeg, write to a jpg file - first bytes are 0xff, 0xd8, 0xff 
        // & use bitwise & operator for last byte - (buffer[3] & 0xf0) == 0xe0)
        // create a new jpeg 
            // create filename for new jpeg with sprintf(filename, "%03i,jpg", 2);
            // open file output *img = fopen(filename, "w")
            // write 512 bytes until start of new jpeg - fwrite(input, size, number, output)
        // if less than 512 bytes,
        // use fread to determine number of 512 byte blocks and end search when it hits that num
    // 
}


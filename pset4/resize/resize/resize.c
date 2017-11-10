/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // is n is greater than 100, return
    if (n > 100 || n < 1) {
        printf("n must be less than or equal to 100\n");
        return 2;
    }

    // open inptr file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open outptr file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // write outfile's new BITMAPINFOHEADER
    
    int initialWidth = bi.biWidth;
    
     // update width and height
    bi.biWidth *= n;
    bi.biHeight *= n;
    
        // determine newPadding for scanlines
    int oldPadding =  (4 - (initialWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // newheight * newwidth + newpadding * newheight
    bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + newPadding*abs(bi.biHeight);

    // write outfile's new BITMAPFILEHEADER
    
    // size of image + offbits
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;
    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
     // iterate over infile's scanlines
         
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < initialWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile n times horizontally
            for(int k = 0; k < n; k++)
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over newPadding, if any
        fseek(inptr, oldPadding, SEEK_CUR);
        
        // then add it back (to demonstrate how)
        for (int l = 0; l < newPadding; l++) {
            fputc(0x00, outptr);
        }
        
        // if i % n == 0, go to next row, else repeat last row
        int repeat = initialWidth*sizeof(RGBTRIPLE) + oldPadding;
        if ((i+1) % n != 0) {
            fseek(inptr, -repeat, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

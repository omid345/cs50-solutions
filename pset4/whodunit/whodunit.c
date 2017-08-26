#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[]) {

    //ensure proper usage
    if (argc != 3) {
        fprintf(stderr, "Usage: ./whodunit infile outfile\n");
        return 1;
    }

    //store file names
    char *infileName = argv[1];
    char *outfileName = argv[2];

    //ensure files can be opened
    FILE *inputFile = fopen(infileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Could not open %s", infileName);
        return 2;
    }

    FILE *outputFile = fopen(outfileName, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Could not create %s", outfileName);
        return 3;
    }

    //read the inputFile header
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inputFile);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(inputFile);
        fclose(outputFile);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //write the outputFile header
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight),
        biWidth = abs(bi.biWidth); i < biHeight; i++) {
        // iterate over pixels in scanline
        for (int j = 0; j < biWidth; j++) {
            RGBTRIPLE triple;
            fread(&triple, sizeof(RGBTRIPLE), 1, inputFile);

            // Remove the red noise (from full red, quite red, less red and so on)
            if (triple.rgbtRed == 255)
            {
                triple.rgbtRed = 255;
                triple.rgbtGreen = 255;
                triple.rgbtBlue = 255;
            }
            else if (triple.rgbtRed < 255 && triple.rgbtRed > 230 )
            {
                triple.rgbtRed = 230;
                triple.rgbtGreen = 230;
                triple.rgbtBlue = 230;
            }
            else if (triple.rgbtRed < 230 && triple.rgbtRed > 200 )
            {
                triple.rgbtRed = 200;
                triple.rgbtGreen = 200;
                triple.rgbtBlue = 200;
            }
            else if (triple.rgbtRed < 200 && triple.rgbtRed > 150 )
            {
                triple.rgbtRed = 150;
                triple.rgbtGreen = 150;
                triple.rgbtBlue = 150;
            }
            else if (triple.rgbtRed < 150 && triple.rgbtRed > 100 )
            {
                triple.rgbtRed = 100;
                triple.rgbtGreen = 100;
                triple.rgbtBlue = 100;
            }
            else if (triple.rgbtRed < 100 && triple.rgbtRed > 50 )
            {
                triple.rgbtRed = 50;
                triple.rgbtGreen = 50;
                triple.rgbtBlue = 50;
            }
            else if (triple.rgbtRed < 50 && triple.rgbtRed > 0 )
            {
                triple.rgbtRed = 0;
                triple.rgbtGreen = 0;
                triple.rgbtBlue = 0;
            }

            fwrite(&triple, sizeof(RGBTRIPLE), 1, outputFile);
        }

        // skip over padding, if any
        fseek(inputFile, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++) {
            fputc(0x00, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
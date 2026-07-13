/*
  ------------------------------------------------------------
  ANSI C IMAGE PROCESSING TEMPLATE USING DIP LIBRARY
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dip.h"
#include "dipcopy.h"			

unsigned char **processImage(unsigned char **inputImage, int rows, int columns);
unsigned char **processImagechannel(unsigned char **inputImage, int rows, int columns);
int main(void)
{
     unsigned char *inputFilename = "melanoma269x187.raw",
                   *outputFilename = "out.raw";
     int rows = 269, 
         columns = 187;
         
         
     unsigned char **inputImage, **outputImage;
       
  
     inputImage = allocateImageRGB(rows, columns);     
     inputImage = loadImageRGB(inputFilename, rows, columns);
     //outputImage = processImage(inputImage, rows, columns);
     outputImage = processImagechannel(inputImage, rows, columns);
	 saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **processImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = inputImage[i][j];
         }
     }
     return outputImage;
}


unsigned char **processImagechannel(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     unsigned char r,g,b;
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             r=inputImage[i][j*3];
             b=inputImage[i][3*j+1];
             g=inputImage[i][3*j+2];
             
			 
			 outputImage[i][j] = (r+g+b)/3;
        
             
             
         }
     }
     return outputImage;
}


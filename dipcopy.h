/*
  ------------------------------------------------------------
  DYNAMIC ANSI C IMAGE MANAGEMENT LIBRARY
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

unsigned char **allocateImageRGB(int rows, int columns)
{
      unsigned char **image = (unsigned char **)malloc(rows * sizeof(unsigned char *));
      int i;
      for (i = 0; i < rows; i++)
      {
          image[i] = (unsigned char *)malloc(3*columns * sizeof(unsigned char));
      }
      return image;
}

unsigned char **loadImageRGB(char *filename, int rows, int columns)
{
    FILE *inputFile;
    unsigned char **image = allocateImageRGB(rows, columns); //!!

    int i,j;    
	if ( ((inputFile = fopen(filename,"rb")) != NULL))
	{
		for  (i = 0; i < rows; i++)
		{
			for  (j = 0; j < 3*columns; j++)
			{
				fscanf(inputFile, "%c", &image[i][j]);
			}
		}
	} 
	else
	{
		printf("Error loading image.");
	}
	fclose(inputFile);
	return image;
}



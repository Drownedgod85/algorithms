#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define BLOCKSIZE 512
#define FILE_NAME_SIZE 8
typedef uint8_t BYTE;

int Error()
{
    printf("Usage: ./recover image\n");
    return 1;
}

int fileError(char filename[])
{
    printf("Can't open file: %s\n", filename);
    return 1;
}
int main(int argc, char *argv[])
{
     if(argc !=2 )
     {
         return Error();
     }

     char* inFile = argv[1];
     if(inFile == NULL)
     {
         return Error();
     }

    FILE* inPtr = fopen(inFile, "r");
    if(inPtr == NULL)
    {
        return fileError(inFile);
    }

    char filename[8];
    FILE* outPtr = NULL;
    uint8_t buffer[BLOCKSIZE];
    int jpgCounter=0;

    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, inPtr) || feof(inPtr)==0)
    {
        if (buffer[0] == 0xff
    && buffer[1] == 0xd8
    && buffer[2] == 0xff
    && (buffer[3] & 0xf0) ==  0xe0)
        {
            if(outPtr != NULL)
            {
                fclose(outPtr);
            }
            sprintf(filename, "%03i.jpg", jpgCounter);
            outPtr = fopen(filename, "w");
            jpgCounter++;
        }
        if(outPtr!=NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outPtr);
        }
  }
  if(inPtr == NULL)
  {
      fclose(inPtr);
      {
          if(outPtr == NULL)
      fclose(outPtr);
  }
    }
    return 0;
}
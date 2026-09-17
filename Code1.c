#include <stdio.h>
#include <stdlib.h>

FILE *DOOR(char *type, char*mode)
{
    char filename[50];
    FILE *fp;

    printf("Enter %s filename: ", type);
    scanf("%s", filename);

    fp= fopen(filename, mode);

    if (fp == NULL)
    {
        exit(0);
    }
    return fp;
}

int main()
{
    FILE *putted= DOOR("input", "r+");

    char name;
    int IS; 
    int IE; 
    int MS; 
    int ME; 
    int OS; 
    int OE; 


    fscanf(putted, " %d", &OS);
    fscanf(putted, " %d", &OE);
    
    
    fscanf(putted, " %d", &MS);
    fscanf(putted, " %d", &ME);

    
    fscanf(putted, " %d", &IS);
    fscanf(putted, " %d", &IE);

    fclose(putted);

    printf("Print out a character: ");
    scanf(" %c", &name);

    putted= DOOR("output", "w+");

    for ( int i= OS; i< OE; i++)
    {
        for ( int j= MS; j< ME; j++)
        {
            for ( int k= IS; k< IE; k++)
            {
                fprintf(putted, "%c", name); 
            }
            fprintf(putted, "\n");
        }
        fprintf(putted, "\n");
    }

    printf("%d Blocks \n", OE - OS);
    printf("%d lines per block\n", ME - MS);
    printf("%d Characters per line\n", IE - IS);

    fclose(putted);
}

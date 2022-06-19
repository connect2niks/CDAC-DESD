#include <stdlib.h>
#include <stdio.h>

#define size 1000

int main(int argc, char const *argv[])
{
    char buf[size];
    FILE *fr,*fw;
    if (argc > 3)
    {
        printf("More then two files are not allowed\n");
        exit(EXIT_FAILURE);
    }
    fr = fopen(argv[1],"r");

    if (fr==NULL)
    {
        perror("Error in opening source file and error is :");
        exit(EXIT_FAILURE);
    }

    fw=fopen(argv[2],"w+");

    if (fw==NULL)
    {
        perror("Error in opening destination file and error is :");
        exit(EXIT_FAILURE);
    }

    while (fread(&buf,size,sizeof(char),fr)!=0)
    {
        fwrite(&buf,size,sizeof(char),fw);  
      }

    fclose(fr);
    fclose(fw);
    return 0;
}

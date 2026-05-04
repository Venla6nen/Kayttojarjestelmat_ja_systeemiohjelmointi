#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
        //Variables for reading lines
        char *pLine =NULL;
        //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        ssize_t read;
        //No file in the command line
        if (argc < 2){
            exit(0);
        }
        FILE *inputfile;
        //For loop for reading all the files in the command line
        for(int i =1; i< argc; i++){
            inputfile =fopen(argv[i], "r"); 
            //Exit if fopen() fails
            if(inputfile ==NULL){
            fprintf(stderr, "my-cat: cannot open file\n");
                exit(1);
            }
            //Reading the lines and printing to the standard output
            while ((read = getline(&pLine, &lineSize, inputfile)) != -1){
                fputs(pLine, stdout);
            }
            fclose(inputfile);
        }
        free(pLine);
        return(0);
    }


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
        
        //No command line arguments
        if (argc < 2){
            fprintf(stderr, "my-grep: searchterm [file ...]\n");
            exit(1);
        }

        //The search term
        char *term = argv[1];
        //Command line has only search term and no files, 
        //then program reads standard input
        //and prints the line if search term matches
        if (argc ==2){
            while ((read = getline(&pLine, &lineSize, stdin)) != -1){
                //source:https://youtu.be/ql1SFKTLLMI
                if(strstr(pLine, term)){
                fputs(pLine, stdout);
            }
        }
        free(pLine);
        return(0);
    }

        FILE *inputfile;
        //Reading all the files in the command line
        for(int i =2; i< argc; i++){
        inputfile =fopen(argv[i], "r"); 
        
        //Exit if fopen() fails
        if(inputfile ==NULL){
        fprintf(stderr, "my-grep: cannot open file\n");
            exit(1);
        }
        //Reading the lines and printing to the standard output if search term matches
        while ((read = getline(&pLine, &lineSize, inputfile)) != -1){
            //source:https://youtu.be/ql1SFKTLLMI
            if(strstr(pLine, term)){
                fputs(pLine, stdout);
            }   
        }
        fclose(inputfile);
    } 
        free(pLine);
        return(0);
    }


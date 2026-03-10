#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
char *compress(char *str) {
    char *start = str;
    char *c_first = str;
    char *c_last = str;
    char *c_write = str;
    int run_len = 0;
    while (*str) {
        ++c_last;
        ++run_len;
        if (!(*c_last) || *c_last != *c_first || run_len == 9) { 
            // end of run
            *(c_write++) = *c_first;
            if (run_len > 1)
                *(c_write++) = '0' + run_len;
            // start next run
            run_len = 0; 
            c_first = c_last;
        }
        ++str;
    }
    *c_write = 0;
    return start;
}


int main(int argc, char *argv[]){

        //source for pointers:https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
        char *pLine =NULL;
       

        //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        ssize_t read;

        //no file in the command line
        if (argc < 2){
            exit(0);
        }
        FILE *inputfile;

        
        for(int i =1; i< argc; i++){
            inputfile =fopen(argv[i], "r"); 
            
            //fopen() fails
            if(inputfile ==NULL){
            fprintf(stderr, "my-cat: cannot open file\n");
                exit(1);
            }
            while ((read = getline(&pLine, &lineSize, inputfile)) != -1){
                fputs(pLine, stdout);

            }
            
            fclose(inputfile);
        }
        free(pLine);
        return(0);
    }


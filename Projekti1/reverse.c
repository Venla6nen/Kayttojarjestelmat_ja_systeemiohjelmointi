#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   
   
    if (argc == 1) {
        return(0);
    }
    if (argc ==2) {

        //source for pointers:https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
        char *pLine =NULL;
        char **pReverseLines = NULL;
        //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        __ssize_t read;

        int count =0;
        int newMemorySize =0;
        char **ptrNewMemorySize =NULL;

        FILE *inputfile;
        inputfile =fopen(argv[1], "r"); 

        if(inputfile ==NULL){
            exit(1);
        }

        while ((read = getline(&pLine, &lineSize, inputfile)) != -1)
        
        {
            char *plineCopy =malloc(read +1);
            if (plineCopy == NULL) {
                exit(1);
            }
            strcpy(plineCopy, pLine);

            //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
            if (count >= newMemorySize) {
               ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
                if(ptrNewMemorySize == NULL) {
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }
            pReverseLines[count] = plineCopy;
            count++;    
            }

            for(int i = count -1; i >= 0; i--){
                printf("%s", pReverseLines[i]);
                free(pReverseLines[i]);
            }
            free(pReverseLines);
            free(pLine);
            fclose(inputfile);
            return(0);
        }
    if (argc ==3){
        
        //source for pointers:https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
        char *pLine =NULL;
        char **pReverseLines = NULL;
        //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        __ssize_t read;

        int count =0;
        int newMemorySize =0;
        char **ptrNewMemorySize =NULL;

        FILE *inputfile;
        inputfile =fopen(argv[1], "r"); 

        FILE *outputfile;
        outputfile =fopen(argv[2], "w");

        if(inputfile ==NULL){
            exit(1);
        }

       

        while ((read = getline(&pLine, &lineSize, inputfile)) != -1)
        
        {
            char *plineCopy =malloc(read +1);
            if (plineCopy == NULL) {
                exit(1);
            }
            strcpy(plineCopy, pLine);

            //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
            if (count >= newMemorySize) {
               ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
                if(ptrNewMemorySize == NULL) {
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }
            pReverseLines[count] = plineCopy;
            count++;    
            }

            for(int i = count -1; i >= 0; i--){

                fprintf(outputfile, "%s", pReverseLines[i]);
                free(pReverseLines[i]);
            }
            free(pReverseLines);
            free(pLine);
            fclose(inputfile);
            fclose(outputfile);
            return(0);
        }
    else{
        return(0);
    }

}



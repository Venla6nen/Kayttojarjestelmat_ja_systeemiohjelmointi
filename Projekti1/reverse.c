#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
   
   
    if (argc == 1) {
       //source for pointers:https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
        char *pLine =NULL;
        char **pReverseLines = NULL;
       //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        ssize_t read;

        int count =0;
        int newMemorySize =0;
        char **ptrNewMemorySize =NULL;

        while ((read = getline(&pLine, &lineSize, stdin)) != -1)
        
        {
            char *plineCopy =malloc(read +1);
            if (plineCopy == NULL) {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            strcpy(plineCopy, pLine);
            //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
            if (count >= newMemorySize) {
               ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
                if(ptrNewMemorySize == NULL) {
                    fprintf(stderr, "realloc failed\n");
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }
            pReverseLines[count] = plineCopy;
            count++;    
            }

            for(int i = count -1; i >= 0; i--){
                /*printf("%s", pReverseLines[i]);*/
                //source:https://man7.org/linux/man-pages/man3/fputs.3p.html
                fputs(pReverseLines[i], stdout);

                int lineLenght = strlen(pReverseLines[i]);
                if (lineLenght == 0 || pReverseLines[i][lineLenght - 1] != '\n') {
                    //source:https://www.wscubetech.com/resources/c-programming/putchar
                    putchar('\n');
                }
                
                free(pReverseLines[i]);
            }
            free(pReverseLines);
            free(pLine);
            return(0);
        
        }
    
    
    if (argc ==2) {

        //source for pointers:https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
        char *pLine =NULL;
        char **pReverseLines = NULL;
        //source for getline():https://man7.org/linux/man-pages/man3/getline.3.html
        size_t lineSize = 0;
        ssize_t read;

        int count =0;
        int newMemorySize =0;
        char **ptrNewMemorySize =NULL;

        FILE *inputfile;
        inputfile =fopen(argv[1], "r"); 

        if(inputfile ==NULL){
           fprintf(stderr, "error: cannot open file 'input.txt'\n");
            exit(1);
        }

        while ((read = getline(&pLine, &lineSize, inputfile)) != -1)
        
        {
            char *plineCopy =malloc(read +1);
            if (plineCopy == NULL) {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            strcpy(plineCopy, pLine);

            //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
            if (count >= newMemorySize) {
               ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
                if(ptrNewMemorySize == NULL) {
                    fprintf(stderr, "realloc failed\n");
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }
            pReverseLines[count] = plineCopy;
            count++;    
            }

            for(int i = count -1; i >= 0; i--){
                /*printf("%s", pReverseLines[i]);*/
                //source:https://man7.org/linux/man-pages/man3/fputs.3p.html
                fputs(pReverseLines[i], stdout);

                int lineLenght = strlen(pReverseLines[i]);
                if (lineLenght == 0 || pReverseLines[i][lineLenght - 1] != '\n') {
                    //source:https://www.wscubetech.com/resources/c-programming/putchar
                    putchar('\n');
                }
                
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
            fprintf(stderr, "error: cannot open file 'input.txt'\n");
            exit(1);
        }
        if(outputfile ==NULL){
            fprintf(stderr, "error: cannot open file 'output.txt'\n");
            exit(1);
        }

        //if file ond iput are same:
        if(inputfile==outputfile){
            fprintf(stderr,"Input and output file must differ\n");
            exit(1);
        }


       

        while ((read = getline(&pLine, &lineSize, inputfile)) != -1)
        
        {
            char *plineCopy =malloc(read +1);
            
            
            if (plineCopy == NULL) {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            strcpy(plineCopy, pLine);

            //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
            if (count >= newMemorySize) {
               ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
                if(ptrNewMemorySize == NULL) {
                    fprintf(stderr, "realloc failed\n");
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }
            pReverseLines[count] = plineCopy;
            count++;    
            }

            
            for(int i = count -1; i >= 0; i--){
                //source:https://man7.org/linux/man-pages/man3/fputs.3p.html
                fputs(pReverseLines[i], outputfile);
                int lineLenght = strlen(pReverseLines[i]);
                if (lineLenght == 0 || pReverseLines[i][lineLenght - 1] != '\n') {
                    //source:https://www.wscubetech.com/resources/c-programming/putchar
                    fprintf(outputfile, "\n");
                }
                //fprintf(outputfile, "%s", pReverseLines[i]);
                free(pReverseLines[i]);
            }
            free(pReverseLines);
            free(pLine);
            fclose(inputfile);
            fclose(outputfile);
            return(0);
        }
    else{
        fprintf(stderr, "usage: reverse <input> <output>\n");
        return(1);
    }

}



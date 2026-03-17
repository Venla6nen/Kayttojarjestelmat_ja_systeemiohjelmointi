#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
   //If prompt is ./reverse (argc == 1)
   //The program reads input from standard input (stdin)
   //and prints the reversed text to standard output (stdout).
    if (argc == 1) {
       
        //Variables for reading lines and storing them in memory.
        char *pLine =NULL;
        char **pReverseLines = NULL;

        size_t lineSize = 0;
        ssize_t read;

        int count =0;
        int newMemorySize =0;
        char **ptrNewMemorySize =NULL;

    
        //source for getline(): https://man7.org/linux/man-pages/man3/getline.3.html
        //Read standard input line by line.
        while ((read = getline(&pLine, &lineSize, stdin)) != -1){
            
            //Source for malloc():https://man7.org/linux/man-pages/man3/free.3.html
            //Allocate memory for the current line (+1 for '\0' )
            char *plineCopy =malloc(read +1);
            //Error handling if malloc fails.
            if (plineCopy == NULL) {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            //source for strcpy(): https://man7.org/linux/man-pages/man3/strcpy.3.html
            //Copy the current line into allocated memory.
            strcpy(plineCopy, pLine);
            
            //Increase the array size if a new line needs more space.
            if (count >= newMemorySize) {
               //source for realloc():https://www.programiz.com/c-programming/c-dynamic-memory-allocation
                ptrNewMemorySize = realloc(pReverseLines, (newMemorySize + 1) * sizeof(char*));
               //Error handling if realloc fails.
               if(ptrNewMemorySize == NULL) {
                    fprintf(stderr, "realloc failed\n");
                    exit(1);
                }
                pReverseLines = ptrNewMemorySize;
                newMemorySize++;
            }

            //Store the copied line in the array
            pReverseLines[count] = plineCopy;
            count++;    
            }

            //Print the lines in reverse order.
            for(int i = count -1; i >= 0; i--){
                //source for fputs():https://man7.org/linux/man-pages/man3/fputs.3p.html
                fputs(pReverseLines[i], stdout);
                //If line does not end with '\n', add a newline
                int lineLenght = strlen(pReverseLines[i]);
                if (lineLenght == 0 || pReverseLines[i][lineLenght - 1] != '\n') {
                    //source for putchar():https://www.wscubetech.com/resources/c-programming/putchar
                    putchar('\n');
                }
            
            //Free the memory
                free(pReverseLines[i]);
            }
            free(pReverseLines);
            free(pLine);
            return(0);
        }
    
    
    //If prompt is ./reverse input.txt (argc == 2)
    //The program reads input from the given file (argv[1])
    //and writes the reversed text to standard output (stdout).
    if (argc ==2) {

       
        char *pLine =NULL;
        char **pReverseLines = NULL;
     
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



    //If prompt is ./reverse input.txt output.txt (argc == 3)
   //The program reads input from the given input file (argv[1])
   //and writes the reversed text to given output file(argv[2]).
    if (argc ==3){

        
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



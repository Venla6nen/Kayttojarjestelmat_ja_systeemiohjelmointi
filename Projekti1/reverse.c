#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   
   
    if (argc == 1) {
        return(0);
    }
    if (argc ==2) {
        char* pMemory = NULL;
        int memorySize = 256;
        
        int count =0;

        FILE *inputfile;
        inputfile =fopen(argv[1], "r");  

        if(inputfile ==NULL){
            perror("Tiedoston avaaminen epäonnistui"); 
            exit(1);
        }
        
        pMemory = (char*)malloc(memorySize);

        if ((pMemory = (char *)malloc(memorySize)) == NULL)
            {perror("Muistinvaraus epäonnistui"); 
            exit(1); 
        }
        while(fgets(pMemory, memorySize, inputfile) != NULL){
            
        

            printf("%s", pMemory);
        }
      

        free(pMemory);
        fclose(inputfile);
        return(0);  

    }
    
    if (argc ==3){
        return(0);
    }
    else{
        return(0);
    }
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //Check the arguments
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    int current_char = -1; 
    int next_char;

    //Read through the files given by the user
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-zip: cannot open file\n");
            exit(1);
        }

        //Reading the files through character by character
        while ((next_char = fgetc(fp)) != EOF) {
            if (current_char == -1) {
                current_char = next_char;
                count = 1;
            } else if (next_char == current_char) {
                count++; //If the same character occurs, raise count by 1. source: https://dev.to/farhadrahimiklie/building-a-file-compressor-in-c-from-scratch-2n25
            } else {
                
                fwrite(&count, sizeof(int), 1, stdout); //If the character changes, write the previous set out
                char c = (char)current_char;
                fwrite(&c, sizeof(char), 1, stdout);
                
                current_char = next_char; //Reset for the next character
                count = 1;
            }
        }
        fclose(fp);
    }
    //write the last set out once all the files have been read
    if (current_char != -1) {
        fwrite(&count, sizeof(int), 1, stdout);
        char c = (char)current_char;
        fwrite(&c, sizeof(char), 1, stdout);
    }

    return 0;
}

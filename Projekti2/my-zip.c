#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    int current_char = -1; 
    int next_char;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-zip: cannot open file\n");
            exit(1);
        }

        while ((next_char = fgetc(fp)) != EOF) {
            if (current_char == -1) {
                
                current_char = next_char;
                count = 1;
            } else if (next_char == current_char) {
                
                count++;
            } else {
                
                fwrite(&count, sizeof(int), 1, stdout);
                char c = (char)current_char;
                fwrite(&c, sizeof(char), 1, stdout);
                
                
                current_char = next_char;
                count = 1;
            }
        }
        fclose(fp);
    }

    if (current_char != -1) {
        fwrite(&count, sizeof(int), 1, stdout);
        char c = (char)current_char;
        fwrite(&c, sizeof(char), 1, stdout);
    }

    return 0;
}
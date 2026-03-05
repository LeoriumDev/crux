#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "lexer.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./crux --lex <file>\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "--lex")) {
        fprintf(stderr, "Invalid options.\nUsage: %s --lex <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fptr = fopen(argv[2], "r");
    if (!fptr) {
        fprintf(stderr, "Error: Could not open file.\n");
        return EXIT_FAILURE;
    }

    size_t file_size;
    fseek(fptr, 0, SEEK_END);
    file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char* file_contents = malloc(file_size + 1);
    if (!file_contents) {
        fprintf(stderr, "Error: malloc failed.\n");
        return EXIT_FAILURE;
    }

    fread(file_contents, 1, file_size, fptr);
    file_contents[file_size] = '\0';

    crux_lexer(file_contents);

    free(file_contents);
    fclose(fptr);

    return EXIT_SUCCESS;
}
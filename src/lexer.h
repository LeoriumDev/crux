#pragma once
#include <stdint.h>

typedef enum {
    INT_KEYWORD,
    IDENTIFIER,
    OPEN_PARENTHESIS,
    VOID_KEYWORD,
    CLOSE_PARENTHESIS,
    OPEN_BRACE,
    RETURN_KEYWORD,
    CONSTANT,
    SEMICOLON,
    CLOSE_BRACE
} CRUX_TOKEN_TYPE;

typedef struct {
    CRUX_TOKEN_TYPE token_type;
    const char* id;
    int64_t int_val;
} CRUX_TOKEN;

CRUX_TOKEN crux_lexer(const char* str);

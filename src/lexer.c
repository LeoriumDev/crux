#include "lexer.h"

CRUX_TOKEN crux_lexer(const char* str) {
    return (CRUX_TOKEN) { .token_type = INT_KEYWORD, .int_val = 1 };
}

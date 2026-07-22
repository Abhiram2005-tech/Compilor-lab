/* lex program to count number of digits */

%{
#include <stdio.h>
int digit_count = 0;
%}

/* Rules Section */
%%
[0-9]          { digit_count++; }  /* Matches any single digit */
"\n"           { printf("Digit count: %d\n", digit_count); digit_count = 0; }
.              ;                   /* Ignore letters, spaces, and punctuation */
%%

int yywrap(void) {
    return 1;
}

int main(void) {  
    yylex();
    return 0;
}

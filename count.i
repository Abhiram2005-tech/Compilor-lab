/* lex program to count number of words */

%{
#include <stdio.h>
#include <string.h>
int word_count = 0;
%}

/* Rules Section */
%%
[a-zA-Z0-9]+   { word_count++; }  /* Matches words (1 or more alphanumeric characters) */
"\n"           { printf("Word count: %d\n", word_count); word_count = 0; }
.              ;                  /* Ignore spaces, punctuation, and other characters */
%%

int yywrap(void) {
    return 1; /* Return 1 to signal end of input stream */
}

int main(void) {  
    yylex();
    return 0;
}

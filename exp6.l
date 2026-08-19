%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+      {
                yylval = atoi(yytext);
                return NUMBER;
            }

[ \t]+      ; /* Ignore whitespace */

\n          { return 0; } /* End of line terminates parsing */

.           { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}

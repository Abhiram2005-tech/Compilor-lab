%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

/* Entry point to print the result upon evaluation */
S : E   { 
            printf("Result: %d\n", $1); 
        }
  ;

E : E '+' E
        {
            $$ = $1 + $3;
        }

  | E '-' E
        {
            $$ = $1 - $3;
        }

  | E '*' E
        {
            $$ = $1 * $3;
        }

  | E '/' E
        {
            if ($3 == 0)
            {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            $$ = $1 / $3;
        }

  | '(' E ')'
        {
            $$ = $2;
        }

  | '-' E %prec UMINUS
        {
            $$ = -$2;
        }

  | NUMBER
        {
            $$ = $1;
        }
  ;

%%

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid Expression\n");
    return 0;
}

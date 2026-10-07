#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Return operator precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Convert clean Infix string to Postfix notation (Shunting-Yard Algorithm)
void infixToPostfix(const char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1) top--; // Pop '('
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

// Generate Three-Address Code from Postfix string
void generateTAC(const char* postfix, const char* targetVar) {
    char stack[MAX][MAX];
    int top = -1;
    int tempCount = 1;

    printf("\nThe intermediate code:\n");

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            strcpy(stack[++top], operand);
        } else {
            char op2[MAX], op1[MAX], temp[MAX];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(temp, "t%d", tempCount++);
            printf("%s := %s %c %s\n", temp, op1, ch, op2);

            strcpy(stack[++top], temp);
        }
    }

    // Assign final expression result to the target variable
    if (targetVar[0] != '\0') {
        printf("%s := %s\n", targetVar, stack[top]);
    }
}

int main(void) {
    char expr[MAX];
    char infix[MAX] = "";
    char targetVar[MAX] = "";
    char postfix[MAX];

    printf("INTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    if (scanf("%99s", expr) != 1) {
        return 1;
    }

    // Separate target variable (LHS) and infix expression (RHS)
    char* equalsPos = strchr(expr, '=');
    if (equalsPos != NULL) {
        int targetLen = equalsPos - expr;
        strncpy(targetVar, expr, targetLen);
        targetVar[targetLen] = '\0';

        int j = 0;
        for (int i = 0; targetVar[i]; i++) {
            if (!isspace(targetVar[i])) targetVar[j++] = targetVar[i];
        }
        targetVar[j] = '\0';

        strcpy(infix, equalsPos + 1);
    } else {
        strcpy(infix, expr);
    }

    // Strip whitespaces
    char cleanInfix[MAX];
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (!isspace(infix[i])) cleanInfix[k++] = infix[i];
    }
    cleanInfix[k] = '\0';

    infixToPostfix(cleanInfix, postfix);
    generateTAC(postfix, targetVar);

    return 0;
}

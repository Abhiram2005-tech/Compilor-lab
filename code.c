#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

struct Quadruple {
    char op[10];
    char arg1[10];
    char arg2[10];
    char res[10];
};

int main(void) {
    struct Quadruple code[MAX];
    int n = 0;

    printf("TARGET CODE GENERATION FROM QUADRUPLES\n\n");
    printf("Enter Intermediate Code Quadruples (op arg1 arg2 res):\n");
    printf("(Type 'exit' or press Ctrl+D/Ctrl+Z to finish)\n\n");

    // Read quadruples line by line until EOF or 'exit'
    while (n < MAX) {
        if (scanf("%s", code[n].op) != 1) break;
        if (strcmp(code[n].op, "exit") == 0) break;

        if (scanf("%s %s %s", code[n].arg1, code[n].arg2, code[n].res) != 3) {
            break;
        }
        n++;
    }

    printf("\nGenerated Target Assembly Code:\n");
    printf("-------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (strcmp(code[i].op, "+") == 0) {
            printf("MOV R0, %s\n", code[i].arg1);
            printf("ADD R0, %s\n", code[i].arg2);
            printf("MOV %s, R0\n", code[i].res);
        } else if (strcmp(code[i].op, "-") == 0) {
            printf("MOV R0, %s\n", code[i].arg1);
            printf("SUB R0, %s\n", code[i].arg2);
            printf("MOV %s, R0\n", code[i].res);
        } else if (strcmp(code[i].op, "*") == 0) {
            printf("MOV R0, %s\n", code[i].arg1);
            printf("MUL R0, %s\n", code[i].arg2);
            printf("MOV %s, R0\n", code[i].res);
        } else if (strcmp(code[i].op, "/") == 0) {
            printf("MOV R0, %s\n", code[i].arg1);
            printf("DIV R0, %s\n", code[i].arg2);
            printf("MOV %s, R0\n", code[i].res);
        } else if (strcmp(code[i].op, "=") == 0) {
            printf("MOV R0, %s\n", code[i].arg1);
            printf("MOV %s, R0\n", code[i].res);
        } else {
            printf("; Unknown operator: %s\n", code[i].op);
        }
    }

    return 0;
}

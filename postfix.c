// postfix.c

#include "postfix.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to convert postfix to infix
void postfixToInfix(const char *postfix, char *infix) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol[2];
        symbol[0] = postfix[i];
        symbol[1] = '\0';

        if (isalnum(postfix[i])) {
            push(&stack, symbol);
        } else {
            char operand2[MAX_STACK_SIZE], operand1[MAX_STACK_SIZE];
            pop(&stack, operand2);
            pop(&stack, operand1);

            // Construct the intermediate infix expression
            char intermediate[MAX_STACK_SIZE];
            snprintf(intermediate, sizeof(intermediate), "(%s %c %s)", operand1, postfix[i], operand2);
            push(&stack, intermediate);
        }
    }

    pop(&stack, infix);
}

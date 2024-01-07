#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "MathCalc.h"


// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to push a value onto the stack
void push(Stack *stack, int value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

// Function to pop a value from the stack
int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0;  // Stack underflow
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;  // Default for non-operators
}

// Function to evaluate a mathematical expression
int evaluateExpression(const char *expression) {
    Stack operatorStack;
    Stack operandStack;
    initializeStack(&operatorStack);
    initializeStack(&operandStack);

    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            // Parse multi-digit numbers
            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;  // Move back one position after the last digit

            push(&operandStack, num);
        } else if (isOperator(currentChar)) {
            while (operatorStack.top >= 0 &&
                   getPrecedence(operatorStack.data[operatorStack.top]) >= getPrecedence(currentChar)) {
                char operator = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);

                // Perform the operation and push the result back to the operand stack
                switch (operator) {
                    case '+':
                        push(&operandStack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operandStack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operandStack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operandStack, operand1 / operand2);
                        break;
                }
            }
            // Push the current operator onto the operator stack
            push(&operatorStack, currentChar);
        }
    }

    // Process any remaining operators in the stack
    while (operatorStack.top >= 0) {
        char operator = pop(&operatorStack);
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);

        // Perform the operation and push the result back to the operand stack
        switch (operator) {
            case '+':
                push(&operandStack, operand1 + operand2);
                break;
            case '-':
                push(&operandStack, operand1 - operand2);
                break;
            case '*':
                push(&operandStack, operand1 * operand2);
                break;
            case '/':
                push(&operandStack, operand1 / operand2);
                break;
        }
    }

    // The final result is at the top of the operand stack
    return pop(&operandStack);
}

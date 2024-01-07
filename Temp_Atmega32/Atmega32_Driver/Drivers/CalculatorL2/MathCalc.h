/*
 * MathCalc.h
 *
 *  Created on: Jan 5, 2024
 *      Author: abo32
 */

#ifndef DRIVERS_CALCULATORL2_MATHCALC_H_
#define DRIVERS_CALCULATORL2_MATHCALC_H_

// Define stack structure
#define STACK_SIZE 40

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

// Function prototypes
void initializeStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isOperator(char ch);
int getPrecedence(char ch);
int evaluateExpression(const char *expression);


#endif /* DRIVERS_CALCULATORL2_MATHCALC_H_ */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_EXPR 256

typedef struct {
    double items[MAX_STACK];
    int top;
} Stack;

/* Initialize stack*/
void initStack(Stack *s);

/* Push to stack*/
void push(Stack *s, double value);

/* Pop from stack*/
double pop(Stack *s);

/* Check if character is operator*/
int isOperator(char c);

/* Get operator precedence*/
int precedence(char op);

/* Apply operator*/
double applyOp(double a, double b, char op);

/* Convert infix to postfix notation*/
void infixToPostfix(char *infix, char *postfix);

/* Evaluate postfix expression*/
double evaluatePostfix(char *postfix, double x_value);

/*Compilation of all prior functions*/
double evaluate(double x, char* expression);

/*Function for Simpson's Integration*/
double simpsons_integration(double a, double b, int n, char* expression);

#endif

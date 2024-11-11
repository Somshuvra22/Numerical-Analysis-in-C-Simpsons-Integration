#include "functions.h"

/* Initialize stack*/
void initStack(Stack *s) {
    s->top = -1;
}

/* Push to stack*/
void push(Stack *s, double value) {
    if(s->top < MAX_STACK - 1) {
        s->items[++(s->top)] = value;
    }
}

/* Pop from stack*/
double pop(Stack *s) {
    if(s->top >= 0) {
        return s->items[(s->top)--];
    }
    return 0;
}

/* Check if character is operator*/
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

/* Get operator precedence*/
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

/* Apply operator*/
double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        case '^': return pow(a, b);
    }
    return 0;
}

/* Convert infix to postfix notation*/
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX_STACK];
    int top = -1;
    int j = 0;

    for(int i = 0; infix[i]; i++) {
        char c = infix[i];

        if(c == ' ') continue;

        if(c == 'x' || c == 'X') {
            postfix[j++] = 'x';
            postfix[j++] = ' ';
        }
        else if(isdigit(c) || c == '.') {
            while(isdigit(infix[i]) || infix[i] == '.') {
                postfix[j++] = infix[i++];
            }
            i--;
            postfix[j++] = ' ';
        }
        else if(c == '(') {
            stack[++top] = c;
        }
        else if(c == ')') {
            while(top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if(top >= 0) top--;
        }
        else if(isOperator(c)) {
            while(top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = c;
        }
    }

    while(top >= 0) {
        if(stack[top] != '(') {
            postfix[j++] = stack[top];
            postfix[j++] = ' ';
        }
        top--;
    }

    postfix[j] = '\0';
}

/* Evaluate postfix expression*/
double evaluatePostfix(char *postfix, double x_value) {
    Stack stack;
    initStack(&stack);
    double a, b;
    char *token = strtok(postfix, " ");

    while(token != NULL) {
        if(token[0] == 'x' || token[0] == 'X') {
            push(&stack, x_value);
        }
        else if(isdigit(token[0])) {
            push(&stack, atof(token));
        }
        else if(isOperator(token[0])) {
            b = pop(&stack);
            a = pop(&stack);
            push(&stack, applyOp(a, b, token[0]));
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

double evaluate(double x, char* expression) {
    char postfix[MAX_EXPR * 2] = {0};
    infixToPostfix(expression, postfix);
    return evaluatePostfix(postfix, x);
}

double simpsons_integration(double a, double b, int n, char* expression){
    int i;
    double x, h, sum;
    if(n % 2 != 0) n++; /* Ensure n is even*/

    h = (b - a) / n;
    sum = evaluate(a, expression) + evaluate(b, expression);

    /* Sum for odd indices*/
    for(i = 1; i < n; i += 2) {
        x = a + i * h;
        sum += 4 * evaluate(x, expression);
    }

    /* Sum for even indices*/
    for(i = 2; i < n; i += 2) {
        x = a + i * h;
        sum += 2 * evaluate(x, expression);
    }

    return (h / 3.0) * sum;
}

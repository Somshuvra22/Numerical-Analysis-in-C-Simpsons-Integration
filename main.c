#include "functions.h"

int main() {
    FILE *file;
    char expression[MAX_EXPR];
    double a, b;
    int n;
    double result;

    /* Open the input file*/
    file = fopen("functions.txt", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    /* Read the function expression from file*/
    fgets(expression, sizeof(expression), file);
    expression[strcspn(expression, "\n")] = 0;
    fclose(file);

    printf("Function read from file: %s\n", expression);

    /* Get integration limits and number of intervals*/
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter number of intervals (n): ");
    scanf("%d", &n);
    /* Ensure n is positive and even for Simpson's Rule */
    if (n <= 0) {
        printf("Number of intervals (n) must be positive.\n");
        return 1;
    }

    /* Calculate the integral*/
    result = simpsons_integration(a, b, n, expression);

    printf("\nThe definite integral from %.2f to %.2f is: %.6f\n", a, b, result);

    return 0;
}

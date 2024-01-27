#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

float calculate(float num1, float num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 != 0)
                return num1 / num2;
            else {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
        case '^':
            return pow(num1, num2);
        default:
            printf("Error: Invalid operator!\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    
    printf("Enter an arithmetic expression: ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    
    float result;
    char *token = strtok(expression, " ");
    
    if(token == NULL) {
        printf("Error: No expression entered!\n");
        return EXIT_FAILURE;
    }
    
    result = atof(token);
    
    token = strtok(NULL, " ");
    
    while(token != NULL) {
        if(isOperator(*token)) {
            char op = *token;
            token = strtok(NULL, " ");
            if(token == NULL) {
                printf("Error: Incomplete expression!\n");
                return EXIT_FAILURE;
            }
            float num = atof(token);
            result = calculate(result, num, op);
        } else {
            printf("Error: Invalid operator or number!\n");
            return EXIT_FAILURE;
        }
        token = strtok(NULL, " ");
    }
    
    printf("Result: %.2f\n", result);
    
    return 0;
}

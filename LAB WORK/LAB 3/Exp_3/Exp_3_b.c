//Write	a	program	that	uses	Stack	operations	to	
//  evaluating	the	postfix	expression. 

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Stack for integers
int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char expr[]) {
    int i = 0;

    while (expr[i] != '\0') {

        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If operand (multi-digit number)
        if (isdigit(expr[i])) {
            int num = 0;

            // Extract full number
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            push(num);
        }

        // Operator encountered
        else {
            int val2 = pop();
            int val1 = pop();

            switch (expr[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", expr[i]);
                    exit(1);
            }
            i++;
        }
    }

    return pop();  // Final result
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (use spaces between numbers):\n");
    fgets(postfix, MAX, stdin);

    int result = evaluatePostfix(postfix);

    printf("\nResult = %d\n", result);

    return 0;
}

//Write	a	program	that	uses	Stack	operations	to
// Converting	infix	expression	into	postfix	expression	
 
 
 #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push operation
void push(char x) {
    stack[++top] = x;
}

// Pop operation
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to define precedence
int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

// Main conversion function
void infixToPostfix(char infix[]) {
    char postfix[MAX] = "";
    int pIndex = 0; // index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {

        // If operand (letter or digit)
        if (isalnum(infix[i])) {
            postfix[pIndex++] = infix[i];
            postfix[pIndex++] = ' ';
        }

        // If '(' push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')', pop until '('
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[pIndex++] = pop();
                postfix[pIndex++] = ' ';
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[pIndex++] = pop();
                postfix[pIndex++] = ' ';
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[pIndex++] = pop();
        postfix[pIndex++] = ' ';
    }

    postfix[pIndex] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline if present
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix);

    return 0;
}

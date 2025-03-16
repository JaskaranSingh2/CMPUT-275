#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic stack implementation
typedef struct {
    int *data; // Array storing stack values
    int top;  // Index of the top element
    int max_alloc; // Current allocated size of the stack
} Stack;

void initStack(Stack *stack) {
    stack->max_alloc = 4; // Initial size, that we can grow later
    stack->top = -1; // Initialize top to -1 to indicate empty stack
    stack->data = malloc(stack->max_alloc * sizeof(int)); // Allocate memory for 4 elements
}

// Function to process input and handle escape sequences (like "\t" and "\n")
// Basically, this function makes sure that if the input contains "\t", it's converted to an actual tab character.
// But, the sample code doesn't address this case so I don't know if I'm doing too much.

void processInput(char *input) {
    char *src = input;
    char *dst = input;

    while (*src) {
        if (*src == '\\' && (*(src + 1) == 't' || *(src + 1) == 'n')) {
            if (*(src + 1) == 't') *dst++ = '\t';
            else if (*(src + 1) == 'n') *dst++ = '\n';
            src += 2; // Move past the escape sequence
        } else {
            *dst++ = *src++; // Just copy the character normally
        }
    }
    *dst = '\0'; // Null-terminate the string
}

// Push a value onto the stack (add to the top)
void push(Stack *stack, int value) {
    // If the stack is full, allocate more memory (double the size)
    if (stack->top >= stack->max_alloc - 1) {
        stack->max_alloc *= 2;
        stack->data = realloc(stack->data, stack->max_alloc * sizeof(int));
    }
    stack->data[++stack->top] = value; // Place the new value on top
}

// Pop a value from the stack (remove and return the top value)
int pop(Stack *stack) {
    return stack->data[stack->top--];
}
// The most essential function necessary to evaluate the Reverse Polish Notation expressions
int polish(char **tokens, int size) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < size; i++) {
        char *single_token = tokens[i];
        
        // Check if numeric (including negative numbers)
        // If it's a number, push it onto the stack
        if ((single_token[0] >= '0' && single_token[0] <= '9') || 
            (single_token[0] == '-' && single_token[1] >= '0' && single_token[1] <= '9')) {
            push(&stack, atoi(single_token));
        } 
        // Handle operators
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            if (strcmp(single_token, "p") == 0) {       // Addition
                push(&stack, val2 + val1);
            } 
            else if (strcmp(single_token, "s") == 0) {  // Subtraction
                push(&stack, val2 - val1);
            } 
            else if (strcmp(single_token, "*") == 0) {  // Multiplication
                push(&stack, val2 * val1);
            } 
            else if (strcmp(single_token, "/") == 0) {  // Integer division
                push(&stack, val2 / val1);
            }
        }
    }

    int result = pop(&stack);
    free(stack.data);
    return result;
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);

    // process input: replace "\t" with '\t' and "\n" with '\n'
    processInput(input);

    // Tokenize input with dynamic memory
    char **tokens = malloc(4 * sizeof(char *));
    size_t num_tokens = 0;
    size_t token_mem_cap = 4;

    char *single_token = strtok(input, " \t\n");  // Split on actual whitespace
    while (single_token != NULL) {
        if (num_tokens >= token_mem_cap) {
            token_mem_cap *= 2;
            tokens = realloc(tokens, token_mem_cap * sizeof(char *));
        }

        tokens[num_tokens] = malloc(strlen(single_token) + 1);
        strcpy(tokens[num_tokens], single_token);
        num_tokens++;
        single_token = strtok(NULL, " \t\n");
    }

    // Evaluate and print result
    printf("%d\n", polish(tokens, num_tokens));

    // Cleanup memory
    for (size_t i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
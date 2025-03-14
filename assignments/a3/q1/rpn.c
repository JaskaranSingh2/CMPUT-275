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
    stack->max_alloc = 4; // Initial size
    stack->top = -1;
    stack->data = malloc(stack->max_alloc * sizeof(int));
}

void push(Stack *stack, int value) {
    if (stack->top >= stack->max_alloc - 1) {
        stack->max_alloc *= 2;
        stack->data = realloc(stack->data, stack->max_alloc * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int polish(char **tokens, int size) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < size; i++) {
        char *single_token = tokens[i];
        
        // Check if numeric (including negative numbers)
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
                if (val1 == 0) {
                    exit(1);
                }
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

    // Tokenize input with dynamic memory
    char **tokens = malloc(4 * sizeof(char *));
    size_t num_tokens = 0;
    size_t token_mem_cap = 4;

    char *single_token = strtok(input, " \t\n");
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

    // I clean up the memory here
    for (size_t i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
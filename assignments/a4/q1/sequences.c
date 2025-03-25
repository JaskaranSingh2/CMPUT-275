#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basically, each operation holds the command and the number to apply
typedef struct {
    char op[4];
    int operand;
} Operation;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    // Start with the initial value from command line
    int current = atoi(argv[1]);
    Operation *ops = NULL;
    size_t numOps = 0;
    char command[10];

    // Read each command until EOF
    while (scanf("%9s", command) == 1) {
        if (strcmp(command, "n") == 0) {
            // Compute the next value by applying all operations
            int output = current;
            for (size_t i = 0; i < numOps; i++) {
                if (strcmp(ops[i].op, "add") == 0) {
                    output += ops[i].operand;
                } else if (strcmp(ops[i].op, "sub") == 0) {
                    output -= ops[i].operand;
                } else if (strcmp(ops[i].op, "mul") == 0) {
                    output *= ops[i].operand;
                } else if (strcmp(ops[i].op, "div") == 0) {
                    output /= ops[i].operand;
                }
            }
            printf("%d\n", output);
            current = output; // Update for next 'n'
        } else {
            // Add the new operation to the list
            int operand;
            scanf("%d", &operand);
            Operation newOp;
            strcpy(newOp.op, command);
            newOp.operand = operand;
            numOps++;
            ops = (Operation*)realloc(ops, numOps * sizeof(Operation));
            ops[numOps - 1] = newOp;
        }
    }

    // Clean up dynamically allocated memory
    free(ops);
    return 0;
}
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

    // We're going to start with the initial value from command line
    int currentOp = atoi(argv[1]);
    Operation *ops = NULL;
    size_t numOps = 0;
    char command[10];

    // Read each command until EOF
    while (scanf("%9s", command) == 1) {
        if (strcmp(command, "n") == 0) {
            // Calc. the next value by applying the operations
            int output = currentOp;
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
            currentOp = output; // Update for next n
        } else {
            // Add new operation to the list
            int operand;
            scanf("%d", &operand);
            Operation newOper;
            strcpy(newOper.op, command);
            newOper.operand = operand;
            numOps++;
            ops = (Operation*)realloc(ops, numOps * sizeof(Operation));
            ops[numOps - 1] = newOper;
        }
    }

    // Clean up memory
    free(ops);
    return 0;
}
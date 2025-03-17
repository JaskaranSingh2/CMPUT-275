#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial capacity for our dynamic arrays (sets)
#define INITIAL_CAPACITY 4
// Max length of input lines - should be fine for most inputs in this situation
#define MAX_LINE_LENGTH 1024

// Function declarations
int* create_set();
void add_to_set(int **set, int *size, int *capacity, int value);
void remove_from_set(int *set, int *size, int value);
void print_set(int *set, int size);
void calculate_union(int *set1, int size1, int *set2, int size2);
void calculate_intersection(int *set1, int size1, int *set2, int size2);
int find_in_set(int *set, int size, int value);
void sort_set(int *set, int size);
void free_resources(int *set_x, int *set_y);

int main() {
    // Sets x and y for our operations
    int *set_x = create_set();
    int *set_y = create_set();
    int size_x = 0, size_y = 0;  // Current number of elements
    int capacity_x = INITIAL_CAPACITY, capacity_y = INITIAL_CAPACITY;  // Current allocated size
    
    char line[MAX_LINE_LENGTH];
    
    // Main loop - keep going until we get a quit command
    while (1) {
        // Get a line of input
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            // Handle EOF - the sample seems to quit so we will as well, although the assignment manual doesn't say this - it says we should only do it on 'q'.
            break;
        }
        
        // Process the entire line, char by char
        char *input_pointer = line;
        
        while (*input_pointer) {
            // Skip spaces and tabs
            while (*input_pointer && (*input_pointer == ' ' || *input_pointer == '\t' || *input_pointer == '\n')) {
                input_pointer++;
            }
            
            // If we reached the end of the line, we're done
            if (*input_pointer == '\0') {
                break;
            }
            
            // Get the command (a, r, p, u, i, q)
            char cmd = *input_pointer++;
            
            // Handle quit command
            if (cmd == 'q') {
                free_resources(set_x, set_y);
                return 0;
            }
            
            // Commands that need a target set (a, r, p)
            if (cmd == 'a' || cmd == 'r' || cmd == 'p') {
                // Skip whitespace before target
                while (*input_pointer && (*input_pointer == ' ' || *input_pointer == '\t')) {
                    input_pointer++;
                }
                
                // If we don't have a target, just skip this command
                if (!*input_pointer) continue;
                
                // Get the target set (x or y)
                char target = *input_pointer++;
                
                // For add and remove, we need a value too
                if (cmd == 'a' || cmd == 'r') {
                    // Skip whitespace before the value
                    while (*input_pointer && (*input_pointer == ' ' || *input_pointer == '\t')) {
                        input_pointer++;
                    }
                    
                    // Find the start of the value (could be negative)
                    char *value_starting = input_pointer;
                    
                    // Handle negative numbers
                    if (*input_pointer == '-') {
                        input_pointer++;
                    }
                    
                    // Read digits
                    while (*input_pointer && *input_pointer >= '0' && *input_pointer <= '9') {
                        input_pointer++;
                    }
                    
                    // If we actually found a value
                    if (value_starting != input_pointer) {
                        // Remember the current character
                        char temp = *input_pointer;
                        // Null-terminate so we can convert
                        *input_pointer = '\0';
                        int value = atoi(value_starting);
                        // Restore the character we replaced
                        *input_pointer = temp;
                        
                        // Add or remove based on the command
                        if (cmd == 'a') {
                            if (target == 'x') {
                                add_to_set(&set_x, &size_x, &capacity_x, value);
                            } else if (target == 'y') {
                                add_to_set(&set_y, &size_y, &capacity_y, value);
                            }
                        } else if (cmd == 'r') {
                            if (target == 'x') {
                                remove_from_set(set_x, &size_x, value);
                            } else if (target == 'y') {
                                remove_from_set(set_y, &size_y, value);
                            }
                        }
                    }
                } else if (cmd == 'p') {
                    // Just print the set
                    if (target == 'x') {
                        print_set(set_x, size_x);
                    } else if (target == 'y') {
                        print_set(set_y, size_y);
                    }
                }
            } else if (cmd == 'u') {
                // Union command - doesn't need any args
                calculate_union(set_x, size_x, set_y, size_y);
            } else if (cmd == 'i') {
                // Intersection command - doesn't need any args
                calculate_intersection(set_x, size_x, set_y, size_y);
            }
        }
    }
    
    // Clean up before exit
    free_resources(set_x, set_y);
    
    return 0;
}

// Create a new set with the initial capacity
int* create_set() {
    int* new_set = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (new_set == NULL) {
        // If we can't allocate memory, we're in trouble
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return new_set;
}

// Add a value to a set if it's not already there
void add_to_set(int **set, int *size, int *capacity, int value) {
    // Check if value already exists - sets don't have dupes
    if (find_in_set(*set, *size, value) >= 0) {
        return;  // Already there, nothing to do
    }
    
    // Make sure we have room
    if (*size >= *capacity) {
        // Double the capacity - common strategy
        *capacity *= 2;
        // Allocate new, bigger array
        int *new_set = (int*)malloc(*capacity * sizeof(int));
        if (new_set == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(*set);  // Clean up old array
            exit(1);
        }
        // Copy over the old data
        for (int i = 0; i < *size; i++) {
            new_set[i] = (*set)[i];
        }
        // Free old array and update pointer
        free(*set);
        *set = new_set;
    }
    
    // Add the new value
    (*set)[*size] = value;
    (*size)++;
}

// Remove a value from a set if it's there
void remove_from_set(int *set, int *size, int value) {
    // Find the value first
    int index = find_in_set(set, *size, value);
    
    // If not found, nothing to do
    if (index < 0) {
        return;
    }
    
    // Shift everything after it forward
    for (int i = index; i < *size - 1; i++) {
        set[i] = set[i + 1];
    }
    
    // Update size
    (*size)--;
    
    // We could shrink the array if it gets too empty
    // but not really necessary for this problem
}

// Print a set in sorted order
void print_set(int *set, int size) {
    // Handle empty set - the spec says print nothing
    if (size == 0) {
        return;
    }
    
    // Create a temp array for sorting so we don't mess up the original
    int *temp = (int*)malloc(size * sizeof(int));
    if (temp == NULL && size > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Copy data to temp array
    for (int i = 0; i < size; i++) {
        temp[i] = set[i];
    }
    
    // Sort it
    sort_set(temp, size);
    
    // Print it out with spaces between elements
    for (int i = 0; i < size; i++) {
        printf("%d", temp[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    // Clean up temp array
    free(temp);
}

// Calculate and print the union of two sets
void calculate_union(int *set1, int size1, int *set2, int size2) {
    // Union can be at most size1 + size2 elements (if no overlap)
    int *union_set = (int*)malloc((size1 + size2) * sizeof(int));
    int union_size = 0;
    
    if (union_set == NULL && (size1 + size2) > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Add everything from set1
    for (int i = 0; i < size1; i++) {
        // But check if it's already in our union result
        if (find_in_set(union_set, union_size, set1[i]) < 0) {
            union_set[union_size++] = set1[i];
        }
    }
    
    // Add everything from set2
    for (int i = 0; i < size2; i++) {
        // Again, check if it's already there
        if (find_in_set(union_set, union_size, set2[i]) < 0) {
            union_set[union_size++] = set2[i];
        }
    }
    
    // Print and clean up
    print_set(union_set, union_size);
    free(union_set);
}

// Calculate and print intersection
void calculate_intersection(int *set1, int size1, int *set2, int size2) {
    // Intersection is at most min(size1, size2)
    int max_size = (size1 < size2) ? size1 : size2;
    int *intersection_set = (int*)malloc(max_size * sizeof(int));
    int intersection_size = 0;
    
    if (intersection_set == NULL && max_size > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Find elements that are in both sets
    for (int i = 0; i < size1; i++) {
        if (find_in_set(set2, size2, set1[i]) >= 0) {
            // It's in both sets, so add to intersection
            intersection_set[intersection_size++] = set1[i];
        }
    }
    
    // Print and clean up
    print_set(intersection_set, intersection_size);
    free(intersection_set);
}

// Find a value in a set, returns index or -1 if not found
int find_in_set(int *set, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) {
            return i;
        }
    }
    return -1;  // Not found
}

// Sort a set using bubble sort
// Not the fastest but simple and works for our needs
void sort_set(int *set, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (set[j] > set[j + 1]) {
                // Swap elements if out of order
                int temp = set[j];
                set[j] = set[j + 1];
                set[j + 1] = temp;
            }
        }
    }
}

// Free memory for both sets
void free_resources(int *set_x, int *set_y) {
    free(set_x);
    free(set_y);
}
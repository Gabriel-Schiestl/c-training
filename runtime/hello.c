#include <stdio.h>
#include <stdlib.h>

void hello() {
    printf("Allocating new stack variable in the new stack context...\n");
    int stack_var = 42;
    printf("Stack variable value: %d\n", stack_var);
    printf("Stack variable address: %p\n", (void *)&stack_var);

    printf("Hello, World!\n");
    exit(0);
}
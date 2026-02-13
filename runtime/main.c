//gcc main.c hello.c context_switch.s -o program

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 2048

extern void context_switch(uint8_t *stack_top);

int main() {
    uint8_t *stack = malloc(STACK_SIZE);
    if (stack == NULL) {
        return 1;
    }

    printf("Stack allocated at: %p\n", (void *)stack);
    printf("Stack size: %d bytes\n", STACK_SIZE);
    printf("Stack top address: %p\n", (void *)(stack + STACK_SIZE));

    context_switch(stack + STACK_SIZE);
}
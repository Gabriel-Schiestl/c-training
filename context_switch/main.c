//gcc main.c hello.c context_switch.s -o program

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 2048

extern void context_switch(uint8_t *stack_top);
extern void trampoline();

int main() {
    uint8_t *stack = malloc(STACK_SIZE);
    if (stack == NULL) {
        return 1;
    }

    printf("Stack allocated at: %p\n", (void *)stack);
    printf("Stack size: %d bytes\n", STACK_SIZE);

    uint8_t *stack_top = stack + STACK_SIZE;
    stack_top = (uint8_t *)(((uintptr_t)stack_top & ~0xF)); 

    printf("Stack top address: %p\n", (void *)stack_top);

    stack_top -= 8;

    *(uint64_t *)stack_top = (uint64_t)trampoline;

    context_switch(stack_top);
}
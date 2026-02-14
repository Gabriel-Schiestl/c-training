#ifndef TASK_H
#define TASK_H
#include <stdint.h>

typedef struct Task {
    uint8_t *program_counter;
    uint8_t *stack_pointer;
    uint8_t *processor;
} Task;

#endif
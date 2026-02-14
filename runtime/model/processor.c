#include <stdint.h>
#include <task.h>
#include <stdlib.h>

typedef struct Processor {
    uint64_t queue_capacity;
    uint64_t queue_size;
    uint64_t queue_head;
    uint64_t queue_tail;
    Task **queue;

    Task *(*dequeue_task)(Processor *processor);
    void *(*run)(Processor *processor);
} Processor;

Task *dequeue_task(Processor *processor) {
    if (processor->queue_size == 0) {
        return NULL; 
    }

    Task *task = processor->queue[processor->queue_head];
    processor->queue_head = (processor->queue_head + 1) % processor->queue_capacity;
    processor->queue_size--;

    return task;
}

void *run(Processor *processor) {
    while (1) {
        Task *task = processor->dequeue_task(processor);
        if (task) {
            // Execute the task (not implemented here)
        }
    }
}

Processor *create_processor(uint64_t capacity) {
    Processor *processor = (Processor *)malloc(sizeof(Processor));
    processor->queue_capacity = capacity;
    processor->queue_size = 0;
    processor->queue_head = 0;
    processor->queue_tail = 0;
    processor->queue = (Task **)malloc(capacity * sizeof(Task *));

    processor->dequeue_task = dequeue_task;
    processor->run = run;
    return processor;
}
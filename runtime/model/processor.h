#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "task.h"

typedef struct Processor {
    uint64_t queue_capacity;
    uint64_t queue_size;
    uint64_t queue_head;
    uint64_t queue_tail;
    Task **queue;

    Task *(*dequeue_task)(Processor *processor);
    void *(*run)(Processor *processor);
} Processor;

Task *dequeue_task(Processor *processor);
Processor *create_processor(uint64_t capacity);

#endif /* PROCESSOR_H */
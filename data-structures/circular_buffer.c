#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct CircularBuffer {
    int head, tail;
    int buffer[BUFFER_SIZE];

    void (*add)(struct CircularBuffer* buffer, int num);
    int (*get)(struct CircularBuffer* buffer);
} CircularBuffer;

void add(CircularBuffer* buffer, int num) {
    buffer->buffer[buffer->head] = num;
    buffer->head = (buffer->head + 1) % BUFFER_SIZE; 
}

int get(CircularBuffer* buffer) {
    if(buffer->head == buffer->tail) {
        return -1;
    }

    int num = buffer->buffer[buffer->tail];
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE; 

    return num;
}

CircularBuffer* newBuffer() {
    CircularBuffer* buffer = (CircularBuffer*) malloc(sizeof(CircularBuffer));

    buffer->head = 0;
    buffer->tail = 0;
    buffer->add = &add;
    buffer->get = &get;

    return buffer;
}

int main() {
    CircularBuffer* buffer = newBuffer();

    buffer->add(buffer, 1);
    buffer->add(buffer, 2);
    buffer->add(buffer, 3);

    printf("%d\n", buffer->get(buffer));
    printf("%d\n", buffer->get(buffer));
    printf("%d\n", buffer->get(buffer));

    free(buffer);

    return 0;
}
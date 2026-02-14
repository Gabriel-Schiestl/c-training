#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "processor.h"

void thread_start() {
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * 2);
    Processor** processors = (Processor**)malloc(sizeof(Processor*) * 2);

    for (int i = 0; i < 2; i++) {
        processors[i] = create_processor(10);
        pthread_create(&threads[i], NULL, processors[i]->run, processors[i]);
    }   

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    exit(0);
}
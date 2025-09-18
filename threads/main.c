#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex;

void* counter(void* arg) {
    for(int i = 0; i < 50000; i++) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if(pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Error initializing mutex");
        return 1;
    }

    if(pthread_create(&thread1, NULL, &counter, NULL) != 0) {
        printf("Failed to initialize thread 1");
        return 1;
    }
    if(pthread_create(&thread2, NULL, &counter, NULL) != 0) {
        printf("Failed to initialize thread 2");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Count in the end: %d", count);
}
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CONSUMERS 2
#define MAX_ITEMS 10

int queue[MAX_ITEMS];
int queueSize = 0, head = 0, back = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for(int i = 0; i <= 10; i++) {
        pthread_mutex_lock(&mutex);

        while(queueSize == MAX_ITEMS) {
            pthread_cond_wait(&cond, &mutex);
        }

        queue[back] = i;
        queueSize++;
        back = (back + 1) % MAX_ITEMS;
        printf("Producer published message %d in queue\n", i);

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    pthread_mutex_lock(&mutex);
    queue[back] = -1;
    queueSize++;
    back = (back + 1) % MAX_ITEMS;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    while(1) {
        pthread_mutex_lock(&mutex);

        while(queueSize == 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        int item = queue[head];
        if (item == -1) {
            pthread_mutex_unlock(&mutex);
            break; 
        }
        queueSize--;
        head = (head + 1) % MAX_ITEMS;
        printf("Consumer %d consumed message %d\n", id, item);

        if (queueSize == MAX_ITEMS - 1) {
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
    return NULL;
}

int main() {
    pthread_t prod, consumers[MAX_CONSUMERS];
    int ids[MAX_CONSUMERS];

    if (pthread_create(&prod, NULL, producer, NULL) != 0) {
        fprintf(stderr, "Erro ao criar produtor\n");
        return 1;
    }

    for (int i = 0; i < MAX_CONSUMERS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&consumers[i], NULL, consumer, &ids[i]) != 0) {
            fprintf(stderr, "Erro ao criar consumidor %d\n", i + 1);
            return 1;
        }
    }

    if (pthread_join(prod, NULL) != 0) {
        fprintf(stderr, "Erro ao esperar produtor\n");
        return 1;
    }

    for (int i = 0; i < MAX_CONSUMERS; i++) {
        if (pthread_join(consumers[i], NULL) != 0) {
            fprintf(stderr, "Erro ao esperar consumidor %d\n", i + 1);
            return 1;
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
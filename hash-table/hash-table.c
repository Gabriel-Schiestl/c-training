#include <string.h>
#include <stdint.h>

#define INITIAL_TABLE_SIZE 50

typedef struct Entry {
    char* key;
    void* value;
    int* ttl;
    Entry* next;
} Entry;

Entry *table[INITIAL_TABLE_SIZE];
int table_size = INITIAL_TABLE_SIZE;

int hash(const char *key) {
    int hash_value = 0;
    for(int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % table_size;
    }

    return hash_value;
}

int8_t table_insert(const char* key, Entry* value) {
    if(strlen(key) == 0) {
        return -1;
    }

    int index = hash(key);
    value->next = table[index];
    table[index] = value;

    return 0;
}

int8_t table_delete(const char* key) {
    if (strlen(key) == 0) {
        return -1;
    }

    int index = hash(key);

    Entry **current = &table[index];

    while (*current) {

        Entry *node = *current;

        if (strcmp(node->key, key) == 0) {

            *current = node->next;

            free(node->key);
            free(node);

            continue; 
        }

        current = &node->next;
    }

    return 0;
}

Entry* table_get(const char* key) {
    if (strlen(key) == 0) {
        return -1;
    }

    int index = hash(key);

    Entry* current = table[index];
    while(current) {
        if(strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    

    return 0;
}
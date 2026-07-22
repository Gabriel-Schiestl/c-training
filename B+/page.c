#include <stdlib.h>

#define ENTRY_SIZE 20

typedef struct {
    int entries_count;
    int entries[ENTRY_SIZE];
    int children[ENTRY_SIZE + 1];
} Page;

Page *build_page() {
    Page *p = calloc(1, sizeof(*p));
    return p;
}
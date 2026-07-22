#ifndef PAGE
#define PAGE

#define ENTRY_SIZE 20

typedef struct Page{
    int entries_count;
    int entries[ENTRY_SIZE];
    int children[ENTRY_SIZE + 1];
} Page;

Page *build_page();

#endif
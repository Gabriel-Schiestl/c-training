#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint64_t rootPage;
    uint64_t pageCount;
} Header;

size_t readHeader(Header *h) {
    FILE *file = fopen("/home/schiestl/workspace/c-training/B+/page.bin", "rb");
    if (!file) return -1;

    size_t read = fread(h, sizeof(*h), 1, file);

    fclose(file);

    return read;
}

void buildHeader(Header *h) {
    h->pageCount = 0;
    h->rootPage = 0;
}

size_t writeHeader(Header *h) {
    FILE *file = fopen("/home/schiestl/workspace/c-training/B+/page.bin", "wb");
    if (!file) return -1;

    size_t written = fwrite(h, sizeof(*h), 1, file);

    fclose(file);

    return written;
}
#ifndef HEADER
#define HEADER

#include <stdint.h>
#include <stdio.h>

typedef struct Header {
    uint64_t rootPage;
    uint64_t pageCount;
} Header;

size_t readHeader(Header *h);

void buildHeader(Header *h);

size_t writeHeader(Header *h);

#endif

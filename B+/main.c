#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "page.h"
#include "header.h"

int main() {
    int fd = open("/home/schiestl/workspace/c-training/B+/page.bin", O_CREAT | O_RDONLY);
    if (open == -1) exit(-1);

    close(fd);

    Header h;

    size_t n = readHeader(&h);
    if (n == 0) {
        buildHeader(&h);
        size_t written = writeHeader(&h);
        if (written <= 0) exit(-1);
    }

    Page *p = build_page();
    printf("Page size: %zu\n", sizeof(*p));
    FILE *file = fopen("/home/schiestl/workspace/c-training/B+/page.bin", "wb");
    if (!file) {
        printf("Failed to open file for writing\n");
        return -1;
    }

    size_t size = fwrite(p, sizeof(*p), 1, file);
    if (size == 0) {
        printf("Failed to write to file\n");
        return -1;
    }

    Page pr;
    ssize_t content = fread(&pr, sizeof(pr), 1, file);
    if (content < 0) {
        printf("Failed to read from file\n");
        return -1;
    }

    printf("Entries count: %d\n", pr.entries_count);

    fclose(file);
    free(p);

    return 0;
}
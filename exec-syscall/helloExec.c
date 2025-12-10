#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args) {
    printf("Starting helloExec...\n");

    for(int i = 0; i < argc; i++) {
        printf("%s", args[i]);
    }

    printf("Finishing helloExec...");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** args) {
    printf("Starting main.c...\n");

    char* exec_args[] = {"Hello exec", "Testing", NULL};
    
    execvp("./helloExec", exec_args);

    printf("Finishing main...");

    return 0;
}

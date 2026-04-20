#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child %d (PID %d): Sleeping 5 seconds...\n", i, getpid());
            sleep(5);
            exit(0);
        }
    }
    printf("Parent (PID %d): Waiting for all 3 children...\n", getpid());
    for (int i = 1; i <= 3; i++) wait(NULL);
    printf("All children finished.\n");
    return 0;
}

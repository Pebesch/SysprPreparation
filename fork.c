#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  pid_t pid;

  pid = fork();
  if(pid == 0) {
    // Child
    printf("Child pid is %d.\n", getpid());
    exit(0);
  } else {
    wait(NULL);
    printf("Parent pid is %d.\n", getpid());
  }
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(){
  int fd[2];
  pid_t p;
  

  pipe(fd);
  p = fork();
  if(p == 0){
    char input[] = "Message";
    write(fd[1], input, 100);
    close(fd[1]);
    exit(0);
  } else {
    wait(NULL);
    char str[100];
    read(fd[0], str, 100);
    close(fd[0]);
    printf("%s", str);
  }

}

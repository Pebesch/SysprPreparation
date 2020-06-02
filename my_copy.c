#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  char buf[64];
  ssize_t r;
  ssize_t w;

  char *source = argv[1];

  int fd = open(source, O_RDONLY);
  if(fd == -1)
  {
    printf("%d\n", errno);
  } else {
    r = read(fd, buf, 64);
    if(r != -1) {printf("read: %s\n", buf);}
  }
  
  char *destination = argv[2];
  fd = open(destination, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if(fd == -1)
  {
    printf("%d\n", errno);
  } else {
    w = write(fd, buf, 64);
  }
}

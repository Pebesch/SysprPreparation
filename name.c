#include <stdio.h>

int main(int argc, char *argv[])
{
  char *p;
  for(p = argv[0]; *p != '\0'; p++)
  {
    printf("%c", *p);
  }
}

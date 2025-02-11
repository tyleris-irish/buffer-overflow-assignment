#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int foo(char* arg)
{
  char localArray[150];
  long number = 333333;
  double varDouble= 1.618;
  int *ptr = NULL;
  strcpy(localArray, arg);
  printf("foo() finishes normally.\n");
  return 0;
}

int kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;
  tv.tv_sec=0;  tv.tv_usec=0;
  FD_ZERO(&read_fd);  FD_SET(0,&read_fd);
  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;
  if(FD_ISSET(0,&read_fd))
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf(stderr, "error: target program needs one input parameter.\n");
      exit(EXIT_FAILURE);
    }
  printf("Press return to call the fuction foo()...\n");
  while(!kbhit())
    ;
  foo(argv[1]);
  return 0;
}



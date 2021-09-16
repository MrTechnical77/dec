#include <stdio.h>

int length(char *ptr){
  int i = 0;
  int n = 0;
  while(*(ptr + i) !='\0')
  {
    ++n;
    ++i;
  }
  return n;
}

int power(int a, int b)
{
  int num = 1;
  //if(b) num*=a;
  for(int i = 1; i <= b; i++)
  {
    num*=a;
  }

  return num;
}

int main(int argc, char **argv)
{
  int riley = 36;
  if (argc!=3)  return -1;

  char *base = argv[2];
  char *number = argv[1];
  int base_int = 0;
  for (int i = 0; i < length(base); i++)
  {
    base_int += power(10, length(base) -1 - i) * (base[i] - '0');
  }

  if(base_int>riley || base_int<2)  return -1;

  int num_int = 0;
  for(int i = 0; i <length(number); i++)
  {
    num_int += power(base_int, length(number) - 1 - i) * (number[i] - (number[i] > 57?(number[i] > 90? 'a'-10:'A' - 10):48));
  }

  printf("%d \n", num_int);

  return 0;
}

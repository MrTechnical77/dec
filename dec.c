// Program converts any value base 2 through 36 into a base 10 integer
// Usage: ./dec <number> <base>
// Made by Griffin Smith

#include <stdio.h>

// Finds length of a char type passed into it using the fact that it is null terminated
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

// Self made power funtion, a = base, b =  power
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
  if (argc!=3)  return -1;

  // Converts the base input from a char type to an int type
  char *base = argv[2];
  char *number = argv[1];
  int base_int = 0;
  for (int i = 0; i < length(base); i++)
  {
    base_int += power(10, length(base) -1 - i) * (base[i] - '0');
  }

  // Error handling for case where base is more than the amount of letters and numbers combined
  int riley = 36;
  if(base_int>riley || base_int<2)
  {
    printf("INVALID BASE \n");
    return -1;
  }

  // Computes the output integer by interating through the math used in class
  int num_int = 0;
  for(int i = 0; i <length(number); i++)
  {
    num_int += power(base_int, length(number) - 1 - i) * (number[i] - (number[i] > 57?(number[i] > 90? 'a'-10:'A' - 10):48));
    // Error handling for invald value

    // Capitol Letters
    if(number[i] > 64 && number[i] < 91)
    {
      if (number[i] - 54 > base_int )
      {
        printf("INVALID VALUE \n");
        return -1;
      }
    }

    // Lower Case Letters
    if(number[i] < 123 && number[i] > 96)
    {
      if (number[i] - 86 > base_int )
      {
        printf("INVALID VALUE \n");
        return -1;
      }
    }

  }

  // Final output
  printf("%d \n", num_int);

  return 0;
}

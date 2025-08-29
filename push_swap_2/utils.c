#include "push_swap.h"

//Manejo de máximos y mínimos, y si le pasa una letra que diga que hubo un error
int ft_isdigit(char c)
{
  return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
  int  result;
  int   sign;

  result = 0;
  sign = 1;
  while(*str == ' ' || (*str >= 9 && *str <= 13))
    str++;
  if(*str == '-' || *str == '+')
  {
    if(*str == '-')
      sign = -1;
    str++;
  }
  while(*str >= '0' && *str <= '9')
  {
    result = result * 10 + (*str - '0');
    str++;
  }
  return (sign * result);
}
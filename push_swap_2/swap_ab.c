#include "push_swap.h"

//Hace sa y sb a la vez
void ss(int *a, int size_a, int *b, int size_b)
{
  int temp;

  if(size_a >= 2)
  {
    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
  }

  if(size_b >= 2)
  {
    temp = b[0];
    b[0] = b[1];
    b[1] = temp;
  }

  printf("ss\n");
}

//ra y rb al mismo tiempo
void rr(int *a, int size_a, int *b, int size_b)
{
  int temp;
  int i;

  if (size_a >= 2)
  {
    temp = a[0];
    i = 0;
    while(i < size_a - 1)
    {
      a[i] = a[i + 1];
      i++;
    }
    a[size_a - 1] = temp;
  }

  if (size_b >= 2)
  {
    temp = b[0];
    i = 0;
    while(i < size_b - 1)
    {
      b[i] = b[i + 1];
      i++;
    }
    b[size_b - 1] = temp;
  }
  printf("rr\n");
}

//rra y rrb al mismo tiempo
void rrr(int *a, int size_a, int *b, int size_b)
{
  int temp;
  int i;

  if(size_a >= 2)
  {
    temp = a[size_a - 1];
    i = size_a - 1;
    while(i > 0)
    {
      a[i] = a[i - 1];
      i--;
    }
    a[0] = temp;
  }

  if (size_b >= 2)
  {
    temp = b[size_b - 1];
    i = size_b - 1;
    while(i > 0)
    {
      b[i] = b[i - 1];
      i--;
    }
    b[0] = temp;
  }

  printf("rrr\n");
}
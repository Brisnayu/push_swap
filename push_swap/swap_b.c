#include "push_swap.h"

//Intercambia los dos primeros elementos del stack b.
void sb(int *b, int size_b)
{
  int temp;

  if(size_b < 2)
    return ;
  temp = b[0];
  b[0] = b[1];
  b[1] = temp;
  printf("sb\n");
}

//Toma el primer elemento del stack a y lo pone en primer lugar en el stack b
void pb(int *a, int *size_a, int *b, int *size_b)
{
    if (*size_a == 0)
        return;

    for (int i = *size_b; i > 0; i--)
        b[i] = b[i - 1];

    b[0] = a[0];
    (*size_b)++;

    for (int i = 0; i < *size_a - 1; i++)
        a[i] = a[i + 1];

    (*size_a)--;
    printf("pb\n");
}

//Desplaza hacia arriba todos los elementos del stack b (el primer elemento se convierte en el último)
void rb(int *b, int size_b)
{
  int temp;
  int i;

  if(size_b < 2)
    return ;
  
  temp = b[0];
  i = 0;
  while(i < size_b - 1)
  {
    b[i] = b[i + 1];
    i++;
  }
  b[size_b - 1] = temp;
  printf("rb\n");
}

//Desplaza hacia abajo todos los elementos del stack b (el último elemento se convierte en el primero)
void rrb(int *b, int size_b)
{
  int temp;
  int i;

  if(size_b < 2)
    return ;

  temp = b[size_b - 1];
  i = size_b - 1;
  while(i > 0)
  {
    b[i] = b[i - 1];
    i--;
  }
  b[0] = temp;
  printf("rrb\n");
}

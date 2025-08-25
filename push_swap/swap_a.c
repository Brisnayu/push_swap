#include "push_swap.h"

//Intercambia los dos primeros elementos del stack a.
void sa(int *a, int size_a)
{
  int temp;

  if (size_a < 2)
    return ;
  temp = a[0];
  a[0] = a[1];
  a[1] = temp;
  printf("sa\n");
}

//Toma el primer elemento del stack b y lo pone en primer lugar en el stack a
void pa(int *a, int *size_a, int *b, int *size_b)
{
    if (*size_b == 0)
        return;

    for (int i = *size_a; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = b[0];
    (*size_a)++;

    for (int i = 0; i < *size_b - 1; i++)
        b[i] = b[i + 1];

    (*size_b)--;
    printf("pa\n");
}

//Desplaza hacia arriba todos los elementos del stack a (el primer elemento se convierte en el último)
void ra(int *a, int size_a)
{
    int temp;
    int i;

    if (size_a < 2)
        return;

    temp = a[0];
    i = 0;
    while (i < size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[size_a - 1] = temp;
    printf("ra\n");
}

//Desplaza hacia abajo todos los elementos del stack a (el ultimo elemento se convierte en el primero)
void rra(int *a, int size_a)
{
  int temp;
  int i;

  if(size_a < 2)
    return ;
  
  temp = a[size_a - 1];
  i = size_a - 1;
  while(i > 0)
  {
    a[i] = a[i - 1];
    i--;
  }
  a[0] = temp;
  printf("rra\n");
}

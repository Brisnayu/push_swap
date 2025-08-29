#include "push_swap.h"

void print_stack(int *stack, int size, char *name)
{
    int i;
    
    printf("Stack %s: ", name);
    i = 0;
    while (i < size)
    {
      printf("%d ", stack[i]);
      i++;
    }
    printf("(size: %d)\n", size);
}

int is_sorted(int *a, int size_a, int size_b)
{
  int i;

  if (size_b > 0)
    return (0);

  if (size_a <= 1)
    return (1);
  
  i = 0;
  while(i < size_a - 1)
  {
    if (a[i] > a[i + 1])
      return (0);
    i++;
  }
  return (1);
}

void sort_three(int *a, int size_a)
{
  if(size_a != 3)
    return ;

  int max_pos = 0;
  if(a[1] > a[max_pos])
    max_pos = 1;
  if(a[2] > a[max_pos])
    max_pos = 2;

  if(max_pos == 0)
    ra(a, size_a);
  else if(max_pos == 1)
    rra(a, size_a);
  
  if(a[0] > a[1])
    sa(a, size_a);
}

int main(void)
{
    int a[10] = {9, 4, 2};
    int b[10] = {0};
    int size_a = 3;
    int size_b = 0;
    
    //printf("=== TESTING OPERATIONS ===\n");

    //orden para únicamente 3 elementos, solo 6 combinaciones posibles:

    while(!is_sorted(a, size_a, size_b))
    {
      //print_stack(a, size_a, "A");
      sort_three(a, size_a);
    }

    //print_stack(a, size_a, "A");

    /*
    print_stack(a, size_a, "A inicial");
    print_stack(b, size_b, "B inicial");
    

    pb(a, &size_a, b, &size_b);
    print_stack(a, size_a, "A después de pb");
    print_stack(b, size_b, "B después de pb");
    
    sa(a, size_a);
    print_stack(a, size_a, "A después de sa");
    
    ra(a, size_a);
    print_stack(a, size_a, "A después de ra");
    
    pa(a, &size_a, b, &size_b);
    print_stack(a, size_a, "A después de pa");
    print_stack(b, size_b, "B después de pa");
    */

    




    

    return (0);
}
#include "push_swap.h"

int has_duplicates(int *arr, int size)
{
  int i;
  int duplicates;
  int sorted;

  i = 0;
  sorted = 1;
  while(i < size - 1)
  {
    if(arr[i] == arr[i + 1])
      duplicates = 1;
    if (arr[i] > arr[i + 1])
      sorted = 0;
    i++;
  }
  if(duplicates)
    return (1);
  if(sorted)
    return (2);
  return (0);
}

int *parse_arguments(int argc, char *argv[], int *count)
{
  int *numbers;

  if(argc == 2)
  {
    //SI PASO LOS ARGUMENTOS ASÍ: "1 2 3 4"
    numbers = parse_single_string(argv[1], count);
  }
  else
  {
    //SI PASO LOS ARGUMENTOS ASÍ: 1 2 3
    numbers = parse_multiple_string(argc, argv, count);
  }

  if(numbers && has_duplicates(numbers, *count))
  {
    if(has_duplicates(numbers, *count) == 1)
      printf("NUMERO REPETIDO\n");
    else if (has_duplicates(numbers, *count) == 2)
      printf("NUMEROS ORDENADOS\n");
    free(numbers);
    return (NULL);
  }

  return (numbers);
}

int main(int argc, char *argv[])
{
  int a[1000];
  int b[1000];
  int size_a;
  int size_b;
  int *numbers;
  int count;
  int i;

  size_a = 0;
  size_b = 0;

  if (argc < 2)
  {
    printf("INTRODUCE MÁS DE UN ARGUMENTO\n");
    return (1);
  }

  numbers = parse_arguments(argc, argv, &count);
  if(!numbers)
  {
    printf("ERROR\n");
    return(1);
  }

  i = 0;
  while(i < count)
  {
    a[i] = numbers[i];
    i++;
  }
  size_a = count;

  if (count == 3)
    sort_three(a, size_a);
  else if (count == 2)
    sort_two(a, size_a);
  else
    radix_sort(a, &size_a, b, &size_b, numbers, count);

  free(numbers);
  return (0);
}
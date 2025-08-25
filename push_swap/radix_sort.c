#include "push_swap.h"

static int get_max_bits(int size)
{
  int max_num;
  int bits;

  max_num = size - 1;
  bits = 0;
  while (max_num > 0)
  {
    max_num = max_num / 2;
    bits++;
  }
  return (bits);
}

static void normalize_array(int *arr, int *normalized, int size)
{
  int i;
  int j;
  int count;

  i = 0;
  while(i < size)
  {
    count = 0;
    j = 0;
    while(j < size)
    {
      if (arr[j] < arr[i])
        count++;
      j++;
    }
    normalized[i] = count;
    i++;
  }
}

static int get_normalized_index(int *original, int *normalized, int size, int element)
{
  int i;

  i = 0;
  while(i < size)
  {
    if(original[i] == element)
      return (normalized[i]);
    i++;
  }
  return (0);
}

void radix_sort(int *a, int *size_a, int *b, int *size_b, int *original, int total_size)
{
  int *normalized;
  int max_bits;
  int bit;
  int current_index;
  int i;
  int original_size_a;

  normalized = malloc(sizeof(int) * total_size);
  if (!normalized)
    return ;

  normalize_array(original, normalized, total_size);

  max_bits = get_max_bits(total_size);
  bit = 0;
  while(bit < max_bits)
  {
    original_size_a = *size_a;
    i = 0;
    while (i < original_size_a)
    {
      current_index = get_normalized_index(original, normalized, total_size, a[0]);     
      if (((current_index >> bit) & 1) == 0)
        pb(a, size_a, b, size_b);
      else
        ra(a, *size_a);
      i++;
    }

    while (*size_b > 0)
      pa(a, size_a, b, size_b);
    bit++;
  }
  free(normalized);
}

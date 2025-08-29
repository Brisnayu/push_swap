#include "push_swap.h"

static void normalize_array(int *arr, int *normalized, int size)
{
  int i;
  int j;
  int count;

  i = 0;
  while (i < size)
  {
    count = 0;
    j = 0;
    while (j < size)
    {
      if (arr[j] < arr[i])
        count++;
      j++;
    }
    normalized[i] = count;
    i++;
  }
}

static int calculate_chunk_size(int n_total)
{
  if (n_total <= 100)
    return (5);
  else if (n_total <= 500)
    return (11);
  else
    return (n_total / 50);
}

//Calculo los rangos de cada uno de mis chunks!
static void chunk_range(int chunk_idx, int n_total, int num_chunks, int *min, int *max)
{
  int chunk_size;

  chunk_size = n_total / num_chunks;
  *min = chunk_idx * chunk_size;
  if (chunk_idx == num_chunks - 1)
    *max = n_total - 1;
  else
    *max = ((chunk_idx + 1) * chunk_size) - 1;
}

static int has_in_range(int *arr, int size_a, int min, int max)
{
  int i;

  i = 0;
  while (i < size_a)
  {
    if (arr[i] >= min && arr[i] <= max)
      return (1);
    i++;
  }
  return (0);
}

//Es más facil mover al principio de a, desde el final o desde el principio???
static int first_in_range(int *arr, int size_a, int min, int max)
{
  int i;

  i = 0;
  while (i < size_a)
  {
    if (arr[i] >= min && arr[i] <= max)
      return (i);
    i++;
  }
  return (-1);
}

static int last_in_range(int *arr, int size_a, int min, int max)
{
  int i;

  i = size_a - 1;
  while (i >= 0)
  {
    if (arr[i] >= min && arr[i] <= max)
      return (i);
    i--;
  }
  return (-1);
}

static void top_min_range_a(int *arr, int size_a, int min, int max)
{
  int top_i;
  int bot_i;
  int steps;

  top_i = first_in_range(arr, size_a, min, max);
  bot_i = last_in_range(arr, size_a, min, max);

  if (top_i == -1 || bot_i == -1)
    return ;

  if (top_i <= size_a - 1 - bot_i)
  {
    while (top_i-- > 0)
      ra(arr, size_a);
  }
  else
  {
    steps = size_a - 1 - bot_i + 1;
    while (steps-- > 0)
      rra(arr, size_a);
  }
}

static void push_a_to_b(int *a, int *size_a, int *b, int *size_b, int min, int max)
{
  int mid;
  int val;

  mid = min + (max - min) / 2;
  pb(a, size_a, b, size_b);
  val = b[0];
  if (val < mid && *size_b > 1)
    rb(b, *size_b);
}

void push_chunk_to_b(int *a, int *size_a, int *b, int *size_b, int min, int max)
{
  while (has_in_range(a, *size_a, min, max))
  {
    top_min_range_a(a, *size_a, min, max);
    push_a_to_b(a, size_a, b, size_b, min, max);
  }
}

static int index_of_max(int *b, int size_b)
{
  int i;
  int max;

  i = 0;
  max = 0;

  while (i < size_b)
  {
    if (b[i] > b[max])
      max = i;
    i++;
  }
  return (max);
}

static void max_top_b(int *b, int size_b)
{
  int max;
  int steps;

  max = index_of_max(b, size_b);
  if (max <= size_b / 2)
  {
    while (max-- > 0)
      rb(b, size_b);
  }
  else
  {
    steps = size_b - max;
    while (steps-- > 0)
      rrb(b, size_b);
  }
}

void push_back_a(int *a, int *size_a, int *b, int *size_b)
{
  while (*size_b > 0)
  {
    max_top_b(b, *size_b);
    pa(a, size_a, b, size_b);
  }
}

void fill_stack_with_normalized(t_stack *stack, int *arr, int n_total)
{
  stack->a = malloc(n_total * sizeof(int));
  stack->b = malloc(n_total * sizeof(int));

  if (!stack->a || !stack->b)
    return ;
  stack->size_b = 0;
  normalize_array(arr, stack->a, n_total);
  stack->size_a = n_total;
}

void chunk_sort(t_stack *stack, int *arr, int n_total)
{
  int num_chunks;
  int i;
  int min;
  int max;

  num_chunks = calculate_chunk_size(n_total);
  fill_stack_with_normalized(stack, arr, n_total);

  i = 0;
  while (i < num_chunks)
  {
    chunk_range(i, n_total, num_chunks, &min, &max);
    push_chunk_to_b(stack->a, &stack->size_a, stack->b, &stack->size_b, min, max);
    i++;
  }
  push_back_a(stack->a, &stack->size_a, stack->b, &stack->size_b);
}
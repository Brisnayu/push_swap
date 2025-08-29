#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //QUITAR Y TRAER MI PRINTF
# include <stdlib.h> //malloc y free

typedef struct s_stack
{
  int *a;
  int *b;
  int size_a;
  int size_b;
} t_stack;

typedef struct s_stacks_radix
{
  int	*a;
	int	*size_a;
	int	*b;
	int	*size_b;
	int	*original;
	int	total_size;
} t_stacks_radix;

int ft_atoi(const char *str);
int ft_isdigit(char c);
char **ft_split(const char *s, char c);

//manejo de la llegada de datos
int *parse_single_string(char *str, int *count);
int *parse_multiple_string(int argc, char *argv[], int *count);

//orden bit a bit
void radix_sort(t_stacks_radix *stacks);

void	chunk_sort(t_stack *stack, int *original, int total_size);

//special cases
void sort_five(int *a, int *b, int *size_a, int *size_b);
void sort_four(int *a, int *b, int *size_a, int *size_b);
void sort_three(int *a, int size_a);
void sort_two(int *a, int size_a);

void sa(int *a, int size_a);
void pa(int *a, int *size_a, int *b, int *size_b);
void ra(int *a, int size_a);
void rra(int *a, int size_a);

//void sb(int *b, int size_b);
void pb(int *a, int *size_a, int *b, int *size_b);
void rb(int *b, int size_b);
void rrb(int *b, int size_b);

//void ss(int *a, int size_a, int *b, int size_b);
//void rr(int *a, int size_a, int *b, int size_b);
//void rrr(int *a, int size_a, int *b, int size_b);

#endif

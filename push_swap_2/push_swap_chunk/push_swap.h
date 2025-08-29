#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	min;
	int	max;
}	t_stack;

int		*parse_single_string(char *str, int *count);
int		*parse_multiple_string(int argc, char *argv[], int *count);

void	chunk_sort(t_stack *stack, int total_size);

void	sort_five(int *a, int *b, int *size_a, int *size_b);
void	sort_four(int *a, int *b, int *size_a, int *size_b);
void	sort_three(int *a, int size_a);
void	sort_two(int *a, int size_a);

void	sa(int *a, int size_a);
void	pa(int *a, int *size_a, int *b, int *size_b);
void	ra(int *a, int size_a);
void	rra(int *a, int size_a);

void	pb(int *a, int *size_a, int *b, int *size_b);
void	rb(int *b, int size_b);
void	rrb(int *b, int size_b);

void	normalize_array(t_stack *stack, int *original_arr);
void	top_min_range_a(t_stack *stack);
void	push_a_to_b(t_stack *stack);

void	push_chunk_to_b(t_stack *stack);
void	push_back_a(t_stack *stack);

#endif

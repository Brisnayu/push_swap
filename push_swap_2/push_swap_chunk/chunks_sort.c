#include "push_swap.h"

static int	calculate_chunk_size(int n_total)
{
	if (n_total <= 100)
		return (5);
	else if (n_total <= 500)
		return (11);
	else
		return (n_total / 50);
}

static void	chunk_range(t_stack *stack, int chunk_idx, int n_total,
		int num_chunks)
{
	int	chunk_size;

	chunk_size = n_total / num_chunks;
	stack->min = chunk_idx * chunk_size;
	if (chunk_idx == num_chunks - 1)
		stack->max = n_total - 1;
	else
		stack->max = ((chunk_idx + 1) * chunk_size) - 1;
}

void	chunk_sort(t_stack *stack, int n_total)
{
	int	num_chunks;
	int	i;

	num_chunks = calculate_chunk_size(n_total);
	i = 0;
	while (i < num_chunks)
	{
		chunk_range(stack, i, n_total, num_chunks);
		push_chunk_to_b(stack);
		i++;
	}
	push_back_a(stack);
}

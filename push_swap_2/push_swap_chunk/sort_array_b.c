#include "push_swap.h"

static int	has_in_range(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] >= stack->min && stack->a[i] <= stack->max)
			return (1);
		i++;
	}
	return (0);
}

void	push_chunk_to_b(t_stack *stack)
{
	while (has_in_range(stack))
	{
		top_min_range_a(stack);
		push_a_to_b(stack);
	}
}

static int	index_of_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[max])
			max = i;
		i++;
	}
	return (max);
}

static void	max_top_b(t_stack *stack)
{
	int	max;
	int	steps;

	max = index_of_max(stack);
	if (max <= stack->size_b / 2)
	{
		while (max-- > 0)
			rb(stack->b, stack->size_b);
	}
	else
	{
		steps = stack->size_b - max;
		while (steps-- > 0)
			rrb(stack->b, stack->size_b);
	}
}

void	push_back_a(t_stack *stack)
{
	while (stack->size_b > 0)
	{
		max_top_b(stack);
		pa(stack->a, &stack->size_a, stack->b, &stack->size_b);
	}
}

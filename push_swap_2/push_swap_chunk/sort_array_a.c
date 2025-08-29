#include "push_swap.h"

void	normalize_array(t_stack *stack, int *original_arr)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->size_a)
	{
		count = 0;
		j = 0;
		while (j < stack->size_a)
		{
			if (original_arr[j] < original_arr[i])
				count++;
			j++;
		}
		stack->a[i] = count;
		i++;
	}
}

static int	first_in_range(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] >= stack->min && stack->a[i] <= stack->max)
			return (i);
		i++;
	}
	return (-1);
}

static int	last_in_range(t_stack *stack)
{
	int	i;

	i = stack->size_a - 1;
	while (i >= 0)
	{
		if (stack->a[i] >= stack->min && stack->a[i] <= stack->max)
			return (i);
		i--;
	}
	return (-1);
}

void	top_min_range_a(t_stack *stack)
{
	int	top_i;
	int	bot_i;
	int	steps;

	top_i = first_in_range(stack);
	bot_i = last_in_range(stack);
	if (top_i == -1 || bot_i == -1)
		return ;
	if (top_i <= stack->size_a - 1 - bot_i)
	{
		while (top_i-- > 0)
			ra(stack->a, stack->size_a);
	}
	else
	{
		steps = stack->size_a - 1 - bot_i + 1;
		while (steps-- > 0)
			rra(stack->a, stack->size_a);
	}
}

void	push_a_to_b(t_stack *stack)
{
	int	mid;
	int	val;

	mid = stack->min + (stack->max - stack->min) / 2;
	pb(stack->a, &stack->size_a, stack->b, &stack->size_b);
	val = stack->b[0];
	if (val < mid && stack->size_b > 1)
		rb(stack->b, stack->size_b);
}

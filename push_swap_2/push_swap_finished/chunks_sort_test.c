#include "push_swap.h"

static void	normalize_array(int *arr, int *normalized, int size)
{
	int	i;
	int	j;
	int	count;

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

static int	get_normalized_value(int *original, int *normalized, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (original[i] == value)
			return (normalized[i]);
		i++;
	}
	return (-1);
}

static int	calculate_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (total_size / 5);
	else if (total_size <= 500)
		return (total_size / 11);
	else
		return (total_size / 22);
}

static void	push_chunk_to_b(t_stack *stack, int *original, int *normalized, 
							int chunk_min, int chunk_max, int total_size)
{
	int	original_size;
	int	normalized_val;
	int	i;

	original_size = stack->size_a;
	i = 0;
	while (i < original_size)
	{
		normalized_val = get_normalized_value(original, normalized, 
											total_size, stack->a[0]);
		if (normalized_val >= chunk_min && normalized_val <= chunk_max)
		{
			pb(stack->a, &stack->size_a, stack->b, &stack->size_b);
			if (stack->size_b > 1 && normalized_val < (chunk_min + chunk_max) / 2)
				rb(stack->b, stack->size_b);
		}
		else
			ra(stack->a, stack->size_a);
		i++;
	}
}

static void	push_back_sorted(t_stack *stack, int *original, int *normalized, int total_size)
{
	int	max_pos;
	int	max_normalized;
	int	current_normalized;
	int	i;

	while (stack->size_b > 0)
	{
		max_pos = 0;
		max_normalized = get_normalized_value(original, normalized, 
											total_size, stack->b[0]);
		i = 1;
		while (i < stack->size_b)
		{
			current_normalized = get_normalized_value(original, normalized, 
													total_size, stack->b[i]);
			if (current_normalized > max_normalized)
			{
				max_normalized = current_normalized;
				max_pos = i;
			}
			i++;
		}
		if (max_pos <= stack->size_b / 2)
		{
			while (max_pos > 0)
			{
				rb(stack->b, stack->size_b);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < stack->size_b)
			{
				rrb(stack->b, stack->size_b);
				max_pos++;
			}
		}
		pa(stack->a, &stack->size_a, stack->b, &stack->size_b);
	}
}

void	chunk_sort(t_stack *stack, int *original, int total_size)
{
	int	*normalized;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;

	normalized = malloc(sizeof(int) * total_size);
	if (!normalized)
		return ;
	normalize_array(original, normalized, total_size);
	chunk_size = calculate_chunk_size(total_size);
	chunk_min = 0;
	while (stack->size_a > 3)
	{
		chunk_max = chunk_min + chunk_size - 1;
		if (chunk_max >= total_size)
			chunk_max = total_size - 1;
		push_chunk_to_b(stack, original, normalized, chunk_min, chunk_max, total_size);
		chunk_min = chunk_max + 1;
	}
	if (stack->size_a == 3)
		sort_three(stack->a, stack->size_a);
	else if (stack->size_a == 2)
		sort_two(stack->a, stack->size_a);
	push_back_sorted(stack, original, normalized, total_size);
	free(normalized);
}
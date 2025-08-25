#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	bits;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num = max_num / 2;
		bits++;
	}
	return (bits);
}

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

static int	get_normalized_index(int *original, int *normalized, int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (original[i] == element)
			return (normalized[i]);
		i++;
	}
	return (0);
}

static void	process_bit(t_stacks_radix *stacks, int *normalized, int bit)
{
	int	count;
	int	i;

	count = *(stacks->size_a);
	i = 0;
	while (i < count)
	{
		if (((get_normalized_index(stacks->original, normalized,
				stacks->total_size, stacks->a[0]) >> bit) & 1) == 0)
			pb(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
		else
			ra(stacks->a, *(stacks->size_a));
		i++;
	}
	while (*(stacks->size_b) > 0)
		pa(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
}

void	radix_sort(t_stacks_radix *stacks)
{
	int	*normalized;
	int	bit;

	normalized = malloc(sizeof(int) * stacks->total_size);
	if (!normalized)
		return ;
	normalize_array(stacks->original, normalized, stacks->total_size);
	bit = 0;
	while (bit < get_max_bits(stacks->total_size))
	{
		process_bit(stacks, normalized, bit);
		bit++;
	}
	free(normalized);
}

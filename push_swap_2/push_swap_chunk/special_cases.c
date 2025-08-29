#include "push_swap.h"

static int	find_min_pos(int *a, int size_a)
{
	int	min;
	int	pos;
	int	i;

	min = a[0];
	pos = 0;
	i = 0;
	while (i < size_a)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	sort_two(int *a, int size_a)
{
	if (size_a != 2)
		return ;
	if (a[0] > a[1])
		sa(a, size_a);
}

void	sort_three(int *a, int size_a)
{
	int	max_pos;

	if (size_a != 3)
		return ;
	max_pos = 0;
	if (a[1] > a[max_pos])
		max_pos = 1;
	if (a[2] > a[max_pos])
		max_pos = 2;
	if (max_pos == 0)
		ra(a, size_a);
	else if (max_pos == 1)
		rra(a, size_a);
	if (a[0] > a[1])
		sa(a, size_a);
}

void	sort_four(int *a, int *b, int *size_a, int *size_b)
{
	int	min_pos;

	min_pos = find_min_pos(a, *size_a);
	if (min_pos == 1)
		ra(a, *size_a);
	else if (min_pos == 2)
	{
		ra(a, *size_a);
		ra(a, *size_a);
	}
	else if (min_pos == 3)
		rra(a, *size_a);
	pb(a, size_a, b, size_b);
	sort_three(a, *size_a);
	pa(a, size_a, b, size_b);
}

void	sort_five(int *a, int *b, int *size_a, int *size_b)
{
	int	min_pos;

	min_pos = find_min_pos(a, *size_a);
	if (min_pos == 1)
		ra(a, *size_a);
	else if (min_pos == 2)
	{
		ra(a, *size_a);
		ra(a, *size_a);
	}
	else if (min_pos == 3)
	{
		rra(a, *size_a);
		rra(a, *size_a);
	}
	else if (min_pos == 4)
		rra(a, *size_a);
	pb(a, size_a, b, size_b);
	sort_four(a, b, size_a, size_b);
	pa(a, size_a, b, size_b);
}

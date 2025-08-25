#include "push_swap.h"

void	sa(int *a, int size_a)
{
	int	temp;

	if (size_a < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	printf("sa\n");
}

void	pa(int *a, int *size_a, int *b, int *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	(*size_a)++;
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_b)--;
	printf("pa\n");
}

void	ra(int *a, int size_a)
{
	int	temp;
	int	i;

	if (size_a < 2)
		return ;
	temp = a[0];
	i = 0;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = temp;
	printf("ra\n");
}

void	rra(int *a, int size_a)
{
	int	temp;
	int	i;

	if (size_a < 2)
		return ;
	temp = a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	printf("rra\n");
}

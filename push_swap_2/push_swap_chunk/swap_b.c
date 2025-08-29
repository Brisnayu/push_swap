#include "push_swap.h"

void	pb(int *a, int *size_a, int *b, int *size_b)
{
	int	i;

	if (*size_a == 0)
		return ;
	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	(*size_b)++;
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_a)--;
	ft_printf("pb\n");
}

void	rb(int *b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return ;
	temp = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = temp;
	ft_printf("rb\n");
}

void	rrb(int *b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return ;
	temp = b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	ft_printf("rrb\n");
}

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
	printf("pb\n");
}

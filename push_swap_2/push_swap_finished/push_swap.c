#include "push_swap.h"

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			sorted = 0;
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	if (sorted)
		return (2);
	return (0);
}

static int	*parse_arguments(int argc, char *argv[], int *count)
{
	int	*numbers;
	int	dup_status;

	if (argc == 2)
		numbers = parse_single_string(argv[1], count);
	else
		numbers = parse_multiple_string(argc, argv, count);
	if (!numbers)
		return (NULL);
	dup_status = has_duplicates(numbers, *count);
	if (dup_status)
	{
		if (dup_status == 1)
			printf("NUMERO REPETIDO\n");
		else if (dup_status == 2)
			printf("NUMEROS ORDENADOS\n");
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

static void	fill_radix_struct(t_stacks_radix *rs, t_stack *stack,
								int *numbers, int count)
{
	rs->a = stack->a;
	rs->size_a = &stack->size_a;
	rs->b = stack->b;
	rs->size_b = &stack->size_b;
	rs->original = numbers;
	rs->total_size = count;
}

static void	init_and_sort(t_stack *stack, int *numbers, int count)
{
	int								i;
	t_stacks_radix		rs;

	i = 0;
	while (i < count)
	{
		stack->a[i] = numbers[i];
		i++;
	}
	stack->size_a = count;
	if (count == 5)
		sort_five(stack->a, stack->b, &stack->size_a, &stack->size_b);
	else if (count == 4)
		sort_four(stack->a, stack->b, &stack->size_a, &stack->size_b);
	else if (count == 3)
		sort_three(stack->a, stack->size_a);
	else if (count == 2)
		sort_two(stack->a, stack->size_a);
	else
	{
		fill_radix_struct(&rs, stack, numbers, count);
		//radix_sort(&rs);
		//chunk_sort(stack, numbers, count);
		chunk_sort(stack, numbers, count);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;
	int		*numbers;
	int		count;

	stacks.size_a = 0;
	stacks.size_b = 0;
	if (argc < 2)
	{
		printf("INTRODUCE MÁS DE UN ARGUMENTO\n");
		return (1);
	}
	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
	{
		printf("ERROR\n");
		return (1);
	}
	init_and_sort(&stacks, numbers, count);
	free(numbers);
	return (0);
}

#include "push_swap.h"

static int	is_numeric_string(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	free_all_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	validate_and_count(char **split_result)
{
	int	count;

	count = 0;
	while (split_result[count])
	{
		if (!is_numeric_string(split_result[count]))
		{
			printf("Caracteres invalidos\n");
			return (-1);
		}
		count++;
	}
	return (count);
}

int	*parse_single_string(char *str, int *count)
{
	char	**split_result;
	int		*numbers;
	int		i;

	split_result = ft_split(str, ' ');
	if (!split_result)
		return (NULL);
	*count = validate_and_count(split_result);
  numbers = malloc((*count) * sizeof(int));
	if (*count <= 0 || !numbers)
	{
		free_all_split(split_result);
		return (NULL);
	}
	i = -1;
	while (++i < *count)
		numbers[i] = ft_atoi(split_result[i]);
	free_all_split(split_result);
	return (numbers);
}

int	*parse_multiple_string(int argc, char *argv[], int *count)
{
	int	*numbers;
	int	i;

	*count = argc - 1;
	numbers = malloc((*count) * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		if (!is_numeric_string(argv[i + 1]))
		{
			printf("Caracteres invalidos\n");
			free(numbers);
			return (NULL);
		}
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (numbers);
}

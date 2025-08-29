CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
SRC = push_swap.c parse_string.c utils.c split.c swap_a.c swap_b.c radix_sort.c special_cases.c chunks_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
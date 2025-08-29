CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = push_swap.c parse_string.c swap_a.c swap_b.c special_cases.c chunks_sort.c sort_array_a.c sort_array_b.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "libft compiled successfully"

$(PRINTF):
	@echo "Compilando printf..."
	$(MAKE) -C $(PRINTF_DIR)
	@echo "printf compiled successfully"

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "Compilando push_swap..."
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "🌟push_swap compiled successfully🌟"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) *.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
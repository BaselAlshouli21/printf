MAKEFLAGS += --no-print-directory

CC = cc
FLAGS = -Wall -Werror -Wextra -g
NAME = printf
OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
	ft_printf_utils.c \
	ft_parser.c \
	ft_parser_utils.c \
	ft_renderer.c \
	ft_renderer_utils.c \
	testing_func.c \
	main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
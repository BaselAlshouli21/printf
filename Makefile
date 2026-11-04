MAKEFLAGS += --no-print-directory

CC = cc
FLAGS = -Wall -Werror -Wextra -I.
NAME = libftprintf.a
OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
	utils/ft_printf_utils.c \
	utils/ft_parser_utils.c \
	utils/ft_renderer_utils.c \
	renderer/ft_renderer.c \
	renderer/ft_render_flags.c \
	renderer/ft_render_specifiers.c \
	parser/ft_parser.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

bonus: all

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c ft_printf.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f printf

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
OBJ_DIR	= obj

SRCS	= \
	ft_isdigit.c \
	ft_memset.c \
	ft_strlen.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c libft.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
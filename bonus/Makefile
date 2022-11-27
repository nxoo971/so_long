
NAME = so_long 

SRCS = main.c parser.c valid_map.c potential_errors.c virus.c load.c move.c draw.c free.c key_hook.c

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = gcc

RM = rm -f

HEADER = so_long.h
MLX_DIR = mlx
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L. -lXext -L. -lX11
CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):  $(MLX) $(OBJS)
		${CC} $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME) ../ft_printf/libftprintf.a

$(MLX):
				$(MAKE) -C $(MLX_DIR)
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN) ./_so_long have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY: all clean fclean re minilibx
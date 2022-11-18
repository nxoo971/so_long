
NAME = so_long 

SRCS = main.c parser.c valid_map.c

# Colors

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
HEADER_BONUS = so_long_bonus.h
MLX_DIR = mlx
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L. -lXext -L. -lX11
CFLAGS = -Wall -Wextra -Werror 

OBJS = ${SRCS:.c=.o}

$(NAME):  $(MLX) $(OBJS) 
		${CC} $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME) ft_printf/libftprintf.a
		
#$(OBJS) : $(HEADER)


all:	$(NAME)
		@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"
$(MLX):
				$(MAKE) -C $(MLX_DIR)
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

bonus: $(NAME_BONUS)
	   @echo "$(GREEN)bonus compiled!$(DEF_COLOR)"
		


$(NAME_BONUS):$(MLX) $(OBJS_BONUS) 
		${CC} $(CFLAGS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

-include $(SRCS:.c=.d)

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY: all clean fclean re minilibx

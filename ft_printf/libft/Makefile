SRCS	= ft_striteri.c ft_strtrim.c ft_strmapi.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_strchr.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
			ft_strlcat.c ft_strnstr.c ft_isalnum.c ft_isprint.c ft_memset.c ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_strnrchr.c ft_substr.c ft_split.c ft_strjoin.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

ADDED	= ft_putchar.c ft_putstr.c ft_putnstr.c ft_putnstr_fd.c ft_putendl.c ft_putnendl.c ft_putnendl_fd.c ft_putnbr.c ft_strcpy.c ft_isspace.c ft_swap.c ft_strcmp.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GNL		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PRINTF	= ft_printf/ft_printf.c ft_printf/extract_spec_info.c ft_printf/accept.c ft_printf/explain_specification.c ft_printf/algo_flag.c ft_printf/exec_integer.c ft_printf/exec_octal.c ft_printf/exec_binary.c ft_printf/exec_unsigned.c ft_printf/exec_double.c ft_printf/exec_string.c ft_printf/calc_len.c ft_printf/operations.c ft_printf/color.c ft_printf/print.c 

NAME	= libft.a

OBJS		= ${SRCS:.c=.o} ${ADDED:.c=.o} 

OBJS_BONUS	= ${BONUS:.c=.o}

OBJS_GNL	= ${GNL:.c=.o}

OBJS_PRINTF	= ${PRINTF:.c=.o}

HEADERS	= ./

.c.o	:
		gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rcs ${NAME} ${OBJS}

all : ${NAME}

bonus	: $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

gnl		: $(OBJS_GNL)
		ar rcs $(NAME) $(OBJS_GNL)

printf	: $(OBJS_PRINTF)
		ar rcs $(NAME) $(OBJS_PRINTF)

any		: $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)

clean :
		rm -f ${OBJS} ${OBJS_BONUS} $(OBJS_GNL) $(OBJS_PRINTF)

fclean : clean
		rm -f ${NAME}

re : fclean all

NAME	= libftprintf.a
SRCS	= ft_printf.c
OBJS	= $(SRCS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -c
RM		= rm -f
LIBFT = libft/libft.a


.c.o:
	$(CC) $(CFLAGS) $(NAME) $< -o $@

all:	$(NAME)


$(NAME): lib $(OBJS)
	cp -f $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

lib:
	@make -C ./libft

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

clean:
	$(RM) $(OBJS)
	@make clean -C ./libft

fclean:		clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re:			fclean all

#dbuild:
#	docker build . -t 42tokyo
#
#drun:
#	docker run -v `pwd`:/user42 -w /user42 --rm -it 42tokyo
#
## for test
#printf: lib
#	$(CC) $(CFLAGS) $(NAME) ft_printf.c -o printf -D TEST
#
#ft_printf: lib
#	$(CC) $(CFLAGS) $(NAME) ft_printf.c -o ft_printf -D TEST -D FT_PRINTF
#
#test: printf ft_printf
#	sh test.sh
#
#a: libft
#	$(CC) $(CFLAGS) $(NAME) ft_printf.c -D TEST -D FT_PRINTF

.PHONY:		all clean fclean re bonus

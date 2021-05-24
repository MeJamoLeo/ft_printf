NAME	= libftprintf.a
SRCS	= ft_printf.c
OBJS	= $(SRCS:%.c=%.o)
	CC = gcc
	CFLAGS = -Wall -Werror -Wextra -c
	#CFLAGS = -Wall -Werror -Wextra -I ./libft -c
	RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) $< -o $@

all:	$(NAME)


$(NAME): libft $(OBJS)
	ar rcs $(NAME) $(OBJS)

libft:
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)

$(OBJS):
	$(CC) $(CFCLAGS) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

dbuild:
	docker build . -t 42tokyo

drun:
	docker run -v `pwd`:/user42 -w /user42 --rm -it 42tokyo

# for test
printf: libft
	$(CC) $(CFCLAGS) $(NAME) ft_printf.c -o printf -D TEST

ft_printf: libft
	$(CC) $(CFCLAGS) $(NAME) ft_printf.c -o ft_printf -D TEST -D FT_PRINTF

test: printf ft_printf
	sh test.sh

a: libft
	$(CC) $(CFCLAGS) $(NAME) ft_printf.c -D TEST -D FT_PRINTF

# end
.PHONY:		all clean fclean re bonus

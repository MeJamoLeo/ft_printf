NAME	= libftprintf.a
SRCS	= ft_printf
#OBJS	= $(SRCS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
#CFLAGS = -Wall -Werror -Wextra -I ./libft -c
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) $< -o $@

all:	$(NAME)

# for test
printf:
	$(CC) $(CFCLAGS) ft_printf.c -o printf -D TEST
ft_printf:
	$(CC) $(CFCLAGS) ft_printf.c -o ft_printf -D TEST -D FT_PRINTF
test: printf ft_printf
	sh test.sh
# end

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFCLAGS) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

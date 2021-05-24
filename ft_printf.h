#ifndef PRINTF_H
# define PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>

# define CNV "dicssuxXp"
# define FIELD_MYNUS 0
# define FIELD_ZERO 1
# define TRUE 1

typedef struct	s_conv_str
{
	int	start;
	int	flag[2];
	int	field;
	int	ast_field;
	int	precision;
	int	ast_precision;
	int	conv_char;
}				t_conv_str;

#endif

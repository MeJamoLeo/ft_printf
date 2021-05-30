#ifndef PRINTF_H
# define PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>

# define CNV "dicssuxXp"
# define FLAG_MYNUS 0
# define FLAG_ZERO 1
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

int	pf_read_conv(t_conv_str *conv, const char *str, int itr);
void	pf_put_conv(va_list args, t_conv_str *conv);
char	*ft_uitobase(unsigned int num, char *base);
char	*ft_uitoa(unsigned int ui);
char	*ft_ultobase(unsigned long num, char *base);

void	pf_put_di(va_list args, t_conv_str *conv);
#endif

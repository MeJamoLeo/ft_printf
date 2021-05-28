/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:22 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 17:17:16 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_conv(va_list args, t_conv_str *conv)
{
	if (conv->ast_field)
		conv->field = va_arg(args, int);
	if (conv->ast_precision)
		conv->precision = va_arg(args, int);

	char	*str;
	char	*tmp;
	char	c;

	if (conv->conv_char == 'i' || conv->conv_char == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (conv->conv_char == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (conv->conv_char == 'c')
	{
		c = va_arg(args, int);
		str = ft_strdup(&c);
	}
	else if (conv->conv_char == 'u')
		str = ft_uitoa(va_arg(args, unsigned int));
	else if (conv->conv_char == 'x')
		str = ft_uitobase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conv->conv_char == 'X')
		str = ft_uitobase(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (conv->conv_char == 'p')
	{
		str = ft_ultobase((unsigned long)va_arg(args, void *), "0123456789abcdef");
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
}

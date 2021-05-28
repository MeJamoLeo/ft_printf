/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:22 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 11:11:04 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_conv(va_list args, t_conv_str *conv)
{
	char	*str;
	char	tmp;

	str = NULL;
	tmp = 0;
	if (conv->conv_char == 'i' || conv->conv_char == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (conv->conv_char == 's')
		str = va_arg(args, char *);
	else if (conv->conv_char == 'c')
		tmp = va_arg(args, int);
	else if (conv->conv_char == 'u')
		str = ft_uitoa(va_arg(args, unsigned int));
	else if (conv->conv_char == 'x')
		str = ft_uitobase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conv->conv_char == 'X')
		str = ft_uitobase(va_arg(args, unsigned int), "0123456789ABCDEF");

	// 実際の出力
	if (conv->conv_char == 'c')
		ft_putchar_fd(tmp, 1);
	else
		ft_putstr_fd(str, 1);
}

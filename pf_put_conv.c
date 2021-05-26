/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:22 by treo              #+#    #+#             */
/*   Updated: 2021/05/27 01:26:10 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_conv(va_list args, t_conv_str *conv, int itr)
{
	char	*str;
	char	tmp;

	if (conv->conv_char == 'i' || conv->conv_char == 'd')
		str = ft_itoa(va_arg(args, int));
	if (conv->conv_char == 's')
		str = va_arg(args, char *);
	if (conv->conv_char == 'c')
		tmp = va_arg(args, int);


	// 実際の出力
	if (conv->conv_char == 'c')
		ft_putchar_fd(tmp, 1);
	else
		ft_putstr_fd(str, 1);
}

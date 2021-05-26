/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:45 by treo              #+#    #+#             */
/*   Updated: 2021/05/26 11:47:42 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int	ft_printf(const char *format, ...)
{
	int	i;
	va_list ap;
	t_conv_str	conv;

	i = 0;
	va_start(ap, format);
	while (*(format + i) != '\0') // format渡された文字列をループ
	{
		// ---------------------------------------------------- 通常文字を読み，出力
		if (*(format + i) != '%')
		{
			ft_putchar_fd(*(format + i) , 1);
			i++;
			continue;
		}
		i = pf_read_conv(&conv, format, i);
		if (i < 0)
			return (-1);
		// ---------------------------------------------------- 出力する
		pf_put_conv(ap, &conv, i);
	}
	printf("\n\nformat:	%s\nstart:	%d\nMYNUS:	%d\nZERO:	%d\nfield:	%d\nast_field:	%d\nprecision:	%d\nast_precision:	%d\nconv_char:	%c\n", format, conv.start, conv.flag[FLAG_MYNUS], conv.flag[FLAG_ZERO], conv.field, conv.ast_field, conv.precision, conv.ast_precision, conv.conv_char);

	va_end(ap);
	return (i);
}

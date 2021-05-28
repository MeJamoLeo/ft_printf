/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:45 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 01:17:51 by treo             ###   ########.fr       */
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
			break;
		// ---------------------------------------------------- 出力する
		pf_put_conv(ap, &conv);
	}
	va_end(ap);
	if (i < 0)
		return (-1);
	return (i);
}

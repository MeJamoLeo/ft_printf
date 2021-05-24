/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:45 by treo              #+#    #+#             */
/*   Updated: 2021/05/24 17:35:51 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_conv(t_conv_str *conv, int itr)
{
	conv->start = itr;
	ft_bzero(conv->flag, 2);
	conv->field = 0;
	conv->ast_field = 0;
	conv->precision = 0;
	conv->ast_precision = 0;
	conv->conv_char = 0;
}

#include <stdio.h>
int	ft_printf(const char *format, ...)
{
	int	i;
	t_conv_str	conv;

	i = 0;
	while (*(format + i) != '\0') // format渡された文字列をループ
	{
		// ---------------------------------------------------- 通常文字を読み，出力
		if (*(format + i) != '%')
		{
			ft_putchar_fd(*(format + i++) , 1);
			i++;
			continue;
		}
		// ---------------------------------------------------- 変換指定を読む
		init_conv(&conv, i);
		i++;
		// ------------------------- flag
		while (ft_strchr("-0", *(format + i)))
		{
			if (*(format + i) == '-')
				conv.flag[FIELD_MYNUS] += 1;
			else
				conv.flag[FIELD_ZERO] += 1;
			i++;
		}
		// ------------------- validation flag
		if (conv.flag[FIELD_MYNUS] > 1 || conv.flag[FIELD_ZERO] > 1)
		{
			ft_putchar_fd(*(format + conv.start), 1);
			i = conv.start + 1;
			continue;
		}

		// ------------------------- field
		if (*(format + i) == '*')
		{
			conv.ast_field = TRUE;
			i++;
		}
		else
			while (ft_isdigit(*(format + i)))
			{
				conv.field *= 10;
				conv.field += *(format + i) - '0';
				i++;
			}
		// ------------------------- precision
		if (*(format + i) == '.')
		{
			i++;
			if (*(format + i) == '*')
			{
				conv.ast_precision = TRUE;
				i++;
			}
			else
				while (ft_isdigit(*(format + i)))
				{
					conv.field *= 10;
					conv.field += *(format + i) - '0';
					i++;
				}
		}
		// ------------------------- cnv_specifer
		if (ft_strchr(CNV, *(format + i)))
		{
			conv.conv_char = *(format + i);
			i++;
		}
		else
		{
			ft_putchar_fd(*(format + conv.start), 1);
			i = conv.start + 1;
			continue;
		}
		printf( "format:	%s\nstart:	%d\nMYNUS:	%d\nZERO:	%d\nfield:	%d\nast_field:	%d\nprecision:	%d\nast_precision:	%d\nconv_char:	%c\n", format, conv.start, conv.flag[FIELD_MYNUS], conv.flag[FIELD_ZERO], conv.field, conv.ast_field, conv.precision, conv.ast_precision, conv.conv_char);
			// ---------------------------------------------------- 出力する
	}
	return (i);
}

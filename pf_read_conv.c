/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:02:25 by treo              #+#    #+#             */
/*   Updated: 2021/05/30 13:20:12 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_conv(t_conv_str *conv, int itr)
{
	conv->start = itr;
	conv->flag[FLAG_MYNUS] = 0;
	conv->flag[FLAG_ZERO] = 0;
	conv->field = 0;
	conv->ast_field = 0;
	conv->precision = 0;
	conv->ast_precision = 0;
	conv->conv_char = 0;
}

int		pf_read_conv(t_conv_str *conv, const char *str, int itr)
{
		// ---------------------------------------------------- 変換指定を読む
		init_conv(conv, itr);
		itr++;
		// ------------------------- flag
		while (ft_strchr("-0", *(str + itr)))
		{
			if (*(str + itr) == '-')
				conv->flag[FLAG_MYNUS] += 1;
			else
				conv->flag[FLAG_ZERO] += 1;
			itr++;
		}
		// ------------------- validation flag
		if (conv->flag[FLAG_MYNUS] > 1 || conv->flag[FLAG_ZERO] > 1)
		{
			ft_putchar_fd(*(str + conv->start), 1);
			itr = conv->start + 1;
			return (-1);
		}

		// ------------------------- field
		if (*(str + itr) == '*')
		{
			conv->ast_field = TRUE;
			itr++;
		}
		else
			while (ft_isdigit(*(str + itr)))
			{
				conv->field *= 10;
				conv->field += *(str + itr) - '0';
				itr++;
			}
		// ------------------------- precision
		if (*(str + itr) == '.')
		{
			itr++;
			if (*(str + itr) == '*')
			{
				conv->ast_precision = TRUE;
				itr++;
			}
			else
				while (ft_isdigit(*(str + itr)))
				{
					conv->precision *= 10;
					conv->precision += *(str + itr) - '0';
					itr++;
				}
		}
		// ------------------------- cnv_specifer
		if (ft_strchr(CNV, *(str + itr)))
		{
			conv->conv_char = *(str + itr);
			itr++;
		}
		else
		{
			ft_putchar_fd(*(str + conv->start), 1);
			itr = conv->start + 1;
			return (itr);
		}
		return (itr);
}


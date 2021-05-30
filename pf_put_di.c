/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:49:57 by treo              #+#    #+#             */
/*   Updated: 2021/05/30 13:30:03 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_put_space(t_conv_str *conv)
{
		if (conv->field > 0)
			while (conv->field-- > 0)
				ft_putchar_fd(' ', 1);
		return (0);
}

static int	pf_put_num(t_conv_str *conv, int num, char *str)
{
		// マイナス
		if (num < 0)
			ft_putchar_fd('-', 1);
		// 0埋め
		if (conv->precision > 0)
			while (conv->precision-- > 0)
				ft_putchar_fd('0', 1);
		// 数字部分の出力
		if (num < 0)
			ft_putstr_fd(str + 1, 1);
		else
			ft_putstr_fd(str, 1);
		return (0);
} 

void	pf_put_di(va_list args, t_conv_str *conv)
{
	int		num;
	char	*str;
	int		len;

	num = va_arg(args, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (num < 0)
		conv->precision -= len - 1;
	else
		conv->precision -= len;

	if (conv->precision > 0)
		conv->field -= len + conv->precision;
	else
		conv->field -= len;

	if (conv->flag[FLAG_MYNUS])
	{
		pf_put_num(conv, num, str);
		pf_put_space(conv);
	}
	else
	{
		pf_put_space(conv);
		pf_put_num(conv, num, str);
	}
	free(str);
}

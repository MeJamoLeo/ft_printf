/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:22 by treo              #+#    #+#             */
/*   Updated: 2021/05/26 11:48:54 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_conv(va_list args, t_conv_str *conv, int itr)
{
	char *str;

	if (conv->conv_char == 'i' || conv->conv_char == 'd')
		str = ft_itoa(va_arg(args, int));


	ft_putstr_fd(str, 1);
}

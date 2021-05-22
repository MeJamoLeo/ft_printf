/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:45 by treo              #+#    #+#             */
/*   Updated: 2021/05/22 10:26:30 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (*(format + i) != '\0')
	{
		if (*(format + i) != '%')
		{
			ft_putchar_fd(*(format + i++) , 1);
			continue;
		}
	}
	return (i);
}

#ifdef TEST
#include <stdio.h>

#ifdef FT_PRINTF
	#define F(...) ft_printf(__VA_ARGS__)
#else
	#define F(...) printf(__VA_ARGS__)
#endif

int	main(void)
{
	F("abcd[%10qs]\n", "hoge");
	return (0);
}

#endif

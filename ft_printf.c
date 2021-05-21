/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:45 by treo              #+#    #+#             */
/*   Updated: 2021/05/21 13:46:37 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{

	if (format)
		return (0);
	return (0);
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
	F("hoge\n");
	return (0);
}

#endif

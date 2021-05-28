/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:18:48 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 10:22:36 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_string(char *dst, unsigned int n, unsigned int s_len)
{
	while (n >= 10)
	{
		*(dst + (s_len--) - 1) = (char)((n % 10) + '0');
		n /= 10;
	}
	*(dst + s_len - 1) = n + '0';
	*(dst + ft_strlen(dst)) = '\0';
	return (dst);
}

static int	digit_count(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int ui)
{
	int		s_len;
	int		tmp;
	char	*ptr;

	s_len = 0;
	tmp = ui;
	s_len += digit_count(tmp);
	ptr = malloc(sizeof(char) * s_len + 1);
	if (!ptr)
		return (NULL);
	fill_string(ptr, ui, s_len);
	return (ptr);
}

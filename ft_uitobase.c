/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:20:36 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 11:13:12 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	powered(unsigned int target, unsigned int base)
{
	int		count;

	count = 1;
	while (base < target)
	{
		target = target / base;
		count++;
	}
	return (count);
}

char	*ft_uitobase(unsigned int num, char *base)
{
	char	*ans;
	int		ans_len;
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	ans_len = powered(num, (unsigned int)base_len);
	ans = malloc(sizeof(char) * ans_len + 1);
	if (!ans)
		return (NULL);
	ans[ans_len] = '\0';
	i = 0;
	while (ans_len)
	{
		ans[ans_len - 1] = base[num % base_len];
		num /= base_len;
		ans_len--;
	}
	return (ans);
}

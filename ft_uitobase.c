/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:20:36 by treo              #+#    #+#             */
/*   Updated: 2021/05/28 12:33:29 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	powered(unsigned int target, unsigned int base)
{
	int		count;

	count = 1;
	while (base <= target)
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

	base_len = ft_strlen(base);
	ans_len = powered(num, (unsigned int)base_len);
	ans = malloc(sizeof(char) * ans_len + 1);
	if (!ans)
		return (NULL);
	ans[ans_len] = '\0';
	while (ans_len)
	{
		ans[ans_len - 1] = base[num % base_len];
		num /= base_len;
		ans_len--;
	}
	return (ans);
}

static int	ul_powered(unsigned long target, unsigned int base)
{
	int		count;

	count = 1;
	while (base <= target)
	{
		target = target / base;
		count++;
	}
	return (count);
}
char	*ft_ultobase(unsigned long num, char *base)
{
	char	*ans;
	int		ans_len;
	int		base_len;

	base_len = ft_strlen(base);
	ans_len = ul_powered(num, (unsigned long)base_len);
	ans = malloc(sizeof(char) * ans_len + 1);
	if (!ans)
		return (NULL);
	ans[ans_len] = '\0';
	while (ans_len)
	{
		ans[ans_len - 1] = base[num % base_len];
		num /= base_len;
		ans_len--;
	}
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:07:09 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/01 15:47:25 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_size(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*convert(char *str, long n, size_t size)
{
	size_t	stop;

	stop = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		stop = 1;
	}
	str[size] = '\0';
	while (size > stop)
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*str;
	long	num;

	num = (long)n;
	n_len = num_size(num);
	str = malloc(n_len + 1);
	if (!str)
		return (NULL);
	str = convert(str, num, n_len);
	return (str);
}

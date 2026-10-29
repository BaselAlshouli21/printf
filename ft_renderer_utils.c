/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 01:25:26 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buff(t_data *data, const char *str, size_t len)
{
	while (*str && len-- > 0)
		data->bytes_written += write(1, str++, 1);
}

void	justify(t_data *data, size_t len)
{
	size_t	width;

	width = data->format.width_value;
	if (width <= len)
		return ;
	while ((size_t)data->format.width_value-- > len)
		write_buff(data, " ", 1);
}

static size_t	num_size(unsigned long num, t_base base)
{
	size_t	n;

	n = 0;
	if (num <= 0)
		n = 1;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		n += 1;
		num /= base;
	}
	return (n);
}

char	*itoa_base(unsigned long n, const char *digits)
{
	size_t	base;
	size_t	len;
	char	*str;

	base = ft_strlen(digits);
	len = num_size(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[n % base];
		n /= base;
	}
	return (str);
}
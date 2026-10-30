/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 14:46:49 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	justify(t_data *data, size_t len, int zero_pad)
{
	size_t	width;
	char	c;

	width = data->format.width_value;
	if (zero_pad)
		c = '0';
	else
		c = ' ';
	if (width <= len)
		return ;
	while ((size_t)data->format.width_value-- > len)
		write_buff(data, &c, 1);
}

int	render_precision(t_data *data, size_t len)
{
	int i;

	i = 0;
	if (data->format.precision_value < 0)
		return (i);
	while (data->format.width_value-- >= len)
	{
		write_buff(data, "0", 1);
		i++;
	}
	return (i);
}

void	render_sign(t_data *data, long n, int mode)
{
	if (mode == 0)
		return ;
	if (n >= 0)
		write_buff(data, "+", 1);
}

static size_t	num_size(long num, t_base base)
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
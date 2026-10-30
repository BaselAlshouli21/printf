/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 20:43:12 by basil42          ###   ########.fr       */
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

void	render_sign(t_data *data)
{
	if (data->format.is_neg)
		write_buff(data, "-", 1);
	else if (data->format.plus && !data->format.is_neg)
		write_buff(data, "+", 1);
}

size_t	num_size(t_data *data, unsigned long num, t_base base)
{
	size_t	n;

	n = 1;
	while (num > 0)
	{
		n += 1;
		num /= base;
	}
	data->format.num_size = n;
	return(n);
}

void	itoa_base(t_data *data, unsigned long n, const char *digits)
{
	size_t	base;

	base = ft_strlen(digits);
	if (n >= base)
		itoa_base(data, n / base, digits);
	data->format.num_size++;
	write_buff(data, &digits[n % base], 1);
}
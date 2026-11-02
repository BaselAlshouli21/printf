/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/02 20:16:16 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_zeros(t_data *data, size_t len)
{
	if (data->format.precision_value > (ssize_t)len)
		return (data->format.precision_value - len);
	return (0);
}

void	render_digits(t_data *data, unsigned long num, size_t len)
{
	render_precision(data, len);
	if (len)
		itoa_base(data, num, NUMS_10);
}

unsigned long get_number(t_data *data)
{
	int val;
	
	if (data->format.specifier == 'u')
	{
		data->format.plus = 0;
		data->format.space = 0;
		return (va_arg(data->ap, unsigned int));
	}
	val = va_arg(data->ap, int);
	if (val < 0)
	{
		data->format.is_neg = 1;
		return (-(long long )val);
	}
	return (val);
}

size_t	num_size(t_data *data, unsigned long num, t_base base)
{
	size_t	n;

	n = 1;
	while (num >= base)
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
	write_buff(data, &digits[n % base], 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:22:28 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/04 02:12:17 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_right(t_data *data, unsigned long num, size_t len,
		const char *base)
{
	size_t	total;

	total = len + get_zeros(data, len) + sign_size(data);
	if (data->format.zero_padding)
	{
		render_sign(data);
		render_pad(data, total, ZERO_PAD);
		render_digits(data, num, len, base);
	}
	else
	{
		render_pad(data, total, SPACE);
		render_sign(data);
		render_digits(data, num, len, base);
	}
}

void	render_decimal(t_data *data, unsigned long num)
{
	size_t	len;
	size_t	total;

	len = num_size(data, num, BASE_10);
	if (!num && data->format.precision_value == 0)
		len = 0;
	total = len + get_zeros(data, len) + sign_size(data);
	if (data->format.left_justified)
	{
		render_sign(data);
		render_digits(data, num, len, NUMS_10);
		render_pad(data, total, SPACE);
	}
	else
		render_right(data, num, len, NUMS_10);
}

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	if (data->format.left_justified)
	{
		write_buff(data, &ch, 1);
		render_pad(data, 1, SPACE);
	}
	else
	{
		render_pad(data, 1, SPACE);
		write_buff(data, &ch, 1);
	}
}

void	render_string(t_data *data, int flag)
{
	const char	*str;
	ssize_t		precision;
	size_t		str_len;

	precision = data->format.precision_value;
	if (!flag)
		str = "nill";
	else
		str = va_arg(data->ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (precision >= 0 && (size_t)precision < str_len)
		str_len = precision;
	if (data->format.left_justified)
	{
		write_buff(data, str, str_len);
		render_pad(data, str_len, SPACE);
	}
	else
	{
		render_pad(data, str_len, SPACE);
		write_buff(data, str, str_len);
	}
}

void	render_hex(t_data *data)
{
	unsigned int	num;
	size_t			len;
	size_t			total;
	char			*base;

	if (data->format.upper_hexa)
		base = UPPER_16;
	else
		base = LOWER_16;
	num = va_arg(data->ap, unsigned int);
	len = num_size(data, num, BASE_16);
	if (!num && data->format.precision_value == 0)
		len = 0;
	total = len + get_zeros(data, len) + sign_size(data);
	if (data->format.left_justified)
	{
		render_sign(data);
		render_digits(data, num, len, base);
		render_pad(data, total, SPACE);
	}
	else
		render_right(data, num, len, base);
}

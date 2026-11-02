/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:22:28 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/02 20:24:04 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_right(t_data *data, unsigned long num, size_t len,
		size_t total)
{
	if (data->format.zero_padding)
	{
		render_sign(data);
		render_pad(data, total, ZERO_PAD);
		render_digits(data, num, len);
	}
	else
	{
		render_pad(data, total, SPACE);
		render_sign(data);
		render_digits(data, num, len);
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
		render_digits(data, num, len);
		render_pad(data, total, SPACE);
	}
	else
		render_right(data, num, len, total);
}

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	if (!ch)
		ch = '\0';
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

void	render_string(t_data *data)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(data->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (data->format.precision_value >= 0)
		str_len = data->format.precision_value;
	else
		str_len = ft_strlen(str) + in(str, 0);
	if (data->format.left_justified)
	{
		write_buff(data, str, str_len);
		render_pad(data, str_len, SPACE);
	}
	else
	{
		render_pad(data, str_len, SPACE);
		write_buff(data, str, data->format.precision_value);
	}
}
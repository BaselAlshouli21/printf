/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/05 16:42:04 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_pointer(t_data *data)
{
	void	*p;
	size_t	len;
	size_t	total;

	p = va_arg(data->ap, void *);
	if (!p)
	{
		data->format.precision_value = -1;
		render_string(data, 0);
		return ;
	}
	len = num_size(data, (t_ull)p, BASE_16);
	total = len + sign_size(data) + get_zeros(data, len);
	if (data->format.left_justified)
	{
		render_sign(data);
		render_digits(data, (t_ull)p, len, LOWER_16);
		render_pad(data, total, SPACE);
	}
	else
	{
		render_pad(data, total, SPACE);
		render_sign(data);
		render_digits(data, (t_ull)p, len, LOWER_16);
	}
}

void	render_format(t_data *data)
{
	char	c;

	c = data->format.specifier;
	if (in("%%c", c))
	{
		if (c == '%')
		{
			write_buff(data, "%%", 1);
			return ;
		}
		render_char(data);
	}
	else if (c == 's')
		render_string(data, 1);
	else if (in("diu", c))
		render_decimal(data, get_number(data));
	else if (in("xX", c))
		render_hex(data);
	else if (in("p", c))
		render_pointer(data);
}

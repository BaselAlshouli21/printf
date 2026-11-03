/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/03 19:29:12 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_pointer(t_data *data)
{
	unsigned long long	p;
	size_t				total;
	size_t				len;
	void				*ptr;

	ptr = va_arg(data->ap, void *);
	p = (unsigned long long)ptr;
	if (!p)
	{
		render_string(data, 1);
		return ;
	}
	len = num_size(data, p, BASE_16);
	total = len + sign_size(data);
	if (data->format.left_justified)
	{
		render_sign(data);
		render_digits(data, p, len, LOWER_16);
		render_pad(data, total, SPACE);
	}
	else
	{
		render_pad(data, total, SPACE);
		render_sign(data);
		render_digits(data, p, len, LOWER_16);
	}
}

void	render_format(t_data *data)
{
	char				c;

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
    	render_string(data, 0);
    else if (in("diu", c))
		render_decimal(data, get_number(data));
	else if (in("xX", c))
		render_hex(data);
	else if (in("p", c))
		render_pointer(data);
}
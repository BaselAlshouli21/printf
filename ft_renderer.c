/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/03 01:57:28 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_pointer(t_data *data)
{
	unsigned long p;

	p = va_arg(data->ap, unsigned long);
	if (!p)
		render_string(data, 0);
	
		
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
    	render_string(data, 1);
    else if (in("diu", c))
		render_decimal(data, get_number(data));
	else if (in("xX", c))
		render_hex(data);
}
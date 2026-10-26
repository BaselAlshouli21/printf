/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/26 20:07:13 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	data->format.width_value--;
	if (data->format.left_justified)
	{
		insert_buff(data, &ch);
		justify(data, 1);
	}
	else
	{
		justify(data, 1);
		insert_buff(data, &ch);
	}
	printf("my_printf: [%s]\n", data->buff); // DELETE LATER
}

void	render_string(t_data *data)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(data->ap, char *);
	str_len = ft_strlen(str);
	if (data->format.left_justified)
	{
		insert_buff(data, str);
		justify(data, str_len);
	}
	else
	{
		justify(data, ft_strlen(str));
		insert_buff(data, str);
	}
	printf("my_printf: [%s]\n", data->buff);
}

void	render_decimal(t_data *data)
{
	long	n;

	n = (long)va_arg(data->ap, int);
	n_len = 
}

void	render_format(t_data *data)
{
    if (in("c%%", data->format.specifier))
    	render_char(data);
	else if (data->format.specifier == 's')
    	render_string(data);
    else if (in("diu", data->format.specifier))
	{
		if (data->format.specifier == 'u')
			render_unsigned(data);
		else
     		render_decimal(data);
	}
    // else
    // 	render_hexa(data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/27 16:49:53 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	justify(data, &ch, 1);
	printf("my_printf: [%s]\n", data->buff); // DELETE LATER
}

void	render_string(t_data *data)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(data->ap, char *);
	if (data->format.precision_value >= 0)
		justify(data, str, data->format.precision_value);
	else
	{
		str_len = ft_strlen(str);
		justify(data, str, str_len);
	}
	printf("my_printf: [%s]\n", data->buff); // DELETE LATER
}

// void	render_decimal(t_data *data)
// {
// 	long	n;

// 	n = (long)va_arg(data->ap, int);
// 	n_len = 
// }

void	render_format(t_data *data)
{
    if (in("c%%", data->format.specifier))
	{
		if (data->format.specifier == '%')
		{
			insert_buff(data, "%%", 1);
			printf("my_printf: [%s]\n", data->buff); // DELETE LATER
			return ;
		}
    	render_char(data);
	}
	else if (data->format.specifier == 's')
    	render_string(data);
    // else if (in("diu", data->format.specifier))
	// {
	// 	if (data->format.specifier == 'u')
	// 		render_unsigned(data);
	// 	else
    //  		render_decimal(data);
	// }
    // else
    // 	render_hexa(data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/29 23:08:30 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	if (data->format.left_justified)
	{
		insert_buff(data, &ch, 1);
		justify(data, 1);
	}
	else
	{
		justify(data, 1);
		insert_buff(data, &ch, 1);
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
		if (data->format.precision_value >= 0)
		{
			insert_buff(data, str, data->format.precision_value);
			justify(data, str, );
		}
	}
	else
	{
		str_len = ft_strlen(str);
		justify(data, str, str_len);
	}
	printf("my_printf: [%s]\n", data->buff); // DELETE LATER
}

// void	render_precision(t_data *data, size_t len)
// {
// 	if (data->format.hash && data->format.upper_hexa)
// 	{
// 		insert_buff(data, "0X", 2);
// 		data->format.width_value -= 2;
// 	}
// 	else if (data->format.hash)
// 	{
// 		insert_buff(data, "0x", 2);
// 		data->format.width_value -= 2;
// 	}
// 	if (data->format.precision_value < 0)
// 		return ;
// 	while (data->format.precision_value-- > len)
// 		insert_buff(data, "0", 1);
// }

// void	render_decimal(t_data *data)
// {
// 	size_t	len;
// 	long	n;
// 	char	*str;

// 	n = va_arg(data->ap, unsigned int);
// 	str = itoa_base(n, NUMS_10);
// 	len = ft_strlen(str);
// 	if (data->format.left_justified)
// 	{
// 		render_precision(data, len);
// 		justify(data, len);
// 	}
// 	else
// 	{
// 		just
// 	}
// }

void	render_format(t_data *data)
{
    if (in("%%c", data->format.specifier))
	{
		if (data->format.specifier == '%')
		{
			insert_buff(data, "%%", 1);
			printf("my_printf: [%s]\n", data->buff); // DELETE LATER
			return ;
		}
		render_char(data);
	}
	// else if (data->format.specifier == 's')
    // 	render_string(data);
    // else if (in("diu", data->format.specifier))
	// 	render_decimal(data);
}
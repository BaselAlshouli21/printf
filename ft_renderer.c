/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 17:37:46 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	if (!ch)
	{
		data->bytes_written += write(1, "\0", 1);
		return ;
	}
	if (data->format.left_justified)
	{
		write_buff(data, &ch, 1);
		justify(data, 1, SPACE);
	}
	else
	{
		justify(data, 1, SPACE);
		write_buff(data, &ch, 1);
	}
}

void	render_string(t_data *data)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(data->ap, char *);
	if (!str)
	{
		data->bytes_written += write(1, "(null)", 6);
		return ;
	}
	if (data->format.precision_value >= 0)
		str_len = data->format.precision_value;
	else
		str_len = ft_strlen(str);
	if (data->format.left_justified)
	{
		write_buff(data, str, str_len);
		justify(data, str_len, SPACE);
	}
	else
	{
		justify(data, str_len, SPACE);
		write_buff(data, str, data->format.precision_value);
	}
}



void	render_decimal(t_data *data)
{
	char	*str;
	size_t	spaces;
	size_t	zeros;
	size_t	len;
	long	n;

	n = va_arg(data->ap, unsigned int);
	str = itoa_base(n, NUMS_10);
	len = ft_strlen(str);
	if (data->format.left_justified)
	{
		render_sign(data, n, data->format.plus);
		len += render_precision(data, len) + data->format.plus;
		write_buff(data, str, len);
		justify(data, len, data->format.zero_padding);
	}
	else
	{
		zeros = (data->format.precision_value > (ssize_t)len) * (data->format.precision_value - len);
		spaces = len + data->format.plus + zeros;
		if (data->format.zero_padding)
		{
			render_sign(data, n, data->format.plus);
			justify(data, spaces, data->format.zero_padding);
			write_buff(data, str, len);
		}
		else
		{
			justify(data, spaces, data->format.zero_padding);
			render_sign(data, n, data->format.plus);
			write_buff(data, str, len);
		}
		len += render_precision(data, len);
	}
	free (str);
}

void	render_format(t_data *data)
{
    if (in("%%c", data->format.specifier))
	{
		if (data->format.specifier == '%')
		{
			write_buff(data, "%%", 1);
			printf("my_printf: [%s]\n", data->buff); // DELETE LATER
			return ;
		}
		render_char(data);
	}
	else if (data->format.specifier == 's')
    	render_string(data);
    else if (in("diu", data->format.specifier))
		render_decimal(data);
}
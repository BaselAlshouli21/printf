/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:34:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/31 00:40:27 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_char(t_data *data)
{
	char	ch;

	ch = va_arg(data->ap, int);
	if (!ch)
		ch = '\0';
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

static void	render_string(t_data *data)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(data->ap, char *);
	if (!str)
		str = "(null)";
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



static void	render_decimal(t_data *data, unsigned long num)
{
	size_t	spaces;
	size_t	zeros;
	size_t	len;

	len = num_size(data, num, BASE_10);
	if (data->format.left_justified)
	{
		render_sign(data);
		len += render_precision(data, len) + data->format.plus;
		itoa_base(data, num, NUMS_10);
		justify(data, len, data->format.zero_padding);
	}
	else
	{
		zeros = (data->format.precision_value > (ssize_t)len) * (data->format.precision_value - len);
		spaces = len + data->format.plus + zeros;
		if (data->format.zero_padding)
		{
			render_sign(data);
			justify(data, spaces, data->format.zero_padding);
			itoa_base(data, num, NUMS_10);
		}
		else
		{
			justify(data, spaces, data->format.zero_padding);
			render_sign(data);
			itoa_base(data, num, NUMS_10);
		}
		len += render_precision(data, len);
	}
}

void	render_format(t_data *data)
{
	unsigned long long	num;
	int					val;
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
    	render_string(data);
    else if (in("diu", c))
	{
		if (c == 'u')
			num = va_arg(data->ap, unsigned int);
		else
		{
			val = va_arg(data->ap, int);
			if (val < 0)
			{
				num = -(long long)val;
				data->format.is_neg = 1;
			}
			else
				num = val;
		}
		render_decimal(data, num);
	}
}
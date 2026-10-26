/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:15 by basil42           #+#    #+#             */
/*   Updated: 2026/10/26 12:02:27 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_data(t_data *data, const char *str)
{
	data->bytes_written = 0;
	data->s = str;
	data->buff = malloc(BUFFER_SIZE);
	if (!data->buff)
		return (MALLOC_ERROR);
	data->buff_idx = 0;
	ft_memset(data->buff, 0, BUFFER_SIZE);
	return (OK);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.ap, str);
	if (init_data(&data, str))
		return (-1);
	while (*data.s)
	{
		if (*(data.s) == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (PARSE_ERROR);
			render_format(&data);
		}
		//else
		//	write_buff(&data, *data.s);
		data.s++;
	}
	//flush_buff(&data);
	free(data.buff);
	va_end(data.ap);
	return (data.bytes_written);
}

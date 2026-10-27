/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:12:44 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/27 16:52:46 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_data *data)
{
	char	flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '0')
			data->format.zero_padding = 1;
		else if (flag == ' ')
			data->format.space = 1;
		else if (flag == '#')
			data->format.hash = 1;
		else if (flag == '+')
			data->format.plus = 1;
		else if (flag == '-')
			data->format.left_justified = 1;
		data->s++;
	}
}

static void	parse_width(t_data *data)
{
	int	width;

	width = parse_atoi(data);
	data->format.width_value = width;
}

static void	parse_precision(t_data *data)
{
	int	precision;

	precision = parse_atoi(data);
	data->format.precision_value = precision;
}

static int parse_sepecifier(t_data *data)
{
	if (!in(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else if (*data->s == '%')
	{
		data->format.specifier = '%';
		data->s++;
	}
	else
		data->format.specifier = *data->s++;
	return (OK);
}

int	parse_format(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	parse_width(data);
	if (*data->s == '.' && *(++data->s))
		parse_precision(data);
	if (parse_sepecifier(data))
		return (PARSE_ERROR);
	if (in("diu", data->format.specifier))
		data->format.base = BASE_10;
	else if (in("xXp", data->format.specifier))
	{
		if ('X' == data->format.specifier)
			data->format.upper_hexa = 1;
		data->format.base = BASE_16;
	}
	if (data->format.precision_value >= 0 && data->format.zero_padding)
		data->format.zero_padding = 0;
	if (data->format.space && data->format.plus)
		data->format.space = 0;
	return (OK);
}

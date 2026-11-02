/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:55:14 by basil42           #+#    #+#             */
/*   Updated: 2026/11/02 20:09:35 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	sign_size(t_data *data)
{
	return (data->format.is_neg || data->format.plus || data->format.space);
}

void	render_sign(t_data *data)
{
	if (data->format.is_neg)
		write_buff(data, "-", 1);
	else if (data->format.plus)
		write_buff(data, "+", 1);
	else if (data->format.space)
		write_buff(data, " ", 1);
}

int	render_precision(t_data *data, size_t len)
{
	int i;

	i = 0;
	if (data->format.precision_value < 0)
		return (i);
	while (data->format.precision_value-- > (ssize_t)len)
	{
		write_buff(data, "0", 1);
		i++;
	}
	return (i);
}

void	render_pad(t_data *data, size_t len, int zero_pad)
{
	size_t	width;
	char	c;

	width = data->format.width_value;
	c = ' ';
	if (zero_pad)
		c = '0';
	while (width > len)
	{
		write_buff(data, &c, 1);
		width--;
	}
}
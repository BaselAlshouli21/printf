/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:55:14 by basil42           #+#    #+#             */
/*   Updated: 2026/10/31 01:28:01 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_sign(t_data *data)
{
	size_t	*width;

	width = &data->format.width_value;
	if (data->format.is_neg)
	{
		write_buff(data, "-", 1);
		*width -= *width > 1;
	}
	else if (data->format.plus && !data->format.is_neg)
	{
		write_buff(data, "+", 1);
		*width -= *width > 1;
	}
}

int	render_precision(t_data *data, size_t len)
{
	int i;

	i = 0;
	if (data->format.precision_value < 0)
		return (i);
	while (data->format.width_value-- >= len)
	{
		write_buff(data, "0", 1);
		i++;
	}
	return (i);
}

void	render_pad(t_data *data, size_t len, int zero_pad)
{
	size_t	*width;
	char	c;

	width = &data->format.width_value;
	if (zero_pad)
		c = '0';
	else
		c = ' ';
	if (*width <= len)
		return ;
	while (*width-- > len)
		write_buff(data, &c, 1);
}
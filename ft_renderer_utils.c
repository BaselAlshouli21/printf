/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/26 17:01:11 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_size(long num)
{
	size_t	n;
	
	n = 0;
	if (num < 0)
	{
		if (num == -2147483648)
			return (10);
		num *= -1;
	}
	while (num > 0)
	{
		n += 1;
		num /= 10;
	}
	return (n);
}

void	insert_buff(t_data *data, char *str)
{
	while (*str)
	{
		data->buff[data->buff_idx++] = *str++;
	}
}

void	justify(t_data *data, size_t len)
{
	if ((size_t)data->format.width_value <= len)
	{
		return ;
	}
	while ((size_t)data->format.width_value > len)
	{
		data->format.width_value--;
		data->buff[data->buff_idx++] = ' ';
	}
}

char *itoa_base(int	num, t_base base)
{
	char	*str;
	size_t	len;
	
	len = num_size(num);
	str = malloc(num_size(num) + 1);
	if (!str)
		return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/27 16:22:09 by balshoul         ###   ########.fr       */
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

void	insert_buff(t_data *data, const char *str, size_t len)
{
	while (*str && len-- > 0)
		data->buff[data->buff_idx++] = *str++;
}

void	justify(t_data *data, const char *str, size_t len)
{
	size_t	width;

	width = data->format.width_value;
	if (width <= len)
		return ;
	if (data->format.left_justified)
	{
		insert_buff(data, str, len);
		width -= len;
		while (width-- > 0)
			insert_buff(data, " ", 1);
	}
	else
	{
		while (width-- > len)
			insert_buff(data, " ", 1);
		insert_buff(data, str, len);
	}
	data->format.width_value -= width;
}

// char *itoa_base(int	num, t_base base)
// {
// 	char	*str;
// 	size_t	len;
	
// 	len = num_size(num);
// 	str = malloc(num_size(num) + 1);
// 	if (!str)
// 		return (NULL);
// }
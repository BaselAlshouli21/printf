/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/29 02:13:26 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


static size_t	num_size(unsigned long n, t_base base)
{
	size_t	n;

	n = 0;
	if (n <= 0)
		n = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n += 1;
		n /= base;
	}
	return (n);
}

char	*itoa_base(unsigned long n, const char *digits)
{
	size_t	base;
	size_t	len;
	char	*str;

	base = ft_strlen(digits);
	len = num_size(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[n % base];
		n /= base;
	}
	return (str);
}
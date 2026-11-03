/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:13:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/02 22:30:30 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

size_t	parse_atoi(t_data *data)
{
	size_t	num;

	num = 0;
	while (ft_isdigit(*data->s))
	{
		num *= 10;
		num += *data->s - '0';
		data->s++;
	}
	return (num);
}

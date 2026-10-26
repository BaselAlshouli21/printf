/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:13:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/26 12:11:22 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in(const char *str, int c)
{
	unsigned char	ch;

	ch = c;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	parse_atoi(t_data *data)
{
	int	num;

	num = 0;
	while (ft_isdigit(*data->s))
	{
		num *= 10;
		num += *data->s - '0';
		data->s++;
	}
	return (num);
}

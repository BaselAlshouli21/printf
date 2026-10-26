/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:13:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/26 11:28:53 by balshoul         ###   ########.fr       */
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
	int	iter;

	num = 0;
	iter = 0;
	while (ft_isdigit(*data->s))
	{
		num += (iter * 10);
		num += *data->s - '0';
		data->s++;
	}
	return (num);
}

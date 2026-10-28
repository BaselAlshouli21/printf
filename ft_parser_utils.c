/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:13:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/28 22:35:24 by basil42          ###   ########.fr       */
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

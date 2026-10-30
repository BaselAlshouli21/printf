/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/31 01:08:43 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_size(t_data *data, unsigned long num, t_base base)
{
	size_t	n;

	n = 1;
	while (num >= base)
	{
		n += 1;
		num /= base;
	}
	data->format.num_size = n;
	return(n);
}

void	itoa_base(t_data *data, unsigned long n, const char *digits)
{
	size_t	base;

	base = ft_strlen(digits);
	if (n >= base)
		itoa_base(data, n / base, digits);
	write_buff(data, &digits[n % base], 1);
}
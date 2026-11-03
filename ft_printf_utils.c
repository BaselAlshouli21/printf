/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:06:36 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/03 22:09:45 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buff(t_data *data, const char *str, size_t len)
{
	ssize_t	ret;

	ret = write(1, str, len);
	if (ret > 0)
		data->bytes_written += ret;
}

void	fix_flags(t_data *data)
{
	t_format	*f;

	f = &data->format;
	if (!in("xX", f->specifier))
		f->hash = 0;
	if (!in("di", f->specifier))
	{
		f->plus = 0;
		f->space = 0;
	}
	if (!in("diuxXs", f->specifier))
		f->precision_value = -1;
	if (f->precision_value >= 0 || f->left_justified
		|| !in("diuxXp", f->specifier))
		f->zero_padding = 0;
	if (f->plus)
		f->space = 0;
}
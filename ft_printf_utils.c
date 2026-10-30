/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:06:36 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 20:58:57 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buff(t_data *data, const char *str, size_t len)
{
	if (len == 1 && !*str)
		data->bytes_written += write(1, "\0", 1);
	while (*str && len-- > 0)
		data->bytes_written += write(1, str++, 1);
}
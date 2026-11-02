/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:06:36 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/02 22:56:57 by balshoul         ###   ########.fr       */
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
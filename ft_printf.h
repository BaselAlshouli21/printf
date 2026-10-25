/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:59 by basil42           #+#    #+#             */
/*   Updated: 2026/10/25 22:19:25 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_format
{
	// flags
	int		hash;
	int		space;
	int		zero_padding;
	int		plus;
	int		left_justified;

	// "cspdiuxX%"
	char	specifier;

	// with + precision
	int		width_value;
	int		precision_value;
}				t_format;

typedef struct s_data
{
	// copy to the original string
	const char	*s;

	// va_list to immediatly get the next arg
	va_list		ap;

	// the flags
	t_format	format;

	// the bytes that the printf has written
	int			bytes_written;
}				t_data;

int	ft_printf(const char *format, ...);

#endif
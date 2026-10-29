/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:59 by basil42           #+#    #+#             */
/*   Updated: 2026/10/29 23:25:18 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define BUFFER_SIZE 4096

# define FLAGS "# 0+-"
# define NUMS_10 "0123456789"
# define LOWER_16 "0123456789abcdef"
# define UPPER_16 "0123456789ABCDEF"
# define SPECIFIERS "cspdiuxX%%"

typedef enum e_error
{
	OK = 0,
	RENDER_ERROR = -100,
	MALLOC_ERROR = -10,
	PARSE_ERROR = -1,
}			t_error;

typedef enum e_base
{
	BASE_10 = 10,
	BASE_16 = 16,
}			t_base;

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

	// Useful data
	int		upper_hexa;
	t_base	base;
}				t_format;

typedef struct s_data
{
	// copy to the original string
	const char	*s;

	// va_list to immediatly get the next arg
	va_list		ap;

	// the flags struct
	t_format	format;

	// the bytes that the printf has written
	int			bytes_written;

	// The Huge Buffer and it's cursor;
	char		*buff;
	int			buff_idx;
}				t_data;

// printf.c
int	ft_printf(const char *str, ...);

// parser
int	parse_format(t_data *data);

// parser utils
int	in(const char *str, int c);
int	parse_atoi(t_data *data);

// renderer
void	render_format(t_data *data);
void	render_char(t_data *data);

// renderer utils
void	write_buff(t_data *data, const char *str, size_t len);
void	justify(t_data *data, size_t len);
char	*itoa_base(unsigned long n, const char *digits);

// DELETE LATER
void	print_struct(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:59 by basil42           #+#    #+#             */
/*   Updated: 2026/11/03 00:29:55 by balshoul         ###   ########.fr       */
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

# define ZERO_PAD 1
# define SPACE 0

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
	size_t	width_value;
	ssize_t	precision_value;

	// Useful data
	int		upper_hexa;
	int		is_neg;
	t_base	base;
	size_t	num_size;
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
}				t_data;

// printf.c
int	ft_printf(const char *str, ...);

// printf utils
void	write_buff(t_data *data, const char *str, size_t len);

// parser
int	parse_format(t_data *data);

// parser utils
size_t	parse_atoi(t_data *data);
int	in(const char *str, int c);

// renderer
void	render_format(t_data *data);

// renderer utils
unsigned long get_number(t_data *data);
size_t	get_zeros(t_data *data, size_t len);
size_t	num_size(t_data *data, unsigned long num, t_base base);
void	itoa_base(t_data *data, unsigned long n, const char *digits);
void	render_digits(t_data *data, unsigned long num, size_t len, const char *base);

// render flags
size_t	sign_size(t_data *data);
void	render_sign(t_data *data);
void	render_pad(t_data *data, size_t len, int zero_pad);
void	render_sign(t_data *data);
int		render_precision(t_data *data, size_t len);

// render specifiers
void	render_decimal(t_data *data, unsigned long num);
void	render_string(t_data *data, int flag);
void	render_char(t_data *data);
void	render_hex(t_data *data);

// DELETE LATER
void	print_struct(t_data *data);

#endif
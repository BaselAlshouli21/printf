/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:54:14 by basil42           #+#    #+#             */
/*   Updated: 2026/10/25 22:23:22 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

double	average(int count, ...)
{
	va_list	ap;
	double	total;
	int		i;

	i = 0;
	total = 0;
	va_start(ap, count);
	while (i++ < count)
		total += va_arg(ap, double);
	return (total / count);
}

int	main()
{
	int	bytes;

	// printf("unsigned max: %u\n", UINT_MAX);
	bytes = printf("[%+ 03d]\n", 2);
	printf("bytes written: %d", bytes);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:45:34 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/30 14:21:19 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_struct(t_data *data)
{
	printf("s: %s\n", data->s);
	printf("%s", "the combination of flags, width, and precision: ");
	if (data->format.hash)
		printf("%s", "[#]");
	if (data->format.left_justified)
		printf("%s", "[-]");
	if (data->format.plus)
		printf("%s", "[+]");
	if (data->format.space)
		printf("%s", "[ ]");
	if (data->format.zero_padding)
		printf("%s", "[0]");
	if (data->format.width_value)
		printf("\nWidth: %ld", data->format.width_value);
	if (data->format.precision_value >= 0)
		printf("\nPrecision: .%ld", data->format.precision_value);
	if (in("iduxXp", data->format.specifier))
		printf("\nBase: %d", data->format.base);
}
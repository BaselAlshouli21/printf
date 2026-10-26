/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/26 12:16:44 by balshoul         ###   ########.fr       */
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
    	printf("\nWidth: %d", data->format.width_value);
    if (data->format.width_value >= 0)
    	printf("\nPrecision: .%d", data->format.precision_value);
    if (in("iduxXp", data->format.specifier))
    	printf("\nBase: %d", data->format.base);
}

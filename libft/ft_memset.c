/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:22:46 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/05 15:01:30 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	ch = c;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = ch;
		i++;
	}
	return (s);
}

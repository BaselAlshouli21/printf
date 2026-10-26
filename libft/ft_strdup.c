/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:16:03 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/10 14:24:53 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*ds;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	ds = malloc(size + 1);
	if (!ds)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ds[i] = s[i];
		i++;
	}
	ds[i] = 0;
	return (ds);
}

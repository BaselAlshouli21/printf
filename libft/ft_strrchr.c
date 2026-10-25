/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:23:57 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/05 16:51:16 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i] != 0)
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

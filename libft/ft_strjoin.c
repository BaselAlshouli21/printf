/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:57:26 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/05 16:45:47 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	char	*ptr;

	if (!s1 || !s2)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ptr = str;
	ft_memcpy(ptr, s1, s1_len);
	ptr += s1_len;
	ft_memcpy(ptr, s2, s2_len);
	ptr += s2_len;
	*ptr = 0;
	return (str);
}

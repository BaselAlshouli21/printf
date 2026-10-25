/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:17:51 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/03 00:22:26 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*llist;

	llist = malloc(sizeof(t_list));
	if (!llist)
		return (NULL);
	llist->content = content;
	llist->next = NULL;
	return (llist);
}

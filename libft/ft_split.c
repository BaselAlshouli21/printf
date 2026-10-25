/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:27:49 by balshoul          #+#    #+#             */
/*   Updated: 2026/10/05 17:00:14 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_word;

	if (!s)
		return (0);
	in_word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

static char	**fill_array(char **arr, const char *s, char c, size_t count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (i < count)
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		arr[i] = ft_substr(s, start, end - start);
		if (!arr[i])
		{
			free_all(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**str_arr;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!str_arr)
		return (NULL);
	str_arr[words_count] = NULL;
	str_arr = fill_array(str_arr, s, c, words_count);
	if (!str_arr)
		return (NULL);
	return (str_arr);
}

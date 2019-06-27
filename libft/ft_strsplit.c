/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:47:30 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 03:47:32 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_of_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void		free_arr(char ***arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (*(*arr + i))
		ft_strdel(*arr + i++);
	free(*arr);
	*arr = NULL;
}

static void		split_str_to_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			arr[j++] = ft_strsub(s, i, len);
			if (arr[j - 1] == NULL)
			{
				free_arr(&arr);
				return ;
			}
			i += len;
		}
	}
	arr[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = count_of_word(s, c);
	res = (char **)malloc(sizeof(char *) * size + 1);
	if (res == NULL)
		return (NULL);
	split_str_to_arr(res, s, c);
	return (res);
}

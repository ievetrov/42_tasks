/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:48:06 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:10:14 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		s++;
	while (s[i] != '\0')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	str = (char*)malloc(sizeof(*str) * (i + 2));
	if (str == NULL)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:45:41 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:30:26 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	n;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		str[i] = f(n, s[i]);
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}

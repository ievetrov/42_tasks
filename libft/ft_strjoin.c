/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:44:07 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:31:59 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	len = 0;
	if (s1 != NULL)
		len += ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	if (len + 1 == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (s1 != NULL)
		str = ft_strcat(str, s1);
	if (s2 != NULL)
		str = ft_strcat(str, s2);
	return (str);
}

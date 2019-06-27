/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:38:04 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:54:33 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	symbol;
	char	*s1;
	char	*s2;
	size_t	i;

	symbol = (char)c;
	s1 = (char *)src;
	s2 = (char *)dst;
	i = 0;
	while (n > 0)
	{
		if (s1[i] == symbol)
		{
			s2[i] = s1[i];
			return (dst + i + 1);
		}
		else
			s2[i] = s1[i];
		i++;
		n--;
	}
	return (0);
}

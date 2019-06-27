/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:38:51 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:45:55 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (dst == src)
		return (dst);
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dst);
}

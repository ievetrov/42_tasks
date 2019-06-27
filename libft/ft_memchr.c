/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:38:17 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:45:29 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == symb)
			return (str + i);
		i++;
		n--;
	}
	return (0);
}

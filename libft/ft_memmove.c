/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:39:14 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:44:13 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buf;
	size_t	i;

	buf = malloc(len);
	if (buf == NULL)
		return (dst);
	i = 0;
	while (i < len)
	{
		*(((unsigned char *)buf) + i) = *(((unsigned char *)src) + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(((unsigned char *)dst) + i) = *(((unsigned char *)buf) + i);
		i++;
	}
	free(buf);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:39:25 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:44:40 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symb;
	char			*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = symb;
		i++;
	}
	return (b);
}

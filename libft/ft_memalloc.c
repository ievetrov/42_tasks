/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:37:53 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:56:34 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*str;
	size_t		i;

	i = 0;
	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char*)str)[i] = 0;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:46:58 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 13:28:01 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	if (size + 1 == 0)
		return (NULL);
	res = (char*)malloc(sizeof(*res) * size + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		res[i] = '\0';
	return (res);
}

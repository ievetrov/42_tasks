/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:46:16 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:29:37 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:36:33 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 03:36:36 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = get_size(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	i = len - 1;
	while (n && i >= 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	str[len] = '\0';
	return (str);
}

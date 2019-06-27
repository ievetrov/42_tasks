/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:40:22 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:42:54 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr(n / 10 * -1);
		c = n % 10 * -1 + '0';
		ft_putchar(c);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		ft_putchar(c);
	}
	else
	{
		c = n + '0';
		ft_putchar(c);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:34:58 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 05:04:41 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	tmp;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '0' || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1 + (i++) * 0;
	else if (str[i] == '+')
		sign = 1 + (i++) * 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[i++] - '0') * sign;
		if (tmp < 0 && res > tmp)
			return (0);
		if (tmp > 0 && res < tmp)
			return (-1);
	}
	return (res);
}

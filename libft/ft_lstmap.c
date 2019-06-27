/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:37:36 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 04:58:47 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	**ptr;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = &list;
	while (lst)
	{
		*ptr = f(lst);
		if (*ptr == NULL)
			return (NULL);
		ptr = &(*ptr)->next;
		lst = lst->next;
	}
	return (list);
}

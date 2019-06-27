/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgalbart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:37:04 by wgalbart          #+#    #+#             */
/*   Updated: 2019/04/28 05:00:03 by wgalbart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*list;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	*alst = NULL;
}

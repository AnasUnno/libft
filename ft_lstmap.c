/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:16:49 by araji-af          #+#    #+#             */
/*   Updated: 2022/10/25 22:47:24 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mynode;
	t_list	*mylist;

	if (!lst || !del || !f)
		return (NULL);
	mylist = NULL;
	while (lst)
	{
		mynode = ft_lstnew(f(lst->content));
		if (mynode == NULL)
		{
			ft_lstclear(&mylist, del);
			return (NULL);
		}
		ft_lstadd_back(&mylist, mynode);
		lst = lst->next;
	}
	return (mylist);
}

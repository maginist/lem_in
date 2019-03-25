/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:57:04 by maginist          #+#    #+#             */
/*   Updated: 2018/11/19 11:28:49 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;
	t_list	*current;

	if (!(lst && f))
		return (0);
	if (!(first = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	tmp = first;
	lst = lst->next;
	while (lst)
	{
		if (!(current = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		tmp->next = current;
		tmp = current;
		lst = lst->next;
	}
	return (first);
}

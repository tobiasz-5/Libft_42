/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:19:34 by tschetti          #+#    #+#             */
/*   Updated: 2023/12/06 19:23:51 by tschetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	start(t_list **lst, t_list **nl, t_list **nh, void *(*f)(void *))
{
	(*nl)->content = f((*lst)->content);
	(*nl)->next = NULL;
	*nh = *nl;
	*lst = (*lst)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_head;
	t_list	*n_lst;

	if (lst == NULL)
		return (NULL);
	n_lst = malloc(sizeof(t_list));
	if (n_lst == NULL)
		return (NULL);
	start(&lst, &n_lst, &n_head, f);
	while (lst != NULL)
	{
		n_lst->next = malloc(sizeof(t_list));
		if (n_lst->next == NULL)
		{
			ft_lstclear(&n_head, del);
			return (NULL);
		}
		n_lst = n_lst->next;
		n_lst->content = f(lst->content);
		n_lst->next = NULL;
		lst = lst->next;
	}
	return (n_head);
}

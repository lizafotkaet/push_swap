/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dll_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:37:32 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/06 14:22:35 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dnew_node(int number)
{
	t_dlist	*lst;

	lst = malloc(sizeof(t_dlist));
	if (lst == NULL)
		return (NULL);
	lst->number = number;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_dlist	*ft_dlsthead(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

t_dlist	*ft_lst_nexttolast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != 0)
		lst = lst->next;
	return(lst);
}

size_t	ft_dlstsize(t_dlist *lst)
{
	size_t	len;

	len = 0;
	while (lst != 0)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
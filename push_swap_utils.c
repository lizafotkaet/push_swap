/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:03 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/03 13:51:33 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_dlist *lst)
{
	while(lst)
	{
		ft_printf("%d\n", lst->number);
		lst = lst->next;
	}
}

bool	sorted_check(t_dlist	*lst)
{
	t_dlist	*head;
	int		current_nbr;

	if (!lst)
		return (true);
	head = lst;
	current_nbr = lst->number;
	while(lst && lst->next)
	{
		lst = lst->next;
		if (current_nbr > lst->number)
			return (false);
		current_nbr = lst->number;
	}
	lst = head;
	return (true);
}

void	free_lst(t_dlist **lst)
{
	t_dlist	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:24:59 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:45 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next; // storing the pointer to the next node before yeeting it
		del((*lst)->content);
		free(*lst); // freeing the node AFTER we put the pointer to the next node in temp, 
						// otherwise if we free the node before storing the pointer in temp
						// we'll lose the pointer (we free THE WHOLE)
		*lst = temp; // basically *lst = (*lst)->next but see the previous comment
	}
	*lst = NULL;
}

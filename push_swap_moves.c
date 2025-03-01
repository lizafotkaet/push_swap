/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:54 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/25 17:13:11 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_lst(t_list *head)
{
	t_list	*first;
	t_list	*second;
	int		temp;
	
	if (!head || !head->next)
		return ;
	first = head;
	second = head->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	push_lst(t_list **head_a, t_list **head_b)
{
	t_list	*temp_ptr;
	
	if (!head_b) // !!!!!!!!????? what if there's only one element in b
		return ;
	temp_ptr = (*head_b)->next; // pointer to now second element of stack b (to be the first element of stack b)
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = temp_ptr;
}

void	rotate_lst(t_list **head)
{
	t_list	*new_head;
	t_list	*temp_old_head; 
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	temp_old_head = *head;
	new_head = (*head)->next; // the current second element of the stack eventually becomes the first element, i.e. the new head
	last = ft_lstlast(*head); // currently last == NULL, we need it to point to the OG head which is stored in temp_head now
	last->next = temp_old_head; // now the last element points not to nothing but to the old head (cause it's the last element now)
	temp_old_head->next = NULL; // the old head is now the last element so it points to nothing
	*head = new_head; // update the OG list head
}

void	reverse_rotate_lst(t_list **head)
{
	t_list	*next_to_last;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	next_to_last = ft_lst_nexttolast(*head); // first we get to the second to last node
	last = ft_lstlast(*head); // then to the last node
	next_to_last->next = NULL; // the second to last node now puts to nothing (cause bc of reverse rotating it's the last element now)
	last->next = *head; // the pointer of the last element initially was NULL (cause it's last, points to nothing) now it points to the current head (the initial first node), basically we put the OG head pointer "inside" the first node and it points to the new second element now, not first
	*head = last; // the head pointer points to the last element now cause we moved it up and it's not last but first now YAAAAAAAAAY
}

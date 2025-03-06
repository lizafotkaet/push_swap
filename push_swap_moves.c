/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:54 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/04 17:42:06 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_lst(t_dlist *head)
{
	t_dlist	*first;
	t_dlist	*second;
	int		temp;
	
	if (!head || !head->next)
		return ;
	first = head;
	second = head->next;
	temp = first->number;
	first->number = second->number;
	second->number = temp;
}

void	push_lst(t_dlist **head_a, t_dlist **head_b)
{
	t_dlist	*temp_next_ptr;
	
	if (!*head_a) // if there's nothing in stack a
		return ;
	temp_next_ptr = (*head_a)->next; // storing the new stack a head
	if (*head_b)
		(*head_b)->prev = *head_a; // if stack b isn't empty
	(*head_a)->next = *head_b; // the pushed element points to the old head (now second element) of stack b 
	*head_b = *head_a; // new stack b head
	*head_a = temp_next_ptr; // new stack a head
	// (*head_a)->prev = NULL; // new stack had has to point to nothing now (it used to point to the old stack a head)
}

void	rotate_lst(t_dlist **head)
{
	t_dlist	*new_head;
	t_dlist	*temp_old_head; 
	t_dlist	*last;

	if (!*head || !(*head)->next)
		return ;
	temp_old_head = *head;
	new_head = (*head)->next; // the current second element of the stack eventually becomes the first element, i.e. the new head
	new_head->prev = NULL; // ONE POINTER
	last = ft_dlstlast(*head); // currently last == NULL, we need it to point to the OG head which is stored in temp_head now
	last->next = temp_old_head; // now the last element points not to nothing but to the old head (cause it's the last element now)
	(*head)->prev = last; //
	temp_old_head->next = NULL; // the old head is now the last element so it points to nothing
	*head = new_head; // update the OG list head
}

void	reverse_rotate_lst(t_dlist **head)
{
	t_dlist	*new_last;
	t_dlist	*last;

	if (!*head || !(*head)->next)
		return ;
	new_last = ft_lst_nexttolast(*head); // first we get to the second to last node (new last node)
	last = ft_dlstlast(*head); // then to the last node
	new_last->next = NULL; // the second to last node now puts to nothing (cause bc of reverse rotating it's the last element now)
	last->next = *head; // the pointer of the last element initially was NULL (cause it's last, points to nothing) now it points to the current head (the initial first node), basically we put the OG head pointer "inside" the first node and it points to the new second element now, not first
	(*head)->prev = last;
	last->prev = NULL;
	*head = last; // the head pointer points to the last element now cause we moved it up and it's not last but first now YAAAAAAAAAY
}

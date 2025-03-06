/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:12 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/04 17:43:10 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct d_list
{
	struct d_list	*prev;
	int				number;
	struct d_list	*next;
}	t_dlist;

t_dlist	*ft_lst_nexttolast(t_dlist *lst);
void	arg_check(char **argv);
void	duplicates_check(t_dlist *lst, int nbr);
bool	is_valid_number(const char *str);
t_dlist	*put_lst(char **argv, int argc, t_dlist *stack_a);
void	print_lst(t_dlist *lst);
bool	sorted_check(t_dlist	*lst);
void	free_lst(t_dlist **lst);
t_dlist	*ft_dnew_node(int number);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlsthead(t_dlist *lst);
void	swap_lst(t_dlist *head);
void	put_nodes(t_dlist **new_node, t_dlist **head, t_dlist **stack_a);

void	swap_lst(t_dlist *head);
void	push_lst(t_dlist **head_a, t_dlist **head_b);
void	rotate_lst(t_dlist **head);
void	reverse_rotate_lst(t_dlist **head);
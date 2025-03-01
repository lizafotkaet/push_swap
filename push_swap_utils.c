/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:03 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/01 11:29:33 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_nexttolast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != 0)
		lst = lst->next;
	return(lst);
}

void	print_lst(t_list *lst)
{
	while(lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}
bool	is_valid_number(const char *str) 
{
	if (*str == '+' || *str == '-')
	    str++;
	if (*str == '\0')
	    return (false);
	while (*str) 
	{
	    if (*str < '0' || *str > '9')
	        return (false);
	    str++;
	}
    return (true);
}

void	duplicates_check(t_list *lst, int nbr)
{
	while(lst)
	{
		if (nbr == lst->content)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		lst = lst->next;
	}
}

void	arg_check(char **argv)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]) == false)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ft_atoi(argv[i], &error);
		if (error)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:05:51 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 17:41:48 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_or_b(t_list **list, char *str)
{
	t_list	*temp;

	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = (*list);
	(*list) = temp;
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_swap_ss(t_list **list1, t_list **list2, char *str)
{
	ft_swap_a_or_b(list1, NULL);
	ft_swap_a_or_b(list2, NULL);
	write(1, str, ft_strlen(str));
}

void	ft_push_a(t_list **list1, t_list **list2)
{
	t_list	*elem;

	elem = *list2;
	(*list2) = (*list2)->next;
	elem->next = (*list1);
	(*list1) = elem;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **list1, t_list **list2)
{
	t_list	*elem;

	elem = (*list1);
	(*list1) = (*list1)->next;
	elem->next = (*list2);
	(*list2) = elem;
	write(1, "pb\n", 3);
}

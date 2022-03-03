/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_stack2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:38:51 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 18:19:00 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a_or_b(t_list **list, char *str)
{
	t_list	*newhead;
	t_list	*lastlist;

	newhead = (*list)->next;
	lastlist = ft_lstlast(*list);
	lastlist->next = *list;
	(*list)->next = NULL;
	*list = newhead;
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_rotate_rr(t_list **list1, t_list **list2)
{
	ft_rotate_a_or_b(list1, NULL);
	ft_rotate_a_or_b(list2, NULL);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_a_or_b(t_list **list, char *str)
{
	t_list	*temp;
	t_list	*lastlist;

	lastlist = ft_lstlast(*list);
	temp = (*list);
	while (temp ->next->next)
		temp = temp->next;
	lastlist->next = (*list);
	(*list) = lastlist;
	temp->next = NULL;
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_reverse_rotate_rr(t_list **list1, t_list **list2)
{
	ft_reverse_rotate_a_or_b(list1, NULL);
	ft_reverse_rotate_a_or_b(list2, NULL);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:05:51 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 01:22:34 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **list)
{
	t_list	*lst2;

	lst2 = (*list)->next;
	(*list)->next = lst2->next;
	lst2->next = (*list);
	(*list) = lst2;
	write(1, "sa\n", 3);
}

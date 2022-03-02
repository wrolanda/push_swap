/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:22:53 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 01:24:46 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*lst1;

	lst1 = *lst;
	if (!lst1)
		return (0);
	i = 1;
	while (lst1->next != NULL)
	{
		lst1 = lst1->next;
		i++;
	}
	return (i);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	if (size == 2)
		ft_swap_a(stack_a);
	ft_print_stack(stack_a);
	/*else if (size == 3)
		ft_sort_3(stack_a);
	else if (size < 6)
		ft_sort_5(stack_a, stack_b, size);
	else
		ft_sort(stack_a, stack_b, size);*/
}

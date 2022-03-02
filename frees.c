/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:49:27 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/02 18:04:06 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_memory_split(char **array, int x)
{
	while (x >= 0)
	{
		free(array[x]);
		x--;
	}
	free(array);
}

void	ft_free_memory_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*next2;

	while (*stack_a)
	{
		next2 = (*stack_a)->next;
		free (*stack_a);
		*stack_a = next2;
	}
	if (stack_b != NULL)
	{
		while (*stack_b)
		{
			next2 = (*stack_b)->next;
			free(*stack_b);
			*stack_b = next2;
		}
	}
	exit(1);
}

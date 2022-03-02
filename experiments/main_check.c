/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:07:41 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 00:16:28 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_list **stack)
{
	t_list	*stack2;

	stack2 = *stack;
	while (stack2)
	{
		printf("%d\n", stack2->value);
		stack2 = stack2->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:07:41 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 18:06:30 by wrolanda         ###   ########.fr       */
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

void	ft_print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack2;

	if (*stack_a)
	{
		stack2 = *stack_a;
		printf("stack a:\n");
		while (stack2)
		{
			printf("%d\n", stack2->value);
			stack2 = stack2->next;
		}
		printf("\n");
	}
	else
		printf("stack a = NULL:\n\n");
	if (*stack_b)
	{
		stack2 = *stack_b;
		printf("stack b:\n");
		while (stack2)
		{
			printf("%d\n", stack2->value);
			stack2 = stack2->next;
		}
		printf("\n");
	}
	else
		printf("stack b = NULL:\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:45:58 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 18:07:48 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(1);
	ft_check_valid_argv_0(argv);
	ft_push_data_on_stack(&stack_a, argv);
		ft_print_stacks(&stack_a, &stack_b);
	ft_check_double_sort(&stack_a);
	ft_push_swap(&stack_a, &stack_b);
	ft_free_memory_stacks(&stack_a, &stack_b);
	return (0);
}

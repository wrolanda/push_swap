/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_of_in_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:59:08 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/02 21:05:37 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_list **list)
{
	t_list	*list1;
	t_list	*list2;
	int		num;

	list1 = *list;
	while (list1)
	{
		num = list1->value;
		list2 = list1->next;
		while (list2)
		{
			if (num == list2->value)
			{
				write(2, "Error\n", 6);
				ft_free_memory_stacks(list, NULL);
			}
			list2 = list2->next;
		}
		list1 = list1->next;
	}
}

void	ft_check_double_sort(t_list **list)
{
	t_list	*stack;
	int		num;
	int		sort;

	stack = (*list)->next;
	num = (*list)->value;
	sort = 1;
	ft_check_double(list);
	while (stack)
	{
		if (num > stack->value)
			sort = 0;
		num = stack->value;
		stack = stack->next;
	}
	if (sort == 1)
		ft_free_memory_stacks(list, NULL);
}

static int	ft_is_valid_char(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (1);
	else
		return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_check_valid_argv_0(char **argv)
{
	int	x;
	int	y;
	int	check;
	int	fl;

	x = 1;
	while (argv[x])
	{
		fl = 0;
		if (argv[x][0] == '\0')
			ft_exit();
		y = -1;
		while (argv[x][++y])
		{
			check = ft_is_valid_char(argv[x][y]);
			fl += ft_isdigit(argv[x][y]);
			if (argv[x][y] == '-' && ft_isdigit(argv[x][y + 1]) != 1)
				ft_exit();
			if (check == 0)
				ft_exit();
		}
		if (fl == 0)
			ft_exit();
		x++;
	}
}

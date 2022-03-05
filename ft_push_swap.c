/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:22:53 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/05 16:55:33 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list **lst)
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

void	ft_sort_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first < second && first < third && second > third)
	{
		ft_reverse_rotate_a_or_b(stack, "rra\n");
		ft_swap_a_or_b(stack, "sa\n");
	}
	else if (first > second && first < third && second < third)
		ft_swap_a_or_b(stack, "sa\n");
	else if (first < second && first > third && second > third)
		ft_reverse_rotate_a_or_b(stack, "rra\n");
	else if (first > second && first > third && second < third)
		ft_rotate_a_or_b(stack, "ra\n");
	else if (first > second && first > third && second > third)
	{
		ft_swap_a_or_b(stack, "sa\n");
		ft_reverse_rotate_a_or_b(stack, "rra\n");
	}
}

int	ft_found_position_min(t_list **list, int size)
{
	int		min_pos;
	int		x;
	int		num;
	t_list	*templ;

	templ = (*list);
	num = templ->value;
	x = 0;
	min_pos = 0;
	while (x < size)
	{
		if (templ->value < num)
		{
			num = templ->value;
			min_pos = x;
		}
		templ = templ->next;
		x++;
	}
	return (min_pos);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b, int size)
{
	int	x;
	int	y;

	x = size + 1;
	while (--x > 3)
	{
		y = ft_found_position_min(stack_a, x);
		while (y > 0 && y < x)
		{
			if (y < x / 2 + 1)
			{
				ft_rotate_a_or_b(stack_a, "ra\n");
				y--;
			}
			else
			{
				ft_reverse_rotate_a_or_b(stack_a, "rra\n");
				y++;
			}
		}
		ft_push_b(stack_a, stack_b);
	}
	ft_sort_3(stack_a);
	while (++x <= size)
		ft_push_a(stack_a, stack_b);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (size == 2)
		ft_swap_a_or_b(stack_a, "sa\n");
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size < 6)
		ft_sort_5(stack_a, stack_b, size);
	else
		ft_main_sort(stack_a, stack_b, size);
	//ft_print_stacks(stack_a, stack_b);
}

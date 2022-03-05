/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:18:34 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/05 20:33:23 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_found_position_max(t_list **list, int size)
{
	int		pos;
	int		x;
	int		num;
	t_list	*templ;

	templ = (*list);
	num = templ->value;
	x = 0;
	pos = 0;
	while (x < size)
	{
		if (templ->value > num)
		{
			num = templ->value;
			pos = x;
		}
		templ = templ->next;
		x++;
	}
	return (pos);
}

void	ft_back_in_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	y;

	x = ft_lstsize(stack_b) + 1;
	while (--x > 0)
	{
		y = ft_found_position_max(stack_b, x);
		while (y > 0 && y < x)
		{
			if (y <= x / 2)
			{
				ft_rotate_a_or_b(stack_b, "rb\n");
				y--;
			}
			else
			{
				ft_reverse_rotate_a_or_b(stack_b, "rrb\n");
				y++;
			}
		}
		ft_push_a(stack_a, stack_b);
	}
}

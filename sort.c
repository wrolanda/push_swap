/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:58:43 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/05 16:35:03 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sort_mas(int *mas, int size)
{
	int	a;
	int	b;
	int	t;

	a = 1;
	while (a < size)
	{
		t = mas[a];
		b = a - 1;
		while (b >= 0 && t < mas[b])
		{
			mas[b + 1] = mas[b];
			b--;
		}
		mas[b + 1] = t;
		a++;
	}
	return (mas);
}

static void	ft_f_base(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*copylist;
	int		*mas;
	int		a;

	mas = (int *)malloc(sizeof(int) * size);
	if (!mas)
		ft_free_memory_stacks(stack_a, stack_b);
	copylist = *stack_a;
	a = 0;
	while (copylist)
	{
		mas[a] = copylist->value;
		copylist = copylist->next;
		a++;
	}
	mas = ft_sort_mas(mas, size);
	copylist = *stack_a;
	while (copylist)
	{
		a = 0;
		while (a < size)
		{
			if (copylist->value == mas[a])
			{
				copylist->index = a;
				break ;
			}
			a++;
		}
		copylist = copylist->next;
	}
	free(mas);
}

static int	ft_found_position_max(t_list **list, int size)
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
		if (templ->value > num)
		{
			num = templ->value;
			min_pos = x;
		}
		templ = templ->next;
		x++;
	}
	return (min_pos);
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

void	ft_main_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	numelem;
	int	i;

	size = ft_lstsize(stack_a);
	if (size > 100)
		numelem = 30;
	else
		numelem = 15;
	ft_f_base(stack_a, stack_b, size);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->index <= (i + numelem))
		{
			if ((*stack_a)->index < (i + (numelem / 4)))
				ft_push_b(stack_a, stack_b);
			else
			{
				ft_push_b(stack_a, stack_b);
				ft_rotate_a_or_b(stack_b, "rb\n");
			}
			i++;
		}
		else
			ft_rotate_a_or_b(stack_a, "ra\n");
	}
	ft_back_in_stack_a(stack_a, stack_b);
}

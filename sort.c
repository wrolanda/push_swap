/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:58:43 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/05 21:22:37 by wrolanda         ###   ########.fr       */
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

static void	ft_write_indexes(t_list *copylist, int a, int size, int *mas)
{
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
}

void	ft_presort(t_list **stack_a, t_list **stack_b, int size)
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
	ft_write_indexes(copylist, a, size, mas);
	free(mas);
}

static int	ft_numelem(int size)
{
	int	numelem;

	if (size > 100)
		numelem = 30;
	else
		numelem = 15;
	return (numelem);
}

void	ft_main_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	numelem;
	int	i;

	size = ft_lstsize(stack_a);
	numelem = ft_numelem(size);
	ft_presort(stack_a, stack_b, size);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:09:37 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/02 19:34:46 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_create_elem(int value)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		ft_free_memory_stacks(&list, NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}

void	ft_create_next(t_list **list, int value)
{
	t_list	*lastlist;

	lastlist = *list;
	if (!lastlist)
		*list = ft_create_elem(value);
	else
	{
		while (lastlist->next)
			lastlist = lastlist->next;
		lastlist->next = ft_create_elem(value);
	}
}

static void	ft_write_split(t_list **list, char *argv)
{
	int		x;
	int		value;
	char	**array;

	array = ft_split(argv, ' ');
	if (!array)
		exit(1);
	x = 0;
	while (array[x])
	{
		value = ft_atoi(array[x], list, array, x);
		ft_create_next(list, value);
		x++;
	}
	ft_free_memory_split(array, x - 1);
}

void	ft_push_data_on_stack(t_list **list, char **argv)
{
	int	x;

	x = 1;
	while (argv[x])
	{
		ft_write_split(list, argv[x]);
		x++;
	}
}

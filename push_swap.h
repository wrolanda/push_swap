/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:45:55 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/03 00:23:28 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

void	ft_exit(void);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str, t_list **list, char **array, int x);
char	**ft_split(char const *s, char c);

void	ft_free_memory_split(char **array, int x);
void	ft_free_memory_stacks(t_list **stack_a, t_list **stack_b);

void	ft_check_valid_argv_0(char **argv);
void	ft_push_data_on_stack(t_list **list, char **argv);
void	ft_check_double(t_list **list);
void	ft_check_double_sort(t_list **list);

void	ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **list);

void	ft_print_stack(t_list **stack);

#endif
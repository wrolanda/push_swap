/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:45:55 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/05 17:20:53 by wrolanda         ###   ########.fr       */
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
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list **lst);

void	ft_free_memory_split(char **array, int x);
void	ft_free_memory_stacks(t_list **stack_a, t_list **stack_b);

void	ft_check_valid_argv_0(char **argv);
void	ft_push_data_on_stack(t_list **list, char **argv);
void	ft_check_double(t_list **list);
void	ft_check_double_sort(t_list **list);

void	ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_main_sort(t_list **stack_a, t_list **stack_b, int size);
void	ft_back_in_stack_a(t_list **stack_a, t_list **stack_b);

void	ft_swap_a_or_b(t_list **list, char *str);
void	ft_swap_ss(t_list **list1, t_list **list2);
void	ft_push_a(t_list **list1, t_list **list2);
void	ft_push_b(t_list **list1, t_list **list2);
void	ft_rotate_a_or_b(t_list **list, char *str);
void	ft_rotate_rr(t_list **list1, t_list **list2);
void	ft_reverse_rotate_a_or_b(t_list **list, char *str);
void	ft_reverse_rotate_rr(t_list **list1, t_list **list2);

void	ft_print_stack(t_list **stack);
void	ft_print_stacks(t_list **stack_a, t_list **stack_b);

#endif

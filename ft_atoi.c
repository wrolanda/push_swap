/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:37:30 by wrolanda          #+#    #+#             */
/*   Updated: 2022/03/02 19:34:38 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*atoi, atoi_l -- convert ASCII string to integer
DESCRIPTION
	The atoi() function converts the initial portion of the string pointed to
	by str to int representation.
*/
#include "push_swap.h"

int	ft_atoi(const char *str, t_list **list, char **array, int x)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign > 2147483647) || (result * sign < -2147483648))
		{
			write(2, "Error\n", 6);
			ft_free_memory_split(array, x);
			ft_free_memory_stacks(list, NULL);
		}
		i++;
	}
	return (result * sign);
}

/*#include <stdio.h>
int main(void)
{
	char *s = " --34 55";
	printf("orig	=	%d\n", atoi(s));
	printf("my	= 	%d\n\n", ft_atoi(s));

}*/

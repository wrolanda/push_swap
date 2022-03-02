/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:22:40 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/25 22:34:31 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft125(github)/libft.h"
#include "bit_move.h"
#include <stdio.h>

long long int ft_revers_num(long long int t, int check)
{
	long long int itog;

	itog = 0;
	while (t > 0)
	{
		itog += t%10;
		t = t/10;
		if (t > 0)
			itog = itog * 10;
	}
	if (check == 1)
		itog -= 1;
	return (itog);
}

long long int ft_10bit_to_2bit(int a)
{
	long long int	t;
	int				check;

	t = 0;
	check = 0;
	if (a % 2 == 0)
	{
		t = 1;
		check = 1;
	}
	while (a > 0)
	{
		t += a % 2;
		a = a / 2;
		if (a > 0)
			t = t * 10;
	}
	t = ft_revers_num(t, check);
	return (t);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = ft_atoi(argv[1]);
		int k = ft_atoi(argv[2]);
		long long int m = ft_10bit_to_2bit(i);
		long long int n = ft_10bit_to_2bit(k);
		printf("2bitview1: %08lld\n", m);
		printf("2bitview2: %08lld\n", n);
		printf("bit move %d and %d = %d;\n", i, k, i & k);
	}
	else
		(printf("argv is not 2\n"));
	return (0);
}

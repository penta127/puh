/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:54:56 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:51:11 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_minus(char c, int *minus)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*minus = -1;
		return (1);
	}
	return (0);
}

bool	error_check_over_number(long int out, char c, int minus)
{
	long	max_div;
	long	max_mod;
	long	min_div;
	long	min_mod;

	if (c < '0' || '9' < c)
		return (false);
	if (minus == 1)
	{
		max_div = INT_MAX / 10;
		max_mod = INT_MAX % 10;
		if ((out > max_div) || (out == max_div && ((int)c - '0') > max_mod))
			return (false);
	}
	else
	{
		min_div = (-(INT_MIN / 10));
		min_mod = (-(INT_MIN % 10));
		if ((out > min_div) || (out == min_div && ((int)c - '0') > min_mod))
			return (false);
	}
	return (true);
}

int	ft_atoi_check(t_stacks *stacks, char *str, char **sp_num)
{
	long int	out;
	size_t		size;
	int			minus;

	size = 0;
	out = 0;
	minus = 1;
	size += check_minus(str[size], &minus);
	if (str[size] == '\0')
		free_split_stacks(stacks, sp_num);
	while (str[size] != '\0')
	{
		if (error_check_over_number(out, str[size], minus) == false)
			free_split_stacks(stacks, sp_num);
		out = (out * 10) + (str[size] - '0');
		size++;
	}
	return ((int)(out * minus));
}

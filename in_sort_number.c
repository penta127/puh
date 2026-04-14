/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sort_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:06 by koito             #+#    #+#             */
/*   Updated: 2025/12/16 00:48:40 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_split_num(t_stacks *stacks, char **split_number)
{
	int		j;
	int		value;
	t_node	*n1;

	j = 0;
	while (split_number[j] != NULL)
	{
		value = ft_atoi_check(stacks, split_number[j], split_number);
		check_dup(stacks, value, split_number);
		n1 = node_new(value);
		if (n1 == NULL)
			free_split_stacks(stacks, split_number);
		under_add(&stacks->a_stacks, n1);
		j++;
	}
}

void	in_sort_number(t_stacks *stacks, int argc, char **argv)
{
	char	**split_number;
	int		i;

	i = 1;
	while (i < argc)
	{
		split_number = ft_split_ps(stacks, argv[i], ' ');
		if (split_number[0] == NULL)
			free_split_stacks(stacks, split_number);
		add_split_num(stacks, split_number);
		free_sp(split_number);
		i++;
	}
}

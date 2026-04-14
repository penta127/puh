/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:38 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:45:28 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_helper(t_stacks *stacks, int min_position)
{
	if (min_position == 2)
		sa_ps(stacks);
	else if (min_position == 3)
	{
		ra_ps(stacks);
		ra_ps(stacks);
	}
	else if (min_position == 4)
		rra_ps(stacks);
	pb_ps(stacks);
	sort_3(stacks);
	pa_ps(stacks);
}

void	sort_4(t_stacks *stacks)
{
	t_node	*n1;
	int		min_value;
	int		min_position;
	int		i;

	i = 1;
	min_position = 1;
	min_value = stacks->a_stacks.top->value;
	n1 = stacks->a_stacks.top;
	while (n1)
	{
		if (min_value > n1->value)
		{
			min_value = n1->value;
			min_position = i;
		}
		n1 = n1->next;
		i++;
	}
	sort_4_helper(stacks, min_position);
}

void	sort_5_helper(t_stacks *stacks, int min_position)
{
	if (min_position == 2)
		sa_ps(stacks);
	else if (min_position == 3)
	{
		ra_ps(stacks);
		ra_ps(stacks);
	}
	else if (min_position == 4)
	{
		rra_ps(stacks);
		rra_ps(stacks);
	}
	else if (min_position == 5)
		rra_ps(stacks);
	pb_ps(stacks);
	sort_4(stacks);
	pa_ps(stacks);
}

void	sort_5(t_stacks *stacks)
{
	t_node	*n1;
	int		min_value;
	int		min_position;
	int		i;

	i = 1;
	min_position = 1;
	min_value = stacks->a_stacks.top->value;
	n1 = stacks->a_stacks.top;
	while (n1)
	{
		if (min_value > n1->value)
		{
			min_value = n1->value;
			min_position = i;
		}
		n1 = n1->next;
		i++;
	}
	sort_5_helper(stacks, min_position);
}

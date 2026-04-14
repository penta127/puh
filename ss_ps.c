/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:41 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ps_ss(t_stacks *stacks)
{
	if (stacks->a_stacks.size <= 1)
		return ;
	else if (stacks->a_stacks.size == 2)
	{
		sa_ps_size_two(&stacks->a_stacks);
	}
	else if (stacks->a_stacks.size >= 3)
	{
		sa_ps_size_over_two(&stacks->a_stacks);
	}
}

void	sb_ps_ss(t_stacks *stacks)
{
	if (stacks->b_stacks.size <= 1)
		return ;
	else if (stacks->b_stacks.size == 2)
	{
		sb_ps_size_two(&stacks->b_stacks);
	}
	else if (stacks->b_stacks.size >= 3)
	{
		sb_ps_size_over_two(&stacks->b_stacks);
	}
}

void	ss_ps(t_stacks *stacks)
{
	sa_ps_ss(stacks);
	sb_ps_ss(stacks);
	write(1, "ss\n", 3);
}

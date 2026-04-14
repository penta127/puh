/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:29 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_ps_rrr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*now_under;
	t_node	*new_under;

	if (stacks->a_stacks.size <= 1)
		return ;
	now_top = stacks->a_stacks.top;
	now_under = stacks->a_stacks.under;
	new_under = stacks->a_stacks.under->before;
	stacks->a_stacks.under = new_under;
	stacks->a_stacks.under->next = NULL;
	now_under->next = now_top;
	now_under->before = NULL;
	now_top->before = now_under;
	stacks->a_stacks.top = now_under;
	stacks->a_stacks.under = new_under;
}

void	rrb_ps_rrr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*now_under;
	t_node	*new_under;

	if (stacks->b_stacks.size <= 1)
		return ;
	now_top = stacks->b_stacks.top;
	now_under = stacks->b_stacks.under;
	new_under = stacks->b_stacks.under->before;
	stacks->b_stacks.under = new_under;
	stacks->b_stacks.under->next = NULL;
	now_under->next = now_top;
	now_under->before = NULL;
	now_top->before = now_under;
	stacks->b_stacks.top = now_under;
	stacks->b_stacks.under = new_under;
}

void	rrr_ps(t_stacks *stacks)
{
	rra_ps_rrr(stacks);
	rrb_ps_rrr(stacks);
	write(1, "rrr\n", 4);
}

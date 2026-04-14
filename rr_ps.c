/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:25 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_ps_rr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*new_top;
	t_node	*now_under;

	if (stacks->a_stacks.size <= 1)
		return ;
	now_top = stacks->a_stacks.top;
	new_top = now_top->next;
	now_under = stacks->a_stacks.under;
	stacks->a_stacks.top = new_top;
	stacks->a_stacks.top->before = NULL;
	now_top->next = NULL;
	now_top->before = now_under;
	now_under->next = now_top;
	stacks->a_stacks.under = now_top;
}

void	rb_ps_rr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*new_top;
	t_node	*now_under;

	if (stacks->b_stacks.size <= 1)
		return ;
	now_top = stacks->b_stacks.top;
	new_top = now_top->next;
	now_under = stacks->b_stacks.under;
	stacks->b_stacks.top = new_top;
	stacks->b_stacks.top->before = NULL;
	now_top->next = NULL;
	now_top->before = now_under;
	now_under->next = now_top;
	stacks->b_stacks.under = now_top;
}

void	rr_ps(t_stacks *stacks)
{
	ra_ps_rr(stacks);
	rb_ps_rr(stacks);
	write(1, "rr\n", 3);
}

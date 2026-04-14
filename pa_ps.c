/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:14 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_ps_helper(t_stack *a, t_node *n1)
{
	if (a->size == 0)
	{
		a->top = n1;
		a->under = n1;
		n1->before = NULL;
		n1->next = NULL;
	}
	else
	{
		n1->next = a->top;
		n1->before = NULL;
		a->top->before = n1;
		a->top = n1;
	}
}

void	pa_ps(t_stacks *stacks)
{
	t_node	*n1;

	if (stacks->b_stacks.size == 0)
		return ;
	n1 = stacks->b_stacks.top;
	stacks->b_stacks.top = n1->next;
	if (stacks->b_stacks.top != NULL)
		stacks->b_stacks.top->before = NULL;
	else
		stacks->b_stacks.under = NULL;
	pa_ps_helper(&stacks->a_stacks, n1);
	stacks->b_stacks.size--;
	stacks->a_stacks.size++;
	write(1, "pa\n", 3);
}

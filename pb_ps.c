/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:16 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_ps_helper(t_stack *b, t_node *n1)
{
	if (b->size == 0)
	{
		b->top = n1;
		b->under = n1;
		n1->before = NULL;
		n1->next = NULL;
	}
	else
	{
		n1->next = b->top;
		n1->before = NULL;
		b->top->before = n1;
		b->top = n1;
	}
}

void	pb_ps(t_stacks *stacks)
{
	t_node	*n1;

	if (stacks->a_stacks.size == 0)
		return ;
	n1 = stacks->a_stacks.top;
	stacks->a_stacks.top = n1->next;
	if (stacks->a_stacks.top != NULL)
		stacks->a_stacks.top->before = NULL;
	else
		stacks->a_stacks.under = NULL;
	pb_ps_helper(&stacks->b_stacks, n1);
	stacks->a_stacks.size--;
	stacks->b_stacks.size++;
	write(1, "pb\n", 3);
}

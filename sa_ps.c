/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:32 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:45:28 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ps_size_two(t_stack *a)
{
	t_node	*n1;
	t_node	*n2;

	n1 = a->top;
	n2 = a->under;
	a->top = n2;
	a->under = n1;
	n1->next = NULL;
	n1->before = n2;
	n2->before = NULL;
	n2->next = n1;
}

void	sa_ps_size_over_two(t_stack *a)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	n1 = a->top;
	n2 = n1->next;
	n3 = n2->next;
	a->top = n2;
	n2->before = NULL;
	n2->next = n1;
	n1->before = n2;
	n1->next = n3;
	n3->before = n1;
}

void	sa_ps(t_stacks *stacks)
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
	write(1, "sa\n", 3);
}

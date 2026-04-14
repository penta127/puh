/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_free_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:59 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:46:30 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_in_null(t_stacks *stacks)
{
	stacks->a_stacks.top = NULL;
	stacks->a_stacks.under = NULL;
	stacks->a_stacks.size = 0;
	stacks->b_stacks.top = NULL;
	stacks->b_stacks.under = NULL;
	stacks->b_stacks.size = 0;
}

void	free_stack_a(t_stack *a)
{
	t_node	*n1;
	t_node	*n1_next;

	n1 = a->top;
	while (n1 != NULL)
	{
		n1_next = n1->next;
		free(n1);
		n1 = n1_next;
	}
	a->top = NULL;
	a->under = NULL;
	a->size = 0;
}

void	free_stack_b(t_stack *b)
{
	t_node	*n1;
	t_node	*n1_next;

	n1 = b->top;
	while (n1 != NULL)
	{
		n1_next = n1->next;
		free(n1);
		n1 = n1_next;
	}
	b->top = NULL;
	b->under = NULL;
	b->size = 0;
}

void	free_sp(char **out)
{
	size_t	i;

	i = 0;
	while (out[i] != NULL)
	{
		free(out[i]);
		i++;
	}
	free(out);
}

void	free_split_stacks(t_stacks *stacks, char **split_number)
{
	if (split_number)
		free_sp(split_number);
	free_stack_a(&stacks->a_stacks);
	free_stack_b(&stacks->b_stacks);
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

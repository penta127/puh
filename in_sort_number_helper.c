/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sort_number_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:02 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:45:28 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stacks *stacks, int check_value, char **sp_num)
{
	t_node	*source;

	source = stacks->a_stacks.top;
	while (source != NULL)
	{
		if (check_value == source->value)
			free_split_stacks(stacks, sp_num);
		source = source->next;
	}
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->before = NULL;
	return (node);
}

void	under_add(t_stack *stack, t_node *node)
{
	if (stack->under == NULL)
	{
		stack->top = node;
		stack->under = node;
	}
	else
	{
		stack->under->next = node;
		node->before = stack->under;
		stack->under = node;
	}
	stack->size++;
}

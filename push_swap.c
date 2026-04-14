/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:19 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:49:07 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (1);
	stacks_in_null(stacks);
	in_sort_number(stacks, argc, argv);
	index_stack(stacks);
	execute_sort(stacks);
	free_stack_a(&stacks->a_stacks);
	free_stack_b(&stacks->b_stacks);
	free(stacks);
	return (0);
}

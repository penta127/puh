/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:12 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 19:55:13 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ascending_order_check(t_stack *a)
{
	t_node	*n1;

	n1 = a->top;
	if (a->size <= 1)
		return (true);
	while (n1->next != NULL)
	{
		if (n1->value > n1->next->value)
			return (false);
		n1 = n1->next;
	}
	return (true);
}

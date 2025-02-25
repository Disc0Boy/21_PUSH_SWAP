/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:31 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:15:21 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_bonus(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	last = stack->head;
	while (last->next)
		last = last->next;
	stack->head = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra_bonus(t_stack *a)
{
	rotate_bonus(a);
}

void	rb_bonus(t_stack *b)
{
	rotate_bonus(b);
}

void	rr_bonus(t_stack *a, t_stack *b)
{
	rotate_bonus(a);
	rotate_bonus(b);
}

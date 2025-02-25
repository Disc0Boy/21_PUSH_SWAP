/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:25 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:14:05 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate_bonus(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	second_last = stack->head;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->head;
	stack->head = last;
}

void	rra_bonus(t_stack *a)
{
	reverse_rotate_bonus(a);
}

void	rrb_bonus(t_stack *b)
{
	reverse_rotate_bonus(b);
}

void	rrr_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate_bonus(a);
	reverse_rotate_bonus(b);
}

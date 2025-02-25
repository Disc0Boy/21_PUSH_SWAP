/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:36 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:23:46 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_bonus(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

void	sa_bonus(t_stack *a)
{
	swap_bonus(a);
}

void	sb_bonus(t_stack *b)
{
	swap_bonus(b);
}

void	ss_bonus(t_stack *a, t_stack *b)
{
	swap_bonus(a);
	swap_bonus(b);
}

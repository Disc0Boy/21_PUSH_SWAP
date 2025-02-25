/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:13 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:14:25 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_bonus(t_stack *dst, t_stack *src)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	src->size--;
	temp->next = dst->head;
	dst->head = temp;
	dst->size++;
}

void	pa_bonus(t_stack *a, t_stack *b)
{
	push_bonus(a, b);
}

void	pb_bonus(t_stack *a, t_stack *b)
{
	push_bonus(b, a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:05 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:47:42 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_shortest_path(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;
	int		size;

	pos = 0;
	size = stack->size;
	current = stack->head;
	while (current)
	{
		if (current->value == value)
			break ;
		pos++;
		current = current->next;
	}
	if (pos > size / 2)
		return (-1);
	return (1);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	direction;

	while (a->size > 3)
	{
		min = get_min(a);
		direction = find_shortest_path(a, min);
		while (a->head->value != min)
		{
			if (direction == 1)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size)
		pa(a, b);
}

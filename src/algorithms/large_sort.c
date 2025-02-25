/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:41:58 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 10:16:40 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_position(t_stack *stack, int index)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (current)
	{
		if (current->index == index)
			return (pos);
		pos++;
		current = current->next;
	}
	return (0);
}

static int	get_chunk_size(t_stack *a)
{
	if (a->size <= 100)
		return (a->size / 5);
	return (a->size / 17);
}

static void	push_to_b_by_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	i;
	int	max_kept;

	chunk_size = get_chunk_size(a);
	i = 0;
	max_kept = a->size - 3;
	while (a->size > 3)
	{
		if (a->head->index >= max_kept)
			ra(a);
		else if (a->head->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->head->index <= (i + chunk_size))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_index;
	int	pos;

	while (b->size)
	{
		max_index = get_max_index(b);
		pos = get_position(b, max_index);
		while (b->head->index != max_index)
		{
			if (pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_infinite(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	index_stack(a);
	push_to_b_by_chunks(a, b);
	sort_three(a);
	push_back_to_a(a, b);
}

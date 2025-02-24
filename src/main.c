/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:56 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/24 15:12:52 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->head->value > a->head->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		sort_infinite(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !argv[1][0])
		return (0);
	a = init_stack('a');
	b = init_stack('b');
	if (!a || !b)
	{
		error_exit(a, b);
		return (0);
	}
	if (!parse_args(argc, argv, a))
	{
		error_exit(a, b);
		return (0);
	}
	index_stack(a);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

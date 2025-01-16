/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:56 by agenisse          #+#    #+#             */
/*   Updated: 2025/01/16 16:43:27 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int g_display_enabled = 0;

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
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);

	if (argc > 2)
	{
		g_display_enabled = 1;
		argv++;
		argc--;
	}

	a = init_stack('a');
	b = init_stack('b');
	if (!a || !b)
		error_exit(a, b);
	if (!parse_args(argc, argv, a))
		error_exit(a, b);
	index_stack(a);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

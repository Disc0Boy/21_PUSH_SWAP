/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:14 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:19:15 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	check_result(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (0);
	return (is_sorted(a));
}

static void	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!execute_operation(line, a, b))
		{
			free(line);
			error_exit(a, b);
			exit(1);
		}
		free(line);
	}
	if (check_result(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		return (1);
	}
	if (!parse_args(argc, argv, a))
	{
		error_exit(a, b);
		return (1);
	}
	process_instructions(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

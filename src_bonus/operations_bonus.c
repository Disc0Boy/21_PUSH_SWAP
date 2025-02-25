/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:50 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:20:32 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	handle_swap_push(char *line, t_stack *a, t_stack *b)
{
	if (!strcmp(line, "sa\n"))
		return (sa_bonus(a), 1);
	if (!strcmp(line, "sb\n"))
		return (sb_bonus(b), 1);
	if (!strcmp(line, "ss\n"))
		return (ss_bonus(a, b), 1);
	if (!strcmp(line, "pa\n"))
		return (pa_bonus(a, b), 1);
	if (!strcmp(line, "pb\n"))
		return (pb_bonus(a, b), 1);
	return (0);
}

int	execute_operation(char *line, t_stack *a, t_stack *b)
{
	if (!line)
		return (0);
	if (handle_swap_push(line, a, b))
		return (1);
	if (!strcmp(line, "ra\n"))
		return (ra_bonus(a), 1);
	if (!strcmp(line, "rb\n"))
		return (rb_bonus(b), 1);
	if (!strcmp(line, "rr\n"))
		return (rr_bonus(a, b), 1);
	if (!strcmp(line, "rra\n"))
		return (rra_bonus(a), 1);
	if (!strcmp(line, "rrb\n"))
		return (rrb_bonus(b), 1);
	if (!strcmp(line, "rrr\n"))
		return (rrr_bonus(a, b), 1);
	return (0);
}

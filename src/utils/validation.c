/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:52 by agenisse          #+#    #+#             */
/*   Updated: 2025/01/16 14:55:19 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	long	num;
	int		i;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		new = new_node(num);
		if (!new)
			return (0);
		add_front(a, new);
		i++;
	}
	if (check_duplicates(a))
		return (0);
	return (1);
}

void	error_exit(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

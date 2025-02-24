/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:42:22 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/24 17:42:24 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_back(t_stack *stack, t_node *new)
{
	t_node	*current;

	if (!stack || !new)
		return ;
	if (!stack->head)
	{
		stack->head = new;
		stack->size++;
		return ;
	}
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = new;
	stack->size++;
}

void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	process_arg(char *arg, t_stack *a)
{
	long	num;
	t_node	*new;

	if (!is_valid_number(arg))
		return (0);
	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	new = new_node((int)num);
	if (!new)
		return (0);
	add_back(a, new);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**args;
	int		i;
	int		ret;

	if (argc == 2)
	{
		args = split_args(argv[1]);
		if (!args)
			return (0);
		i = 0;
	}
	else
	{
		args = argv + 1;
		i = 0;
	}
	ret = 1;
	while (args[i] && ret)
		ret = process_arg(args[i++], a);
	if (argc == 2)
		free_split_args(args);
	if (ret && check_duplicates(a))
		return (0);
	return (ret);
}

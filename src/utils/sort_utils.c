/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:47 by agenisse          #+#    #+#             */
/*   Updated: 2025/01/16 15:47:52 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	assign_index(t_stack *stack, int min, int *index)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (temp->value == min && temp->index == -1)
		{
			temp->index = *index;
			(*index)++;
			break ;
		}
		temp = temp->next;
	}
}

void	index_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		min;
	int		index;

	if (!stack || !stack->head)
		return ;
	index = 0;
	current = stack->head;
	while (current)
	{
		min = INT_MAX;
		temp = stack->head;
		while (temp)
		{
			if (temp->value < min && temp->index == -1)
				min = temp->value;
			temp = temp->next;
		}
		assign_index(stack, min, &index);
		current = current->next;
	}
}

long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

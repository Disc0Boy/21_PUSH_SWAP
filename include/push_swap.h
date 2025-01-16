/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:49:34 by agenisse          #+#    #+#             */
/*   Updated: 2025/01/16 16:42:38 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
	char			name;
}					t_stack;

// Operations
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// List utils
t_stack				*init_stack(char name);
t_node				*new_node(int value);
void				add_front(t_stack *stack, t_node *create);
void				free_stack(t_stack *stack);
int					is_sorted(t_stack *stack);

// Sort utils
int					get_min(t_stack *stack);
int					get_max(t_stack *stack);
void				assign_index(t_stack *stack, int min, int *index);
void				index_stack(t_stack *stack);

// Validation
int					is_valid_number(char *str);
int					check_duplicates(t_stack *stack);
int					parse_args(int argc, char **argv, t_stack *a);
void				error_exit(t_stack *a, t_stack *b);
long				ft_atoi(const char *str);

// Sort
void				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);

#endif
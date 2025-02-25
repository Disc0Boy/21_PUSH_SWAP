/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:34:45 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:34:46 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <string.h>

char				*get_next_line(int fd);
int					execute_operation(char *line, t_stack *a, t_stack *b);
void				pa_bonus(t_stack *a, t_stack *b);
void				pb_bonus(t_stack *a, t_stack *b);
void				sa_bonus(t_stack *a);
void				sb_bonus(t_stack *b);
void				ss_bonus(t_stack *a, t_stack *b);
void				ra_bonus(t_stack *a);
void				rb_bonus(t_stack *b);
void				rr_bonus(t_stack *a, t_stack *b);
void				rra_bonus(t_stack *a);
void				rrb_bonus(t_stack *b);
void				rrr_bonus(t_stack *a, t_stack *b);

#endif

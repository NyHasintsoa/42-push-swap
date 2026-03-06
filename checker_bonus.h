/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:26:43 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 08:52:31 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include "ft_type.h"

typedef struct s_opts_checker
{
	int				*numbers;
	int				size;
}	t_opts_checker;

t_opts_checker	ft_parse_args(int argc, char *argv[]);
char			*push_swap_checker(t_opts_checker opts);

int				ft_exec_push(
					const char *cmd,
					t_stack **stack_a,
					t_stack **stack_b);

int				ft_exec_reverse(
					const char *cmd,
					t_stack **stack_a,
					t_stack **stack_b);

int				ft_exec_rotate(
					const char *cmd,
					t_stack **stack_a,
					t_stack **stack_b);

int				ft_exec_swap(
					const char *cmd,
					t_stack **stack_a,
					t_stack **stack_b);

#endif
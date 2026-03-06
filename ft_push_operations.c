/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:18:17 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 07:58:03 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, t_options opts)
{
	ft_print_operation("pa\n");
	opts.bench->pa += 1;
	if (*stack_b)
		ft_stack_push(stack_a, ft_stack_top(stack_b));
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_options opts)
{
	ft_print_operation("pb\n");
	opts.bench->pb += 1;
	if (*stack_a)
		ft_stack_push(stack_b, ft_stack_top(stack_a));
}

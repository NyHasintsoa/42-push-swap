/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:21:52 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 07:56:20 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

void	ft_ra(t_stack **stack_a, t_options opts)
{
	ft_print_operation("ra\n");
	opts.bench->ra += 1;
	ft_stack_rotate(stack_a);
}

void	ft_rb(t_stack **stack_b, t_options opts)
{
	ft_print_operation("rb\n");
	opts.bench->rb += 1;
	ft_stack_rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_options opts)
{
	ft_print_operation("rr\n");
	opts.bench->rr += 1;
	ft_stack_rotate(stack_a);
	ft_stack_rotate(stack_b);
}

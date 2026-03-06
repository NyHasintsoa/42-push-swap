/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:18:19 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 07:58:39 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

void	ft_sa(t_stack **stack_a, t_options opts)
{
	ft_print_operation("sa\n");
	opts.bench->sa += 1;
	ft_stack_swap(stack_a);
}

void	ft_sb(t_stack **stack_b, t_options opts)
{
	ft_print_operation("sb\n");
	opts.bench->sb += 1;
	ft_stack_swap(stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_options opts)
{
	ft_print_operation("ss\n");
	opts.bench->ss += 1;
	ft_stack_swap(stack_a);
	ft_stack_swap(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:19:39 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 07:55:51 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

void	ft_rra(t_stack **stack_a, t_options opts)
{
	ft_print_operation("rra\n");
	opts.bench->rra += 1;
	ft_stack_reverse_rotate(stack_a);
}

void	ft_rrb(t_stack **stack_b, t_options opts)
{
	ft_print_operation("rrb\n");
	opts.bench->rrb += 1;
	ft_stack_reverse_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_options opts)
{
	ft_print_operation("rrr\n");
	opts.bench->rrr += 1;
	ft_stack_reverse_rotate(stack_a);
	ft_stack_reverse_rotate(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:00:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:42:43 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

static void	ft_put_min_top(t_stack **stack_a, t_options opts)
{
	int	min_index;
	int	size;
	int	reverse;

	min_index = ft_get_min_pos(*stack_a);
	if (min_index < 0)
		return ;
	size = ft_stack_size(*stack_a);
	if (min_index < size / 2)
	{
		while (min_index)
		{
			ft_ra(stack_a, opts);
			min_index--;
		}
		return ;
	}
	reverse = size - min_index;
	while (reverse)
	{
		ft_rra(stack_a, opts);
		reverse--;
	}
}

void	ft_strategy_simple(t_options opts, t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a && (*stack_a)->next)
	{
		ft_put_min_top(stack_a, opts);
		if (ft_check_stack_sorted(*stack_a, opts.count))
			break ;
		ft_pb(stack_a, stack_b, opts);
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b, opts);
}

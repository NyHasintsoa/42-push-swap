/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_adaptive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:15:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 13:55:17 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_short_sort(
	t_options opts,
	t_stack **stack_a,
	t_stack **stack_b
) {
	if (opts.count == 2)
	{
		ft_sa(stack_a, opts);
		return (1);
	}
	else if (opts.count == 3)
	{
		ft_sort_three(stack_a, opts);
		return (1);
	}
	else if (opts.count == 4
		|| opts.count == 5)
	{
		ft_sort_min(stack_a, stack_b, opts);
		return (1);
	}
	return (0);
}

void	ft_strategy_adaptive(
	t_options opts,
	t_stack **stack_a,
	t_stack **stack_b,
	float disorder
) {
	if (ft_short_sort(opts, stack_a, stack_b))
		return ;
	if (disorder < 0.2)
		ft_strategy_simple(opts, stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_strategy_medium(opts, stack_a, stack_b);
	else if (disorder >= 0.5)
		ft_strategy_complex(opts, stack_a, stack_b);
}

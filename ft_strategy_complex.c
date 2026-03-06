/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_complex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:00:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:42:51 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

static void	rotate_to_top(t_stack **stack, int pos, char name, t_options opts)
{
	int	size;

	size = ft_stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (name == 'a')
				ft_ra(stack, opts);
			else
				ft_rb(stack, opts);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (name == 'a')
				ft_rra(stack, opts);
			else
				ft_rrb(stack, opts);
		}
	}
}

static void	push_to_b_by_chunks(
	t_stack **stack_a,
	t_stack **stack_b,
	int chunk,
	t_options opts
) {
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b, opts);
			ft_rb(stack_b, opts);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk)
		{
			ft_pb(stack_a, stack_b, opts);
			i++;
		}
		else
			ft_ra(stack_a, opts);
	}
}

static void	sort_back_to_a(t_stack **stack_b, t_stack **stack_a, t_options opts)
{
	int	max_pos;

	while (*stack_b)
	{
		max_pos = ft_get_max_pos(*stack_b);
		rotate_to_top(stack_b, max_pos, 'b', opts);
		ft_pa(stack_a, stack_b, opts);
	}
}

void	ft_strategy_complex(
	t_options opts,
	t_stack **stack_a,
	t_stack **stack_b
) {
	int	chunk;

	if (opts.count <= 100)
		chunk = 15;
	else
		chunk = 35;
	push_to_b_by_chunks(stack_a, stack_b, chunk, opts);
	sort_back_to_a(stack_b, stack_a, opts);
}

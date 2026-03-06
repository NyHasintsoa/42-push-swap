/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_medium.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:30:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:42:48 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

static void	move_max_to_top(t_stack **stack_b, t_options opts)
{
	int	max_pos;
	int	size;

	if (!stack_b || !*stack_b)
		return ;
	max_pos = ft_get_max_pos(*stack_b);
	size = ft_stack_size(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			ft_rb(stack_b, opts);
			max_pos--;
		}
	}
	else
	{
		max_pos = size - max_pos;
		while (max_pos > 0)
		{
			ft_rrb(stack_b, opts);
			max_pos--;
		}
	}
}

static void	empty_stack_b(t_stack **stack_b, t_stack **stack_a, t_options opts)
{
	while (*stack_b)
	{
		move_max_to_top(stack_b, opts);
		ft_pa(stack_a, stack_b, opts);
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

void	ft_strategy_medium(t_options opts, t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;

	if (opts.count <= 100)
		chunk = opts.count / 16;
	else
		chunk = opts.count / 30;
	push_to_b_by_chunks(stack_a, stack_b, chunk, opts);
	empty_stack_b(stack_b, stack_a, opts);
}

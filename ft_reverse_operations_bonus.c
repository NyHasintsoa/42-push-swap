/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_operations_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:19:39 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:43:18 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"

static void	ft_rra(t_stack **stack_a)
{
	ft_stack_reverse_rotate(stack_a);
}

static void	ft_rrb(t_stack **stack_b)
{
	ft_stack_reverse_rotate(stack_b);
}

static void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_reverse_rotate(stack_a);
	ft_stack_reverse_rotate(stack_b);
}

int	ft_exec_reverse(const char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "rra") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ft_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

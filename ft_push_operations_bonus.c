/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:18:17 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:43:45 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"

static void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
		ft_stack_push(stack_a, ft_stack_top(stack_b));
}

static void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
		ft_stack_push(stack_b, ft_stack_top(stack_a));
}

int	ft_exec_push(const char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "pa") == 0)
		ft_pa(stack_a, stack_b);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:21:52 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:43:36 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"

static void	ft_ra(t_stack **stack_a)
{
	ft_stack_rotate(stack_a);
}

static void	ft_rb(t_stack **stack_b)
{
	ft_stack_rotate(stack_b);
}

static void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_rotate(stack_a);
	ft_stack_rotate(stack_b);
}

int	ft_exec_rotate(const char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "ra") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(cmd, "rr") == 0)
		ft_rr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

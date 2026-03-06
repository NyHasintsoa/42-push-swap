/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:18:19 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 22:13:30 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"

static void	ft_sa(t_stack **stack_a)
{
	ft_stack_swap(stack_a);
}

static void	ft_sb(t_stack **stack_b)
{
	ft_stack_swap(stack_b);
}

static void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_swap(stack_a);
	ft_stack_swap(stack_b);
}

int	ft_exec_swap(const char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_sb(stack_b);
	else if (ft_strcmp(cmd, "ss") == 0)
		ft_ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 07:12:36 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 13:47:43 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_print_operation(const char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_total_ops(t_bench	*bench)
{
	int	total;

	total = bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr;
	total += bench->sa + bench->sb + bench->ss;
	total += bench->pa + bench->pb;
	return (total);
}

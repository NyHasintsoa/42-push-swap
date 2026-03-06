/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:57:16 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 21:58:40 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

t_strategy	ft_parse_strategy(const char *str)
{
	if (!str)
		return (STRATEGY_UNKNOWN);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (STRATEGY_ADAPTIVE);
	if (ft_strcmp(str, "--simple") == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (STRATEGY_COMPLEX);
	return (STRATEGY_UNKNOWN);
}

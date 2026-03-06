/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:16:22 by nramalan          #+#    #+#             */
/*   Updated: 2026/01/28 23:21:59 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	r;

	i = 0;
	r = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

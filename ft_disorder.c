/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:33:48 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 13:41:29 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

float	ft_compute_disorder(t_options opts)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < (opts.count - 1))
	{
		j = i + 1;
		while (j < opts.count)
		{
			total_pairs += 1;
			if (opts.numbers[i] > opts.numbers[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (mistakes == total_pairs)
		return ((float) 1);
	if (mistakes == 0 && total_pairs == 0)
		return ((float) 0);
	return ((float) mistakes / total_pairs);
}

char	*ft_format_disorder(float disorder)
{
	char	*str;
	int		first;
	int		last;

	str = (char *) malloc(sizeof(char) * 7);
	if (!str)
		return (NULL);
	first = (int) disorder;
	last = (int)((disorder - first) * 100);
	str[0] = (first / 10) + '0';
	str[1] = (first % 10) + '0';
	str[2] = '.';
	str[3] = (last / 10) + '0';
	str[4] = (last % 10) + '0';
	str[5] = '%';
	str[6] = '\0';
	return (str);
}

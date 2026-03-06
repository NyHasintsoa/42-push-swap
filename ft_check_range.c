/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:16:49 by karatsar          #+#    #+#             */
/*   Updated: 2026/03/06 06:58:59 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_words_is_in_range(char **words)
{
	long	n;
	int		i;

	i = 0;
	while (words[i])
	{
		n = ft_atol(words[i]);
		if ((n > 2147483647) || (n < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

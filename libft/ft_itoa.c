/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:56:15 by nramalan          #+#    #+#             */
/*   Updated: 2026/01/28 22:45:02 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr *= (-1);
	}
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	size_t	length;
	long	nbr;

	nbr = (long) n;
	length = ft_nbrlen(nbr);
	tab = (char *) malloc(sizeof(char) * (length + 1));
	if (!tab)
		return (NULL);
	tab[length] = '\0';
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr *= (-1);
	}
	if (nbr == 0)
		tab[0] = '0';
	while (nbr > 0)
	{
		tab[length - 1] = (nbr % 10) + '0';
		nbr /= 10;
		length--;
	}
	return (tab);
}

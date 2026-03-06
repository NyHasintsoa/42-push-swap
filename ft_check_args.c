/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:15:54 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/03 18:14:56 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	ft_args_are_numeric(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisnumeric(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_args_is_in_range(int argc, char *argv[])
{
	long	n;
	int		i;

	i = 1;
	n = 0;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if ((n > 2147483647) || (n < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_check_args(int argc, char *argv[])
{
	int	i;
	int	*tab;

	if (!ft_args_are_numeric(argc, argv))
		ft_error();
	if (!ft_args_is_in_range(argc, argv))
		ft_error();
	tab = (int *) malloc(sizeof(int) * argc);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		tab[i] = (int) ft_atol(argv[i + 1]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

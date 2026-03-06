/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:26:54 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 09:12:32 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_utils.h"
#include "libft.h"

static int	print_result(const char *value)
{
	if (ft_strcmp(value, "OK") == 0)
		ft_putstr_fd("OK\n", 1);
	else if (ft_strcmp(value, "KO") == 0)
		ft_putstr_fd("KO\n", 1);
	else if (ft_strcmp(value, "Error") == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_opts_checker	opts;
	char			*value;
	int				is_error;

	if ((argc - 1) == 0)
		return (0);
	opts = ft_parse_args(argc, argv);
	value = push_swap_checker(opts);
	is_error = print_result(value);
	free(opts.numbers);
	return (is_error);
}

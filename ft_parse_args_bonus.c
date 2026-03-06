/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:43:38 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 22:11:19 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_utils.h"

static int	*ft_get_numbers(int argc, char *argv[])
{
	int	*numbers;

	numbers = NULL;
	if ((argc - 1) == 1)
		numbers = ft_check_str(argv[1]);
	else
		numbers = ft_check_args(argc, argv);
	return (numbers);
}

t_opts_checker	ft_parse_args(int argc, char *argv[])
{
	t_opts_checker	opts;

	opts.numbers = NULL;
	opts.size = (argc - 1);
	if (opts.size == 1)
		opts.size = ft_count_numbers(argv[1], ' ');
	opts.numbers = ft_get_numbers(argc, argv);
	ft_check_dup(opts.numbers, opts.size);
	return (opts);
}

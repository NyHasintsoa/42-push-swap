/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:59:46 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 16:10:06 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

int	main(int argc, char *argv[])
{
	t_options	opts;
	t_bench		bench;
	int			is_sorted;
	float		disorder;

	if ((argc - 1) == 0)
		return (0);
	opts = ft_parse_options(argc, argv);
	disorder = ft_compute_disorder(opts);
	bench = ft_init_bench(disorder);
	opts.bench = &bench;
	is_sorted = ft_check_array_sorted(opts.numbers, opts.count);
	if (opts.is_bench && is_sorted)
		ft_print_bench(opts);
	if (is_sorted)
	{
		free(opts.numbers);
		return (0);
	}
	push_swap(opts);
	free(opts.numbers);
	return (0);
}

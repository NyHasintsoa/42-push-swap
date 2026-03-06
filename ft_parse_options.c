/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:30:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 07:07:19 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

static int	ft_is_option(const char *str)
{
	if (!str)
		return (0);
	if ((str[0] == '-') && (str[1] == '-'))
	{
		return (1);
	}
	return (0);
}

static int	*ft_get_numbers(int argc, char *argv[], int index)
{
	int	*numbers;

	numbers = NULL;
	if ((argc - index) > 1)
		numbers = ft_check_args(argc - index + 1, &argv[index - 1]);
	else
		numbers = ft_check_str(argv[index]);
	return (numbers);
}

static void	ft_add_numbers(t_options *opts, int argc, int index, char *argv[])
{
	int			size;

	size = argc - index;
	if (size == 1)
		size = ft_count_numbers(argv[index], ' ');
	opts->numbers = ft_get_numbers(argc, argv, index);
	opts->count = ft_check_dup(opts->numbers, size);
}

static void	ft_parse_flags(t_options *opts, int argc, char *argv[], int *i)
{
	int			nb_strategy;
	int			nb_bench;

	nb_strategy = 0;
	nb_bench = 0;
	while (*i < argc && ft_is_option(argv[*i]))
	{
		if (ft_parse_strategy(argv[*i]) != STRATEGY_UNKNOWN)
		{
			nb_strategy++;
			opts->strategy = ft_parse_strategy(argv[*i]);
		}
		else if (ft_strcmp(argv[*i], "--bench") == 0)
		{
			nb_bench++;
			opts->is_bench = 1;
		}
		else
			ft_error();
		(*i)++;
	}
	if ((nb_strategy >= 2) || (nb_bench >= 2))
		ft_error();
}

t_options	ft_parse_options(int argc, char *argv[])
{
	t_options	opts;
	int			i;

	opts.strategy = STRATEGY_ADAPTIVE;
	opts.is_bench = 0;
	opts.numbers = NULL;
	i = 1;
	ft_parse_flags(&opts, argc, argv, &i);
	ft_add_numbers(&opts, argc, i, argv);
	return (opts);
}

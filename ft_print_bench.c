/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:30:25 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 13:50:09 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"
#include "libft.h"

static void	ft_print_bench_rotation_parts(t_options opts)
{
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(opts.bench->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(opts.bench->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(opts.bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(opts.bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(opts.bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(opts.bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_strategy(t_strategy strategy)
{
	if (strategy == STRATEGY_ADAPTIVE)
		ft_putstr_fd("Adaptive", 2);
	else if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium", 2);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex", 2);
}

static void	ft_print_class(t_options opts)
{
	if (opts.strategy == STRATEGY_ADAPTIVE)
	{
		if (opts.bench->disorder < 0.2)
			ft_putstr_fd("O(n²)", 2);
		else if (opts.bench->disorder >= 0.2 && opts.bench->disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else if (opts.bench->disorder >= 0.5)
			ft_putstr_fd("O(nlogn)", 2);
		return ;
	}
	if (opts.strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("O(n²)", 2);
	else if (opts.strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("O(n√n)", 2);
	else if (opts.strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("O(nlogn)", 2);
}

static void	ft_print_bench_summary(t_options opts)
{
	char	*disorder;

	ft_putstr_fd("[bench] disorder:   ", 2);
	if (opts.bench->disorder < 100)
	{
		disorder = ft_format_disorder(opts.bench->disorder);
		ft_putstr_fd(disorder, 2);
		free(disorder);
	}
	else if (opts.bench->disorder == 100)
		ft_putstr_fd("100%", 2);
	ft_putstr_fd("\n[bench] strategy:   ", 2);
	ft_print_strategy(opts.strategy);
	ft_putstr_fd(" / ", 2);
	ft_print_class(opts);
	ft_putstr_fd("\n[bench] total_ops:  ", 2);
	ft_putnbr_fd(ft_total_ops(opts.bench), 2);
}

void	ft_print_bench(t_options opts)
{
	ft_print_bench_summary(opts);
	ft_putstr_fd("\n[bench] sa:  ", 2);
	ft_putnbr_fd(opts.bench->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(opts.bench->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(opts.bench->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(opts.bench->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(opts.bench->pb, 2);
	ft_print_bench_rotation_parts(opts);
}

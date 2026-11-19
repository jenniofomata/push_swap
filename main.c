/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run(t_ps *ps)
{
	ps->disorder = compute_disorder(ps);
	sort(ps);
	if (ps->bench)
	{
		print_bench(ps);
	}
}

int	main(int ac, char **av)
{
	t_ps	ps;
	int		first;

	init_ps(&ps);
	first = parse_flags(&ps, ac, av);
	if (first < 0)
	{
		error_exit(&ps);
	}
	if (first >= ac)
	{
		return (0);
	}
	if (!build_stack(&ps, ac - first, av + first))
	{
		error_exit(&ps);
	}
	run(&ps);
	free_ps(&ps);
	return (0);
}

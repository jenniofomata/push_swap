/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(t_ps *ps, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (is_flag(av[i], "--bench"))
			ps->bench = 1;
		else if (is_flag(av[i], "--simple"))
			ps->strategy = ST_SIMPLE;
		else if (is_flag(av[i], "--medium"))
			ps->strategy = ST_MEDIUM;
		else if (is_flag(av[i], "--complex"))
			ps->strategy = ST_COMPLEX;
		else if (is_flag(av[i], "--adaptive"))
			ps->strategy = ST_ADAPTIVE;
		else
			return (-1);
		i++;
	}
	return (i);
}

static int	fill_from_arg(t_ps *ps, const char *s, int *k)
{
	int	pos;

	pos = 0;
	while (s[pos])
	{
		while (is_sep(s[pos]))
		{
			pos++;
		}
		if (s[pos])
		{
			if (!read_num(s, &pos, &ps->a.v[*k]))
			{
				return (0);
			}
			(*k)++;
		}
	}
	return (1);
}

static int	fill_values(t_ps *ps, int ac, char **av)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < ac)
	{
		if (!fill_from_arg(ps, av[i], &k))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	collect_numbers(t_ps *ps, int ac, char **av)
{
	int	i;
	int	total;
	int	c;

	i = 0;
	total = 0;
	while (i < ac)
	{
		c = count_nums(av[i]);
		if (c == 0)
		{
			return (0);
		}
		total += c;
		i++;
	}
	if (total == 0 || !alloc_stacks(ps, total))
	{
		return (0);
	}
	ps->n = total;
	ps->a.size = total;
	return (fill_values(ps, ac, av));
}

int	build_stack(t_ps *ps, int ac, char **av)
{
	if (!collect_numbers(ps, ac, av))
	{
		return (0);
	}
	if (has_duplicates(ps))
	{
		return (0);
	}
	return (normalize(ps));
}

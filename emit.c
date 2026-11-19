/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*op_name(int op)
{
	char	*tab[OP_NB];

	tab[OP_SA] = "sa\n";
	tab[OP_SB] = "sb\n";
	tab[OP_SS] = "ss\n";
	tab[OP_PA] = "pa\n";
	tab[OP_PB] = "pb\n";
	tab[OP_RA] = "ra\n";
	tab[OP_RB] = "rb\n";
	tab[OP_RR] = "rr\n";
	tab[OP_RRA] = "rra\n";
	tab[OP_RRB] = "rrb\n";
	tab[OP_RRR] = "rrr\n";
	return (tab[op]);
}

void	emit(t_ps *ps, int op)
{
	ps->ops[op]++;
	ps->total++;
	ft_putstr_fd(op_name(op), 1);
}

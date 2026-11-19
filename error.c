/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ps(t_ps *ps)
{
	free(ps->a.v);
	free(ps->b.v);
	ps->a.v = NULL;
	ps->b.v = NULL;
}

void	error_exit(t_ps *ps)
{
	free_ps(ps);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

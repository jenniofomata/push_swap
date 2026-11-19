/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
	{
		return ;
	}
	tmp = s->v[0];
	s->v[0] = s->v[1];
	s->v[1] = tmp;
}

void	st_rotate(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
	{
		return ;
	}
	tmp = s->v[0];
	ft_memmove(s->v, s->v + 1, sizeof(int) * (s->size - 1));
	s->v[s->size - 1] = tmp;
}

void	st_rev_rotate(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
	{
		return ;
	}
	tmp = s->v[s->size - 1];
	ft_memmove(s->v + 1, s->v, sizeof(int) * (s->size - 1));
	s->v[0] = tmp;
}

void	st_push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
	{
		return ;
	}
	ft_memmove(to->v + 1, to->v, sizeof(int) * to->size);
	to->v[0] = from->v[0];
	to->size++;
	ft_memmove(from->v, from->v + 1, sizeof(int) * (from->size - 1));
	from->size--;
}

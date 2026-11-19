/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_percent(double d)
{
	long	scaled;

	scaled = (long)(d * 10000.0 + 0.5);
	ft_putnbr_fd((int)(scaled / 100), 2);
	ft_putstr_fd(".", 2);
	if (scaled % 100 < 10)
	{
		ft_putstr_fd("0", 2);
	}
	ft_putnbr_fd((int)(scaled % 100), 2);
	ft_putstr_fd("%\n", 2);
}

void	put_op(char *label, int n)
{
	ft_putstr_fd(label, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(" ", 2);
}

void	put_strategy(int s)
{
	char	*tab[4];

	tab[ST_SIMPLE] = "Simple";
	tab[ST_MEDIUM] = "Medium";
	tab[ST_COMPLEX] = "Complex";
	tab[ST_ADAPTIVE] = "Adaptive";
	ft_putstr_fd(tab[s], 2);
}

void	put_method(int m)
{
	char	*tab[5];

	tab[M_SELECT] = " (selection)";
	tab[M_CHUNK] = " (chunk)";
	tab[M_RADIX] = " (radix)";
	tab[M_SMALL] = " (small)";
	tab[M_LIS] = " (lis)";
	ft_putstr_fd(tab[m], 2);
}

void	put_class(int m)
{
	char	*tab[5];

	tab[M_SELECT] = "O(n^2)";
	tab[M_CHUNK] = "O(n*sqrt(n))";
	tab[M_RADIX] = "O(n log n)";
	tab[M_SMALL] = "O(1)";
	tab[M_LIS] = "O(n^2)";
	ft_putstr_fd(tab[m], 2);
}

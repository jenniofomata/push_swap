/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:00 by jenofoma          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

static int	read_digits(const char *s, int *i, long *nb)
{
	int	digits;

	digits = 0;
	*nb = 0;
	while (ft_isdigit(s[*i]))
	{
		*nb = *nb * 10 + (s[*i] - '0');
		if (*nb > 2147483648L)
		{
			return (0);
		}
		(*i)++;
		digits++;
	}
	return (digits);
}

static int	fits_int(int sign, long nb)
{
	if (sign > 0 && nb > 2147483647L)
	{
		return (0);
	}
	if (sign < 0 && nb > 2147483648L)
	{
		return (0);
	}
	return (1);
}

int	read_num(const char *s, int *pos, int *out)
{
	long	nb;
	int		sign;
	int		i;

	i = *pos;
	sign = read_sign(s, &i);
	if (!read_digits(s, &i, &nb))
	{
		return (0);
	}
	if (s[i] && !is_sep(s[i]))
	{
		return (0);
	}
	if (!fits_int(sign, nb))
	{
		return (0);
	}
	*out = (int)(sign * nb);
	*pos = i;
	return (1);
}

int	count_nums(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (is_sep(s[i]))
		{
			i++;
		}
		if (s[i])
		{
			count++;
			while (s[i] && !is_sep(s[i]))
			{
				i++;
			}
		}
	}
	return (count);
}

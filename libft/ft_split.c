/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:30:12 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/21 19:19:33 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_strings(const char *s, char c)
{
	size_t	word_count;
	int		new_word;

	new_word = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && new_word == 0)
		{
			new_word = 1;
			word_count++;
		}
		else if (*s == c)
		{
			new_word = 0;
		}
		s++;
	}
	return (word_count);
}

static	size_t	ft_count_chars(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
	{
		len++;
	}
	return (len);
}

static	void	ft_free_word_boxes(char **word_boxes, size_t n)
{
	while (n > 0)
	{
		free(word_boxes[n--]);
	}
	free(word_boxes);
}

static	int	ft_al_n_cop_w(char **word_boxes, const char **s, char c, size_t i)
{
	size_t	len;

	while (**s == c)
		(*s)++;
	len = ft_count_chars(*s, c);
	word_boxes[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!word_boxes[i])
	{
		ft_free_word_boxes(word_boxes, i);
		return (0);
	}
	ft_strlcpy(word_boxes[i], *s, len + 1);
	*s += len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**word_boxes;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (0);
	word_count = ft_count_strings(s, c);
	word_boxes = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!word_boxes)
		return (0);
	i = 0;
	while (i < word_count)
	{
		if (!ft_al_n_cop_w(word_boxes, &s, c, i))
			return (0);
		i++;
	}
	word_boxes[word_count] = 0;
	return (word_boxes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:09:23 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:22:06 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (*str)
	{
		if (x == 0 && *str != c)
		{
			x = 1;
			count++;
		}
		if (x == 1 && *str == c)
			x = 0;
		str++;
	}
	return (count);
}

static int	word_len(char *str, char c)
{
	int	n;

	n = 0;
	while (*str && *str != c)
	{
		str++;
		n++;
	}
	return (n);
}

static void	free_tab(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
}

static char	**fill_tab(char **tab, char *p, char c)
{
	int	len;
	int	j;
	int	k;

	j = 0;
	while (*p)
	{
		while (*p && *p == c)
			p++;
		if (!*p)
			break ;
		len = word_len(p, c);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tab[j])
		{
			free_tab(tab, j);
			return (NULL);
		}
		k = 0;
		while (k < len)
			tab[j][k++] = *p++;
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, (char *)s, c));
}

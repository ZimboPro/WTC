/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 07:42:20 by prussell          #+#    #+#             */
/*   Updated: 2017/09/04 10:33:00 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		split_c(char const *s, char c)
{
	int count;
	int next;

	if (!s)
		return (0);
	count = 0;
	next = 1;
	while (*s)
	{
		if (*s != c && next)
		{
			count++;
			next = 0;
		}
		else if (*s == c)
			next = 1;
		s++;
	}
	return (count);
}

static	int		word_len(char const *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	char	*add_word(char const *src, char c)
{
	int		j;
	char	*dst;

	dst = (char *)malloc(sizeof(*dst) * word_len(src, c) + 1);
	if (!dst)
		return (NULL);
	j = 0;
	while (src[j] != c && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		y;
	int		i;
	int		len;

	if (!s || !(split = (char**)malloc(sizeof(char *) * (split_c(s, c) + 1))))
		return (NULL);
	y = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c)
		{
			split[y] = add_word(s + i, c);
			if (!split[y++])
				return (NULL);
			i += word_len(s + i, c);
		}
		else
			i++;
	}
	split[y] = NULL;
	return (split);
}

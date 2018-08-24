/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 07:42:20 by prussell          #+#    #+#             */
/*   Updated: 2017/09/28 13:32:09 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static	int		split_c(char const *s)
{
	int count;
	int next;

	if (!s)
		return (0);
	count = 0;
	next = 1;
	while (*s)
	{
		if (!ft_isspace(*s) && next && *s != SEPARATOR_CHAR)
		{
			count++;
			next = 0;
		}
		else if (ft_isspace(*s) || *s == SEPARATOR_CHAR)
			next = 1;
		s++;
	}
	return (count);
}

static	int		word_len(char const *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && !ft_isspace(s[i]) && s[i] != SEPARATOR_CHAR)
		i++;
	return (i);
}

static	char	*add_word(char const *src)
{
	int		j;
	char	*dst;

	dst = (char *)malloc(sizeof(*dst) * word_len(src) + 1);
	if (!dst)
		return (NULL);
	j = 0;
	while (!ft_isspace(src[j]) && src[j] && src[j] != SEPARATOR_CHAR)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char			**core_line_split(char const *s)
{
	char	**split;
	int		y;
	int		i;
	int		len;

	if (!s || !(split = (char**)malloc(sizeof(char *) * (split_c(s) + 1))))
		return (NULL);
	y = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
		if (!ft_isspace(s[i]) && s[i] != SEPARATOR_CHAR)
		{
			split[y] = add_word(s + i);
			if (!split[y++])
			{
				ft_strarrdel(split);
				return (NULL);
			}
			i += word_len(s + i);
		}
		else
			i++;
	split[y] = NULL;
	return (split);
}

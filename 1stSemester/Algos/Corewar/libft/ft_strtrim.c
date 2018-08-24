/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:07:35 by prussell          #+#    #+#             */
/*   Updated: 2017/06/08 15:23:58 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		beg;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	beg = 0;
	while (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t')
		beg++;
	end = ft_strlen(s) - 1;
	while (end > beg && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	dst = ft_strnew(end - beg + 1);
	if (dst)
	{
		i = 0;
		end++;
		while (beg < end)
			dst[i++] = s[beg++];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}

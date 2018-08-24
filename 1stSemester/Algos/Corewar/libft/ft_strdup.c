/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:16:38 by prussell          #+#    #+#             */
/*   Updated: 2017/05/31 15:07:02 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}

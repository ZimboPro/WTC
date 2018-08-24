/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:21:17 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:54 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		valid_param(char *param)
{
	return (ft_strstr(param, "-dump") != NULL ||
				ft_strstr(param, "-n") != NULL ||
				ft_strstr(param, ".cor") != NULL ||
				ft_isnumber(param));
}

int		is_valid_params(char **params)
{
	int	i;
	int	file_found;

	i = 1;
	file_found = 0;
	while (params[i])
	{
		if (ft_strstr(params[i], "-dump") != NULL)
		{
			if (params[i + 1] && !ft_isnumber(params[i + 1]))
				return (0);
		}
		else if (ft_strstr(params[i], "-n") != NULL)
		{
			if ((params[i + 1] && !ft_isnumber(params[i + 1])) ||
					(params[i + 2] && ft_strstr(params[i + 2], ".cor") == NULL))
				return (0);
		}
		else if (ft_strstr(params[i], ".cor") != NULL)
			file_found = 1;
		else if (!valid_param(params[i]))
			return (0);
		i++;
	}
	return (file_found);
}

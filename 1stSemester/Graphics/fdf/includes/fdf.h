/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:26:31 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/30 15:25:59 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_p
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			x0;
	int			y0;
}				t_p;

typedef struct	s_count
{
	int			i;
	int			j;
}				t_count;

void			ft_draw(int **pts, t_p *m, char *s);
int				**ft_read(char *str, int **pts, int *y, int *x);
int				ft_open(char *str);

#endif

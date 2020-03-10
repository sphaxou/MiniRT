/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:21 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/10 21:54:10 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*rt_render(t_mlx *mlx, t_rtlst *cam)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx->x)
	{
		y = 0;
		while (y < mlx->y)
		{
			printf("x %d y %d\n", x, y);
			rt_cast(x, y, mlx, cam);
			y++;
		}
		x++;
	}
	return (NULL);
}

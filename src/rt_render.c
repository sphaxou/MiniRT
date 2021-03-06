/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:21 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 21:43:15 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*rt_render(t_mlx *mlx)
{
	t_rtlst	*cur;
	int		x;
	int		y;

	x = 0;
	while (x < mlx->x)
	{
		y = 0;
		while (y < mlx->y)
		{
		//	printf("render start\n");
			cur = rt_cast(x, y, mlx);
			rt_put_pixel(mlx, cur, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}

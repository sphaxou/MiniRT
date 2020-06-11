/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 21:02:05 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 22:00:14 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

int		rt_get_color(t_mlx *mlx, t_rtlst *cur)
{
	int	rgb;
	(void)mlx;
//	printf("rgb calc %d\n", cur);
	rgb = cur ? 65536 * cur->r + 256 * cur->g + cur->b : 0;
	printf("rgb done %d\n", rgb);
	return (rgb);
}

void	rt_put_pixel(t_mlx *mlx, t_rtlst *cur, float x, float y)
{
//	printf("start put pixel\n");
	mlx_pixel_put(mlx->ptr, mlx->win, x, y, rt_get_color(mlx, cur));
//	printf("end put pixel\n");
}

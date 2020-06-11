/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:31:25 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 21:45:00 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

float	rt_intersect_sphere(t_mlx *mlx, t_rtlst *obj)
{
	float	a1;
	float	a2;
	float	a;
	float	b;
	float	c;
	float	delta;

//	printf("inter sp");
	a = mlx->vx * mlx->vx + mlx->vy * mlx->vy + mlx->vz * mlx->vz;
	b = 2 * (mlx->vx * (mlx->cam->x - obj->x) + mlx->vy * (mlx->cam->y - obj->y)
			+ mlx->vz * (mlx->cam->z - obj->z));
	c = (mlx->cam->x - obj->x) * (mlx->cam->x - obj->x) + (mlx->cam->y - obj->y)
		* (mlx->cam->y - obj->y) + (mlx->cam->z - obj->z)
		* (mlx->cam->z - obj->z)
		- obj->dia * obj->dia / 4;
	delta = b * b - 4 * a * c;
//	printf("%.2f %.2f %.2f\n", a, b,c);
	if (delta < 0)
		return (0);
	if (!delta)
		return (-b / 2 * a >= 0 ? -b / 2 * a : 0);
	a1 = (-b - sqrt(delta)) / 2 * a;
	a2 = (-b + sqrt(delta)) / 2 * a;
	a1 = a1 > 0 ? a1 : a2;
	a2 = a2 > 0 ? a2 : a1;
	return (a1 < a2 ? a1 : a2);
}

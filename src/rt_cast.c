/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:29:18 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/10 22:32:42 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	rt_intersect(t_rtlst ray, t_rtlst *obj, float alpha)
{
	if (!obj)
		return (alpha);
	if (obj->id == 1)
		alpha = rt_intersect_sphere(ray, obj, alpha);
	return (rt_intersect(ray, obj->next, alpha));
}

void	rt_cast(float x, float y, t_mlx *mlx, t_rtlst *cam)
{
	float	alpha;
	t_rtlst	ray;

	printf("mlx->x %d\tx: %f\t", mlx->x, x);
	ray.vx = x - (float)mlx->x / 2;
	ray.vy = y - (float)mlx->y / 2;
	ray.vz = cam->fov;
	rt_rot(&ray, cam);
	printf("cam x: %.0f\n", cam->x);
	ray.x = cam->x;
	ray.y = cam->y;
	ray.z = cam->z;
	printf("vx %.02f vy %.02f vz %.02f\tx %.2f y %.2f z %.2f\n", ray.vx, ray.vy, ray.vz, ray.x, ray.y, ray.z);
	alpha = rt_intersect(ray, mlx->obj, MAX_DIST);
	printf("alpha = %f\n", alpha);
}

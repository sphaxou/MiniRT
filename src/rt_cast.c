/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:29:18 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 21:54:44 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rtlst	*rt_intersect(t_mlx *mlx, t_rtlst *obj, t_rtlst *cur)
{
	if (!obj)
		return (cur);
	if (!cur)
		cur = obj;
//	printf("%d\n", obj->id);
	if (obj->id == 1)
		obj->dist = rt_intersect_sphere(mlx, obj);
	if (obj->dist)
		printf("%f\n", obj->dist);
	if (obj->dist && obj->dist < cur->dist)
		cur = obj;
//	printf("%p\n", obj->next);
	return (rt_intersect(mlx, obj->next, cur));
}

t_rtlst	*rt_cast(float x, float y, t_mlx *mlx)
{
	t_rtlst	*cur;

	mlx->vx = x - mlx->x / 2;
	mlx->vy = y - mlx->y / 2;
	mlx->vz = mlx->cam->fov;
	cur = rt_intersect(mlx, mlx->obj, NULL);
	if (cur)
		printf("cast done\n");
	return (cur);
}

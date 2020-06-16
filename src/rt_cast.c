/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:29:18 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/16 19:55:51 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_calcdist(t_mlx *mlx, t_rtlst *obj)
{
	if (!obj)
		return ;
	obj->dist = 0;
		if (obj->id == 1)
			obj->dist = rt_intersect_sphere(mlx, obj);
		if (obj->id == 2)
			obj->dist = rt_intersect_plane(mlx, obj);
	rt_calcdist(mlx, obj->next);
}

t_rtlst *take_closest(t_rtlst *obj)
{
	t_rtlst *tmp;
	float	dist;

	tmp = NULL;
	dist = 0;
	while (obj)
	{
		if (obj->dist > 0 && (dist > obj->dist || !dist))
		{
			dist = obj->dist;
			tmp = obj;
		}
		obj = obj->next;
	}
	return (tmp);
}

t_rtlst	*rt_intersect(t_mlx *mlx, t_rtlst *obj)
{
	if (!obj)
		return (NULL);
	rt_calcdist(mlx, obj);
	return (take_closest(obj));
}

t_rtlst	*rt_cast(float x, float y, t_mlx *mlx)
{
	t_rtlst	*cur;

	mlx->vx = x - mlx->x / 2;
	mlx->vy = y - mlx->y / 2;
	mlx->vz = mlx->cam->fov;
	cur = rt_intersect(mlx, mlx->obj);
	return (cur);
}

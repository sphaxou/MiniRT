/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:12:47 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/16 19:24:48 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	rt_intersect_plane(t_mlx *mlx, t_rtlst *obj)
{
	float ln;
	float t;

	ln = mlx->vx * obj->vx + mlx->vy * obj->vy + mlx->vz * obj->vz;
	if (!ln)
		return (0);
	t = ((obj->x - mlx->cam->x) * obj->vx
		+ (obj->y - mlx->cam->y) * obj->vy
		+ (obj->z - mlx->cam->z) * obj->vz) / ln;
	return (t);
}

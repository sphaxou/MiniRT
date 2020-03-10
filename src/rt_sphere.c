/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:31:25 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/10 21:49:11 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

static float minthree(float a, float b, float c)
{
	a = a < b ? a : b;
	return (a < c ? a : c);
}

float	rt_intersect_sphere(t_rtlst ray, t_rtlst *obj, float alpha)
{
	float	a1;
	float	a2;
	float	a;
	float	b;
	float	c;
	float	delta;

	printf("inter sp");
	a = ray.vx * ray.vx + ray.vy * ray.vy + ray.vz * ray.vz;
	b = 2 * (ray.vx * (ray.x - obj->x) + ray.vy * (ray.y - obj->y)
			+ ray.vz * (ray.z - obj->z));
	c = (ray.x - obj->x) * (ray.x - obj->x) + (ray.y - obj->y)
		* (ray.y - obj->y) + (ray.z - obj->z) * (ray.z - obj->z)
		- obj->dia * obj->dia / 4;
	delta = b * b - 4 * a * c;
	printf("%.2f %.2f %.2f\n", a, b,c);
	if (delta < 0)
		return (alpha);
	if (!delta)
		return (-b / 2 * a >= 0 ? -b / 2 * a : alpha);
	a1 = (-b - sqrt(delta)) / 2 * a;
	a2 = (-b + sqrt(delta)) / 2 * a;
	a1 = a1 > 0 ? a1 : alpha;
	a2 = a2 > 0 ? a2 : alpha;
	return (minthree(a1, a2, alpha));
}

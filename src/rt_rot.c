/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:35:46 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/10 21:35:13 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

void		rt_rx(t_rtlst *lst, float x)
{
	t_rtlst	tmp;
	tmp.x = lst->vx;
	tmp.y = lst->vy * cos(x) - lst->vz * sin(x);
	tmp.z = lst->vy * sin(x) + lst->vz * cos(x);
	lst->vx = tmp.x;
	lst->vy = tmp.y;
	lst->vz = tmp.z;
}
void		rt_ry(t_rtlst *lst, float y)
{
	t_rtlst	tmp;
	tmp.x = lst->vx * cos(y) + lst->vz * sin(y);
	tmp.y = lst->vy;
	tmp.z = lst->vx * -sin(y) + lst->vz * cos(y);
	lst->vx = tmp.x;
	lst->vy = tmp.y;
	lst->vz = tmp.z;
}
void		rt_rz(t_rtlst *lst, float z)
{
	t_rtlst	tmp;
	tmp.x = lst->vx * cos(z) - lst->vy * sin(z);
	tmp.y = lst->vx * sin(z) + lst->vy * cos(z);
	tmp.z = lst->vz;
	lst->vx = tmp.x;
	lst->vy = tmp.y;
	lst->vz = tmp.z;
}
void		rt_rot(t_rtlst *lst, t_rtlst *angle)
{
	rt_rx(lst, angle->vx);
	rt_ry(lst, angle->vy);
	rt_rz(lst, angle->vz);
}
void		rt_anti_rot(t_rtlst *lst, t_rtlst *angle)
{
	rt_rz(lst, -angle->vz);
	rt_ry(lst, -angle->vy);
	rt_rx(lst, -angle->vx);
}

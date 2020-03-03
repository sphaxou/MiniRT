/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:32:40 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/03 14:27:16 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"
#include "libft.h"

char	*g_err = NULL;
void	checkobj_sp(t_rtlst *lst)
{
	printf("sphere\n%f %f %f\ndia %f rgb %x\n", lst->x, lst->y, lst->z, lst->dia, lst->rgb);
}

void	plane(t_rtlst *lst)
{
	printf("plane\n%f %f %f\nv: %f %f %f\nrgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->rgb);
}

void	square(t_rtlst *lst)
{
	printf("square\n%f %f %f\nv: %f %f %f\nh%f rgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->h, lst->rgb);
}

void	cy(t_rtlst *lst)
{
	printf("cy\n%f %f %f\nv: %f %f %f\ndia %f h %f rgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->dia, lst->h, lst->rgb);
}

void	triangle(t_rtlst *lst)
{
	printf("triangle\n1: %f %f %f\n2: %f %f %f\n3: %f %f %f\nrgb %x\n", lst->x, lst->y, lst->z, lst->x2, lst->y2, lst->z2, lst->x3, lst->y3, lst->z3, lst->rgb);
}

void	checkobj(t_rtlst *lst)
{
	if (!lst)
		return ;
	if (lst->id == 1)
		checkobj_sp(lst);
	if (lst->id == 2)
		plane(lst);
	if (lst->id == 3)
		square(lst);
	if (lst->id == 4)
		cy(lst);
	if (lst->id == 5)
		triangle(lst);
	checkobj(lst->next);
}

void	checklum(t_rtlst *lst)
{
	if (!lst)
		return ;
	printf("lum\n%f %f %f\nint: %f rgb: %x\n", lst->x, lst->y, lst->z, lst->ratio, lst->rgb);
	checklum(lst->next);
}

void	checkcam(t_rtlst *lst)
{
	if (!lst)
		return ;
	printf("cam\n%f %f %f\n%f %f %f\nfov %d\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->fov);
	checkcam(lst->next);
}

void	check(t_mlx *mlx)
{
	printf("%p\n%p\na %f r %d rgb %x x %d y %d\n", mlx->ptr, mlx->win, mlx->a, mlx->r, mlx->rgb, mlx->x, mlx->y);
	checkcam(mlx->cam);
	checkobj(mlx->obj);
	checklum(mlx->lum);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = NULL;
	(void)av;
	if (ac != 2 && ac != 3)
		return (0);
	if (ac == 2)
	{
		if (!(mlx = rt_init(av[1])))
			return (0);
		check(mlx);
		mlx_key_hook(mlx->win, rt_hook_keydown, mlx->ptr);
		mlx_loop(mlx->ptr);
	}
	return (0);
}

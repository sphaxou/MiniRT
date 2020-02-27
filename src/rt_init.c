/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:48:01 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/27 18:42:53 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>
#include <stdlib.h>
#include "minirt.h"

t_mlx	*rt_init(char *name)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	if ((g_err = rt_parse(mlx, name)))
	{
		ft_putstr(g_err);
		return (NULL);
	}
	mlx->win = mlx_new_window(mlx->ptr, mlx->x, mlx->y, name);
	return (mlx);
}

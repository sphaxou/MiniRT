/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:08:13 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/27 18:09:39 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

char		*rt_parse_l(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3])
		return ("File error\n");
	tmp = rt_lstnew();
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getrgb(&tmp, split[3])))
		return (g_err);
	tmp->ratio = ft_atof(split[2]);
	rt_lstaddback(&mlx->lum, tmp);
	return (NULL);
}

char		*rt_parse_sp(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!(tmp = rt_lstnew()))
		return ("Malloc error\n");
	tmp->id = 1;
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getrgb(&tmp, split[3])))
		return (g_err);
	tmp->dia = ft_atof(split[2]);
	rt_lstaddback(&mlx->obj, tmp);
	return (NULL);
}

char		*rt_parse_p(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3])
		return ("File error\n");
	if (!(tmp = rt_lstnew()))
		return ("Malloc error\n");
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getvect(&tmp, split[2]))
			|| (g_err = rt_getrgb(&tmp, split[3])))
		return (g_err);
	tmp->id = 2;
	rt_lstaddback(&mlx->obj, tmp);
	return (NULL);
}

char		*rt_parse_sq(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3] ||!split[4] || !(tmp = rt_lstnew()))
		return ("File error\n");
	tmp->id = 3;
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getvect(&tmp, split[2]))
			|| (g_err = rt_getrgb(&tmp, split[4])))
		return (g_err);
	tmp->h = ft_atof(split[3]);
	rt_lstaddback(&mlx->obj, tmp);
	return (NULL);
}

char		*rt_parse_cy(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3] ||!split[4] || !split[5]
			|| !(tmp = rt_lstnew()))
		return ("File error\n");
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getvect(&tmp, split[2]))
			|| (g_err = rt_getrgb(&tmp, split[5])))
		return (g_err);
	tmp->id = 4;
	tmp->dia = ft_atof(split[3]);
	tmp->h = ft_atof(split[4]);
	rt_lstaddback(&mlx->obj, tmp);
	return (NULL);
}

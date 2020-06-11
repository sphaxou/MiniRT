/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:03:41 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 14:32:36 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

char	*rt_getrgb(t_rtlst **lst, char *s)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (!(split = ft_split(s, ',')) || !split[0] || !split[1] || !split[2])
		return ("Color error\n");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 | b > 255 || b < 0)
	{
		rt_deletesplit(split);
		return ("Color error\n");
	}
	(*lst)->r = r;
	(*lst)->g = g;
	(*lst)->b = b;
	rt_deletesplit(split);
	return (NULL);
}

char	*rt_getxyz(t_rtlst **lst, char *s)
{
	char	**split;

	if (!(split = ft_split(s, ',')) || !split[0] || !split[1] || !split[2])
		return ("Coord error\n");
	(*lst)->x = ft_atof(split[0]);
	(*lst)->y = ft_atof(split[1]);
	(*lst)->z = ft_atof(split[2]);
	rt_deletesplit(split);
	return (NULL);
}

char	*rt_getvect(t_rtlst **lst, char *s)
{
	char	**split;

	if (!(split = ft_split(s, ',')) || !split[0] || !split[1] || !split[2])
		return ("Vector error\n");
	(*lst)->vx = ft_atof(split[0]);
	(*lst)->vy = ft_atof(split[1]);
	(*lst)->vz = ft_atof(split[2]);
	rt_deletesplit(split);
	return (((*lst)->vx >= -1 && (*lst)->vx <= 1 && (*lst)->vy >= -1
			&& (*lst)->vy <= 1 && (*lst)->vz >= -1 && (*lst)->vz <= 1
			&& ((*lst)->vx || (*lst)->vy || (*lst)->vz))
			? NULL : "Vector value error\n");
}

char	*rt_parse_t(t_mlx *mlx, char **split)
{
	char	***tab;
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5]
			|| !(tab = malloc(sizeof(*tab) * 3))
			|| !(tab[0] = ft_split(split[2], ','))
			|| !(tab[1] = ft_split(split[3], ',')) || !tab[0][0] || !tab[0][1]
			|| !tab[0][2] || !tab[1][0] || !tab[1][1] || !tab[1][2]
			|| !(tmp = rt_lstnew()))
		return ("File g_err\n");
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getrgb(&tmp, split[4])))
		return (g_err);
	tmp->id = 5;
	tmp->x2 = ft_atof(tab[0][0]);
	tmp->y2 = ft_atof(tab[0][1]);
	tmp->z2 = ft_atof(tab[0][2]);
	tmp->x3 = ft_atof(tab[1][0]);
	tmp->y3 = ft_atof(tab[1][1]);
	tmp->z3 = ft_atof(tab[1][2]);
	rt_deletesplit(tab[0]);
	rt_deletesplit(tab[1]);
	rt_lstaddback(&mlx->obj, tmp);
	free(tab);
	return (NULL);
}

char	*rt_parse_bn(t_mlx *mlx, char **split)
{
	(void)mlx;
	(void)split;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:30:07 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/10 22:34:07 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>
#include "libft.h"
#include <unistd.h>

void	rt_deletesplit(char **split)
{
	int		i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

char		*rt_parse_r(t_mlx *mlx, char **split)
{
	printf("%d\n", mlx->r);
	if (mlx->r)
		return ("Multiple R\n");
	if (!split[1] || !split[2])
		return ("File render size missing\n");
	mlx->r = 1;
	mlx->x = ft_atoi(split[1]);
	mlx->y = ft_atoi(split[2]);
	return (NULL);
}

char		*rt_parse_a(t_mlx *mlx, char **split)
{
	char	**tab;

	if (mlx->a || !split[1] || !split[2] || split[3])
		return ("File g_err\n");
	if (!(tab = ft_split(split[2], ',')))
		return ("Malloc g_err\n");
	if (!tab[0] || !tab[1] || !tab[2])
		return ("File g_err\n");
	mlx->a = ft_atof(split[1]);
	printf("%f\n", mlx->a);
	mlx->rgb = ft_atoi(tab[0]) * 65536 + ft_atoi(tab[1]) * 256
			+ ft_atoi(tab[2]);
	rt_deletesplit(tab);
	return ((mlx->a >= 0 && mlx->a <= 1) ? NULL : "Ambiant light error\n");
}

char		*rt_parse_cam(t_mlx *mlx, char **split)
{
	t_rtlst	*tmp;

	if (!split[1] || !split[2] || !split[3] || split[4])
		return ("File error\n");
	tmp = rt_lstnew();
	if (!tmp)
		return ("File g_err\n");
	if ((g_err = rt_getxyz(&tmp, split[1]))
			|| (g_err = rt_getvect(&tmp, split[2])))
		return (g_err);
	tmp->fov = ft_atoi(split[3]);
	rt_lstaddback(&mlx->cam, tmp);
	return ((tmp->fov > 0 && tmp->fov <= 180) ? NULL : "Camera Error\n");
}

char		*rt_parse(t_mlx *mlx, char *name)
{
	int		fd;
	char	*line;
	int		gnl;
	char	**split;
	t_funct	f;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return ("Open error\n");
	while ((gnl = get_next_line(fd, &line)))
	{
		printf("%s a = %f\n", line, mlx->a);
		if (gnl == -1)
			g_err = "GNL error\n";//penser a clean les donnees precedentes
		if (!(f = rt_get_funct(line)))
			g_err = "Funct error\n";
		if (!g_err && !(split = ft_split(line, ' ')))
			return ("Split error\n");
		free(line);
		if (g_err || (g_err = f(mlx, split)))
			return (g_err);
		rt_deletesplit(split);
	}
	printf("fin gnl\n");
	close(fd);
	return (0);
}

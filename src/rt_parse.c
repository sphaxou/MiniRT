/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:30:07 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/27 18:12:07 by vgallois         ###   ########.fr       */
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

	if (mlx->a || !split[1] || !split [2])
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
	return (NULL);
}

char		*rt_parse_cam(t_mlx *mlx, char **split)
{
	char	**tab;
	char	**tab2;

	if (!split[1] || !split[2] || !split[3])
		return ("File g_err\n");
	if (!(tab = ft_split(split[1], ',')) || !(tab2 = ft_split(split[2], ',')))
		return ("Malloc g_err\n");
	if (!tab[0] || !tab[1] || !tab[2] || !tab2[0] || !tab2[1] || !tab2[2])
	{
			rt_deletesplit(tab);
			rt_deletesplit(tab);
		return ("File g_err\n");
	}
	mlx->cam.x = ft_atof(tab[0]);
	mlx->cam.y = ft_atof(tab[1]);
	mlx->cam.z = ft_atof(tab[2]);
	mlx->cam.vx = ft_atof(tab2[0]);
	mlx->cam.vy = ft_atof(tab2[1]);
	mlx->cam.vz = ft_atof(tab2[2]);
	mlx->cam.fov = ft_atoi(split[3]);
	rt_deletesplit(tab2);
	rt_deletesplit(tab);
	return (NULL);
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

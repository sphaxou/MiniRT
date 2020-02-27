/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:37:26 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/27 18:10:34 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>

/*
** id des objets:
** 1 sphere
** 2 plan
** 3 carre
** 4 cylindre
** 5 triangle
*/

typedef struct		s_rtlst
{
	float			x;
	float			y;
	float			z;
	float			x2;
	float			y2;
	float			z2;
	float			x3;
	float			y3;
	float			z3;
	int				rgb;
	int				id;
	float			vx;
	float			vy;
	float			vz;
	float			dia;
	float			ratio;
	float			h;
	struct s_rtlst	*next;
}					t_rtlst;

typedef struct		s_cam
{
	float			x;
	float			y;
	float			z;
	float			vx;
	float			vy;
	float			vz;
	int				fov;
}					t_cam;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	float			a;
	int				r;
	int				rgb;
	int				x;
	int				y;
	t_cam			cam;
	t_rtlst			*obj;
	t_rtlst			*lum;
}					t_mlx;

extern	char		*g_err;

typedef char		*(*t_funct)(t_mlx *mlx, char **split);
t_mlx				*rt_init(char *name);

t_funct				rt_get_funct(char *s);
char				*rt_parse(t_mlx *mlx, char *name);
char				*rt_parse_r(t_mlx *mlx, char **split);
char				*rt_parse_a(t_mlx *mlx, char **split);
char				*rt_parse_cy(t_mlx *mlx, char **split);
char				*rt_parse_cam(t_mlx *mlx, char **split);
char				*rt_parse_l(t_mlx *mlx, char **split);
char				*rt_parse_sp(t_mlx *mlx, char **split);
char				*rt_parse_sq(t_mlx *mlx, char **split);
char				*rt_parse_p(t_mlx *mlx, char **split);
char				*rt_parse_t(t_mlx *mlx, char **split);
char				*rt_parse_bn(t_mlx *mlx, char **spliti);
char				*rt_getxyz(t_rtlst **lst, char *line);
char				*rt_getvect(t_rtlst **lst, char *line);
char				*rt_getrgb(t_rtlst **lst, char *line);
void				rt_deletesplit(char **split);
t_rtlst				*rt_lstnew(void);
void				rt_lstaddback(t_rtlst **alst, t_rtlst *new);
t_rtlst				*rt_lstlast(t_rtlst *lst);

int					rt_hook_keydown(int key, t_mlx *mlx);

#endif

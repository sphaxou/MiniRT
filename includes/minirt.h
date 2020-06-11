/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:37:26 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 21:21:59 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>
# define MAX_DIST 10000.0
/*
** id des objets:
** 1 sphere
** 2 plan
** 3 carre
** 4 cylindre
** 5 triangle
*/

typedef struct		s_vect
{
	float			vx;
	float			vy;
	float			vz;
}					t_vect;

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
	int				r;
	int				g;
	int				b;
	int				id;
	float			vx;
	float			vy;
	float			vz;
	float			dia;
	float			ratio;
	float			h;
	int				fov;
	float			dist;
	struct s_rtlst	*next;
}					t_rtlst;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	float			a;
	int				res;
	int				r;
	int				g;
	int				b;
	int				x;
	int				y;
	float			vx;
	float			vy;
	float			vz;
	t_rtlst			*cam;
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

char				*rt_check_r(t_mlx *mlx);
char				*rt_check_a(t_mlx *mlx);
char				*rt_check_cam(t_rtlst *lst);
char				*rt_check_l(t_rtlst *lst);
char				*rt_check_obj(t_rtlst *lst);

void				rt_rot(t_rtlst *lst, t_rtlst *angle);
void				rt_anti_rot(t_rtlst *lst, t_rtlst *angle);

char				*rt_render(t_mlx *mlx);
float				rt_intersect_sphere(t_mlx *mlx, t_rtlst *obj);
t_rtlst				*rt_cast(float x, float y, t_mlx *mlx);
void				rt_put_pixel(t_mlx *mlx, t_rtlst *cur, float x, float y);
t_rtlst				*rt_lstnew(void);
void				rt_lstaddfront(t_rtlst **alst, t_rtlst *new);
void				rt_lstaddback(t_rtlst **alst, t_rtlst *new);
t_rtlst				*rt_lstlast(t_rtlst *lst);

int					rt_hook_keydown(int key, t_mlx *mlx);

#endif

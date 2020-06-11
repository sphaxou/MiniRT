/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:45:32 by vgallois          #+#    #+#             */
/*   Updated: 2020/06/11 16:41:51 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

static void	create_tab(t_funct *tab)
{
	tab['R'] = rt_parse_r;
	tab['A'] = rt_parse_a;
	tab['c'] = rt_parse_cy;
	tab['l'] = rt_parse_l;
	tab['s'] = rt_parse_sp;
	tab['S'] = rt_parse_sq;
	tab['p'] = rt_parse_p;
	tab['C'] = rt_parse_cam;
	tab['t'] = rt_parse_t;
	tab['\n'] = rt_parse_bn;
}

t_funct		rt_get_funct(char *s)
{
	static t_funct	*tab = NULL;

	if (!tab)
	{
		if (!(tab = ft_memalloc(sizeof(t_funct) * 256)))
			return (NULL);
		create_tab(tab);
	}
	if (*s != 's' && *s != 'c')
		return (tab[(int)(*s)]);
	if (*s == 's')
		return (tab[s[1] == 'p' ? 's' : 'S']);
	if (*s == 'c')
		return (tab[s[1] == 'y' ? 'c' : 'C']);
	return (NULL);
}

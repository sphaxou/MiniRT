/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:25:50 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/24 18:53:32 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include <stdlib.h>
#include "minirt.h"

int	rt_hook_keydown(int key, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

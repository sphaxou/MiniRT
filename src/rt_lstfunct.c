/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lstfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:15:40 by vgallois          #+#    #+#             */
/*   Updated: 2020/03/03 14:28:56 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

t_rtlst	*rt_lstnew()
{
	t_rtlst	*new;

	if (!(new = ft_memalloc(sizeof(t_rtlst))))
		return (NULL);
	return (new);
}

void	rt_lstaddback(t_rtlst **alst, t_rtlst *new)
{
	t_rtlst	*lst;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	lst = *alst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	rt_lstaddfront(t_rtlst **alst, t_rtlst *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}


t_rtlst	*rt_lstlast(t_rtlst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

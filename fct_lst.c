/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:23 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/14 17:42:09 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_add_x(t_position *begin_list)
{
	t_position  *point;

	point = begin_list;
	while (begin_list)
	{
		begin_list->x++;
		begin_list = begin_list->next;
	}
}

void    ft_add_y(t_position *begin_list)
{
	t_position  *point;

	point = begin_list;
	while (begin_list)
	{
		begin_list->y++;
		begin_list->x = begin_list->x; //nbr de deplacement
			begin_list = begin_list->next;
	}
}

t_position          *new_position(int x, int y)
{
	t_position  *position;

	if (!(position = (t_position *)malloc(sizeof(t_position))))
		return (0);
	position->x = x;
	position->y = y;
	position->next = NULL;
	return (position);
}

t_position          *ft_itopos(t_position *pos, int i, int j)
{
	pos->x = i;
	pos->y = j;
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:48:05 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/13 20:50:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_position			*new_position(int x, int y)
{
	t_position	*position;

	if (!(position = (t_position *)malloc(sizeof(t_position))))
		return (0);
	position->x = x;
	position->y = y;
	return (position);
}

t_position			*ft_itopos(t_position *pos, int i, int j)
{
	pos->x = i;
	pos->y = j;
	return (pos);
}

int					ft_are_pos_adj(t_tetri *tetri, t_position *p2)
{
	int i;
	t_position *p1;
	
	p1 = tetri->pa;
	if((p1->x == p2->x + 1 || p1->x == p2->x - 1 || p1->y == p2->y + 1 || p1->y == p2->y - 1))
		return (1);
	p1 = tetri->pb;
	if((p1->x == p2->x + 1 || p1->x == p2->x - 1 || p1->y == p2->y + 1 || p1->y == p2->y - 1))
		return (1);
	p1 = tetri->pc;
	if((p1->x == p2->x + 1 || p1->x == p2->x - 1 || p1->y == p2->y + 1 || p1->y == p2->y - 1))
		return (1);
	p1 = tetri->pd;
	if((p1->x == p2->x + 1 || p1->x == p2->x - 1 || p1->y == p2->y + 1 || p1->y == p2->y - 1))
		return (1);
	return (0);
}

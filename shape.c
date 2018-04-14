/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:05:36 by fedecomb          #+#    #+#             */
/*   Updated: 2018/04/14 20:59:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_frame_check(char **frame, t_tetri *elem, int x, int y)
{
	int cpx;
	int cpy;
	int good = 0;
	cpx = x;
	cpy = y;
write(1, "check\n", 6);
	while (frame[cpy])
	{
//ft_putnbr(elem->pd->x);
//write(1, '\n', 1);
		while (frame[cpy][cpx] && !good)
		{
			if(ft_check_and_place(frame, elem, cpx, cpy))
			{
				ft_frame_remove(frame, elem,cpx, cpy);
				write(1, "j en ai place 1\n", 16);
				if(ft_frame_check(frame, elem->next, cpx, cpy))
					return 1;
				ft_frame_remove(frame, elem,cpx, cpy);
			}
			cpx++;
		}
		cpx = 0;
		cpy++;
	}
	return 0;
	
}

int		ft_check_and_place(char **frame, t_tetri *elem, int x, int y)
{
	int size;
	t_position *p;

	size = ft_strlen(*frame);
	p = elem->pa;
	while (p)
	{
		if (frame[p->y + y][p->x + x] == '.' && p->x + x < size && p->y + y < size)
			p = p->next;
		else
			return (0);
	}
	p = elem->pa;
	while (p)
	{
		frame[p->y + y][p->x + x] = elem->letter;
		p = p->next;
	}
ft_map_print(frame);
	return (1);
}

void	ft_frame_remove(char **frame, t_tetri *elem, int x, int y)
{
	t_position *p;

write(1,'Q', 1);
	p = elem->pa;
	while (p)
	{
		frame[p->y + y][p->x + x] = '.';
		p = p->next;
	}
}



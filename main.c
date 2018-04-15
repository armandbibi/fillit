/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/15 14:52:17 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char ** av)
{
	int			fd;
	char		*s;
	int			ret;
	t_tetri		*lst_tetri;
	int 		size;
	char 		**map;

	size = 4;
	s = ft_readfd(av[1]);
	if((close(fd))<0)
		return 0;
	map = ft_map_new(size);
	lst_tetri = ft_atotet(s, 'A');
	ft_remove_extra_spaces(lst_tetri);
	//ft_putnbr(lst_tetri->pa->y);
	while((!ft_frame_check(map, lst_tetri, 0, 0)))
	{
		ft_map_free(map);
		map = ft_map_new(size++);
	}
	ft_map_print(map);
}

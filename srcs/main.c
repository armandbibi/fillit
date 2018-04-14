/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/14 14:27:25 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int main(int ac, char ** av)
{
	int		fd;
	char	*s;
	int		ret;
	t_tetri		*lst_tetri;

	s = ft_readfd(av[1]);
	if((close(fd))<0)
		return 0;
	lst_tetri = ft_atotet(s);

	ft_putchar(lst_tetri->pc->y + 48);
	while(lst_tetri)
	{
		ft_remove_extra_spaces(lst_tetri);
		printf("TETRI:\npa:%d %d\n", lst_tetri->pa->x, lst_tetri->pa->y);
		printf("pb:%d %d\n", lst_tetri->pb->x, lst_tetri->pb->y);
		printf("pc:%d %d\n", lst_tetri->pc->x, lst_tetri->pc->y);
		printf("pd:%d %d\n", lst_tetri->pd->x, lst_tetri->pd->y);
		lst_tetri = lst_tetri->next;
	}
}

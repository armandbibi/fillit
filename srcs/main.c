/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/13 16:17:53 by abiestro         ###   ########.fr       */
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
	
	t_position  *p = new_position(0, 5);
	ft_itopos(p, 18);
	printf("%d, %d", p->x, p->y);

	
}

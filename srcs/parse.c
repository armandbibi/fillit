/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/12 16:01:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZ 21 * 26
#include "../includes/fillit.h"

char			*ft_readfd(char *str)
{
	char	block[BUF_SIZ];
	int		fd;
	int		size;
	char	*dup;

	fd = open(str, O_RDONLY);
	if  ((size = (read(fd, block, BUF_SIZ))))
	{
		dup = ft_strnew(ft_strlen(block));
		 ft_strncpy(dup, block, ft_strlen(block));
	}
	return (dup);
}

t_tetri			*ft_atotet(char *str)
{
	t_tetri		*tetri;

	tetri = new_tetri();
	if (ft_tetri_check(tetri, str))
	{
		str += BUF_SIZ;
		tetri->next = ft_atotet(str);
	}
	else
	{
		free(tetri->pa);
		free(tetri->pb);
		free(tetri->pc);
		free(tetri->pd);
		free(tetri);
		tetri = NULL;
	}
	return (tetri);
}

t_tetri			*ft_tetri_check(t_tetri *tetri, char *str)
{
	t_position	*p;
	int			i;

	i = 0;
	p = new_position(-2, -2);
	while (str[i] == '.' || str[i] == '#' || (str[i] == '\n' && str[i] - 1 != '\n' ))
	{
	}
}

t_tetri			*new_tetri(void)
{
	t_tetri		*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	tetri->pa = new_position(-2, -2);
	tetri->pb = new_position(-2, -2);
	tetri->pc = new_position(-2, -2);
	tetri->pd = new_position(-2, -2);
	tetri->placed = 0;
	tetri->next = NULL;
	return (tetri);
}

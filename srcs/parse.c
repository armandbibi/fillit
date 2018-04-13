/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/13 16:17:51 by abiestro         ###   ########.fr       */
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
	if (ft_tetri_add_pos(tetri, str) && (ft_is_tetri_valid(tetri)))
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

t_tetri			*ft_tetri_add_pos(t_tetri *tetri, char *str)
{
	int i;
	int countht;

	i = 0;
	countht = 0;
	while (i < 21)
	{
		if (((i % 5) && str[i] == '\n') || ((i % 5) && str[i] != '\n'))
			return (0);
		else if (str[i] == '#')
		{
			if (countht == 0)
			{
				tetri->pa = ft_itopos(tetri->pa, i);
				countht++;
			}
			else if (countht == 1)
			{
				tetri->pb = ft_itopos(tetri->pb, i);
				countht++;
			}
			else if (countht == 2)
			{
				tetri->pc = ft_itopos(tetri->pc, i);
				countht++;
			}
			else if (countht == 3)
			{
				tetri->pd = ft_itopos(tetri->pd, i);
				countht++;
			}
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (tetri);
}

int				ft_is_tetri_valid(t_tetri *tetri)
{
	int i;

	i = 0;
	i += ft_are_pos_adj(tetri, tetri->pa);
	i += ft_are_pos_adj(tetri, tetri->pb);
	i += ft_are_pos_adj(tetri, tetri->pc);
	i += ft_are_pos_adj(tetri, tetri->pd);
	return (i);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/15 14:53:29 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZ 21 * 26
#include "fillit.h"

char					*ft_readfd(char *str)
{
	char	block[BUF_SIZ];
	int		fd;
	int		size;
	char	*dup;

	fd = open(str, O_RDONLY);
	if ((size = (read(fd, block, BUF_SIZ))))
	{
		dup = ft_strnew(ft_strlen(block));
		ft_strncpy(dup, block, ft_strlen(block));
	}
	return (dup);
}

t_tetri					*ft_atotet(char *str, char letter)
{
	t_tetri		*tetri;

	tetri = new_tetri();
	if (ft_tetri_add_pos(tetri, str) && (ft_is_tetri_valid(tetri)))
	{
		tetri->letter = letter;
		str = &str[21];
		if (*str != 0)
		{
			tetri->next = ft_atotet(str, letter + 1);
		}
	}
	else
	{
		printf("apprends a finir correctement\n");
		free(tetri->pa);
		free(tetri->pb);
		free(tetri->pc);
		free(tetri->pd);
		free(tetri);
		tetri = NULL;
	}
	return (tetri);
}

t_tetri					*ft_tetri_add_pos(t_tetri *tetri, char *str)
{
	int i;
	int j;
	int k;

	t_position *p = tetri->pa;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			k = i * 5 + j;
			if (str[k] != '\n' && str[k] != '.' && str[k] != '#')
				return (0);
			if (j && ((j && str[k - 1] == '\n') || (!j && str[k - 1] != '\n')))
				return (0);
			if (str[k] == '#')
			{
				if (tetri->pa)
				{
					ft_itopos(tetri->pa,j, i);
					tetri->pa = tetri->pa->next;

				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	tetri->pa = p;
	return (tetri);
}

int						ft_is_tetri_valid(t_tetri *tetri)
{
	if (ft_are_pos_adj(tetri, tetri->pa)
			&& ft_are_pos_adj(tetri, tetri->pb)
			&& ft_are_pos_adj(tetri, tetri->pc)
			&& ft_are_pos_adj(tetri, tetri->pd))
		return (1);
	return (0);
}

t_tetri					*new_tetri(void)
{
	t_tetri		*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	tetri->pa = new_position(-2, -2);
	tetri->pb = new_position(-2, -2);
	tetri->pc = new_position(-2, -2);
	tetri->pd = new_position(-2, -2);
	tetri->pa->next = tetri->pb;
	tetri->pb->next = tetri->pc;
	tetri->pc->next = tetri->pd;
	tetri->pd->next = NULL;
	tetri->placed = 0;
	tetri->next = NULL;
	return (tetri);
}

void					ft_remove_extra_spaces(t_tetri *tetri)
{
	t_tetri *copie;
	copie = tetri;
	while (tetri)
	{
		while (tetri->pa->x && tetri->pb->x && tetri->pc->x && tetri->pd->x)
		{
			tetri->pa->x--;
			tetri->pb->x--;
			tetri->pc->x--;
			tetri->pd->x--;
		}
		while (tetri->pa->y && tetri->pb->y && tetri->pc->y && tetri->pd->y)
		{
			tetri->pa->y--;
			tetri->pb->y--;
			tetri->pc->y--;
			tetri->pd->y--;
		}
		tetri = tetri->next;
	}
	tetri = copie;
}

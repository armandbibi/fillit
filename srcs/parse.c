/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/13 21:20:02 by abiestro         ###   ########.fr       */
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
		str = &str[21];
		if(*str != 0)
		{
			printf("next\n");
			tetri->next = ft_atotet(str);
		}
		else
			printf("sorti correcte\n");
	}
	else
	{
		printf("appreds a finir correctement\n");
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
	int j;
	int k;
printf("new tetri\n");
	i = 0;
	countht = 0;
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
				if (countht == 0)
				{
printf("1 = %d, %d\n",i,j);
					ft_itopos(tetri->pa, i, j);
					countht++;
				}
				else if (countht == 1)
				{
printf("1 = %d, %d\n",i,j);
					ft_itopos(tetri->pb, i, j);
					countht++;
				}
				else if (countht == 2)
				{
printf("1 = %d, %d\n",i,j);
					ft_itopos(tetri->pc, i, j);
					countht++;
				}
				else if (countht == 3)
				{
printf("1 = %d, %d\n",i,j);
					ft_itopos(tetri->pd, i, j);
					countht++;
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (tetri);
}

int				ft_is_tetri_valid(t_tetri *tetri)
{
	if (ft_are_pos_adj(tetri, tetri->pa) && ft_are_pos_adj(tetri, tetri->pb)
			&& ft_are_pos_adj(tetri, tetri->pc) && ft_are_pos_adj(tetri, tetri->pd))
		return (1);
	return (0);
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

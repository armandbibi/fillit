/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/13 16:07:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct      s_position
{
	int x;
	int y;
}                   t_position;

typedef struct		s_tetri
{
	t_position		*pa;
	t_position		*pb;
	t_position		*pc;
	t_position		*pd;
	int				placed;
	struct s_tetri	*next;
}					t_tetri;

char				*ft_readfd(char *str);



void				ft_fdtotetris(int fd);
t_tetri				*ft_atotet(char *str);
t_tetri				*new_tetri(void);
t_tetri				*ft_tetri_add_pos(t_tetri *tetri, char *);
int					ft_is_tetri_valid(t_tetri *tetri);

t_position			*new_position(int x, int y);
t_position			*ft_itopos(t_position *pos,int i);
int					ft_are_pos_adj(t_tetri *t, t_position *p);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:16:28 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/20 10:16:29 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "Get_next_line/get_next_line.h"
# include "Libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_CPE
{
	int	c;
	int	p;
	int	e;
}	t_cpe;

typedef struct s_map
{
	int		nb_l;
	int		nb_c;
	char	**map;
	t_cpe	cpe;
}	t_map;

//init
void	ft_init_cpe(t_map *map);
void	ft_nb_l(int fd, t_map *map);
char	**ft_recup_map(int fd, int nb_l);

//verif_map
int		ft_ber(char *str);
int		ft_verif_cpe(t_map *map);
int		ft_verif_one_line(char *str);
int		ft_verif_line(char *str, int nb_c);
int		ft_verif_map(char *file, t_map *map);

//clear
void	ft_mapclear(t_map *map);

#endif

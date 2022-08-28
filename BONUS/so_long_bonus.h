/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:16:28 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 15:28:53 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../Get_next_line/get_next_line.h"
# include "../Libft/libft.h"

# define RIGHT 'P'
# define LEFT 'L'
# define BLOOD 'B'
# define BLOOD_RIGHT 'F'
# define BLOOD_LEFT 'G'
# define YELLOW_RIGHT 'Y'
# define YELLOW_LEFT 'Q'
# define YELLOW_K 'K'
# define YELLOW_KL 'H'

typedef struct s_CPE
{
	int	c;
	int	p;
	int	e;
}	t_cpe;

typedef struct s_pos
{
	int	c;
	int	l;
}	t_pos;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	int		nb_l;
	int		nb_c;
	int		cpt;
	char	**map;
	t_cpe	cpe;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
}	t_game;

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

//cpt
void	ft_cpt(t_map *map, int l, int c);

//swap
void	ft_do_left_right(t_game *game, int l, int c, t_pos *pos);
void	ft_left_right(t_game *game, t_pos *pos, int key);
void	ft_knife(t_game *game, t_pos *pos, t_pos *pat);
int		ft_case_ok(char c);
void	ft_exit_open(t_game *game);

//key
void	ft_pos(t_map *map, t_pos *pos);
void	ft_domov(char *map_av, char *map_ap, char av);
int		ft_putmov(t_game *game, int l, int c, t_pos *pos);
void	ft_mov(t_game *game, t_pos *pos, t_pos *pat, int key);
int		ft_key(int key, t_game *game);

//display
void	*image_bonus(int elem, t_mlx *mlx);
void	image(int elem, int nb_l, int nb_c, t_mlx *mlx);
void	ft_display(t_map *map, t_mlx *mlx);
void	ft_display_bis(t_map *map, t_mlx *mlx, t_pos *pos);

//patrouille
void	ft_pos_pat(t_map *map, t_pos *pos);
char	ft_patmv(int mv, char pat);
void	ft_patmov(char *map_av, char *map_ap, char av, char ap);
void	ft_tourne(t_pos *pat, t_map *map);
void	ft_patrouille(t_pos *pos, t_pos *pat, t_map *map);

//main
void	ft_game(t_map *map);

//clear
void	ft_mapclear(t_map *map);
void	ft_stop(t_map *map, void *mlx);
void	ft_destroy(t_game *game);
int		ft_cross(t_game *game);

void	ft_affiche(t_game *game);

#endif

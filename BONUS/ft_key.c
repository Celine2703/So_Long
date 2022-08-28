/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:34:12 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 15:45:33 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_pos(t_map *map, t_pos *pos)
{
	int		c;
	int		l;

	l = 0;
	while (map ->map[l])
	{
		c = 0;
		while (map ->map[l][c])
		{
			if (map ->map[l][c] == 'P' || map ->map[l][c] == 'F'
				|| map ->map[l][c] == 'L' || map ->map[l][c] == BLOOD_LEFT)
			{
				pos ->c = c;
				pos ->l = l;
				return ;
			}
			c++;
		}
		l++;
	}
	pos ->c = -1;
	pos ->l = -1;
}

void	ft_domov(char *map_av, char *map_ap, char av)
{
	if (*map_av == 'P')
		*map_ap = 'F';
	else
		*map_ap = BLOOD_LEFT;
	*map_av = av;
}

int	ft_putmov(t_game *game, int l, int c, t_pos *pos)
{
	t_map	*map;

	map = game ->map;
	ft_cpt(map, l, c);
	if (map ->map[l][c] == 'O' || map ->map[l][c] == 'Y')
		return (ft_putnbr_fd(++map ->cpt, 1), ft_destroy(game), 1);
	else if (map ->map[l][c] == '1' || map ->map[l][c] == 'E')
		return (0);
	else if ((map ->map[l][c] == 'C' && map->cpe.c--) || map->map[l][c] == 'B')
		return (ft_domov(&(map->map[pos->l][pos->c]), &(map->map[l][c]), '0'),
			1);
	else if (map ->map[l][c] == '0')
		return (ft_do_left_right(game, l, c, pos), 1);
	return (0);
}

void	ft_mov(t_game *game, t_pos *pos, t_pos *pat, int key)
{
	t_map	*map;
	int		mov;

	map = game ->map;
	mov = 0;
	if (key == 'w' && pos ->l)
		mov = ft_putmov(game, pos ->l - 1, pos ->c, pos);
	else if (key == 'a' && pos ->c)
		mov = ft_putmov(game, pos ->l, pos ->c - 1, pos);
	else if (key == 's' && pos ->l != map ->nb_l)
		mov = ft_putmov(game, pos ->l + 1, pos ->c, pos);
	else if (key == 'd' && pos ->c != map ->nb_c)
		mov = ft_putmov(game, pos ->l, pos ->c + 1, pos);
	ft_left_right(game, pos, key);
	if (pos ->c == -1)
		return ;
	if (map ->cpt % 2 && mov == 1)
		ft_patrouille(pos, pat, map);
	ft_knife(game, pos, pat);
	ft_affiche(game);
	if (!(map ->cpe.c))
		ft_exit_open(game);
}

int	ft_key(int key, t_game *game)
{
	t_pos	pos;
	t_pos	pat;

	ft_pos(game ->map, &pos);
	ft_pos_pat(game ->map, &pat);
	if (key == 65307)
		ft_destroy(game);
	ft_mov(game, &pos, &pat, key);
	ft_pos(game ->map, &pos);
	if (pos.c == -1)
		ft_destroy(game);
	ft_display_bis(game ->map, game ->mlx, &pos);
	ft_display_bis(game ->map, game ->mlx, &pat);
	return (0);
}

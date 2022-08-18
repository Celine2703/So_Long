/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:34:12 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/18 16:44:56 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_game *game)
{
	t_pos	pos;

	ft_pos(game ->map, &pos);
	if (key == 65307)
		ft_destroy(game);
	ft_mov(game, &pos, key);
	ft_display(game ->map, game ->mlx);
	return (0);
}

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
			if (map ->map[l][c] == 'P')
			{
				pos ->c = c;
				pos ->l = l;
				return ;
			}
			c++;
		}
		l++;
	}
}

void	ft_putmov(t_game *game, int l, int c, t_pos *pos)
{
	t_map	*map;

	map = game ->map;
	if (map ->map[l][c] == 'C')
	{
		map ->map[l][c] = 'S';
		map ->cpe.c --;
		map ->map[pos ->l][pos ->c] = '0';
	}
	else if (map ->map[l][c] == 'E')
	{
		if (!(map ->cpe.c))
			ft_destroy(game);
		return ;
	}
	else if (map ->map[l][c] == '1')
		map ->map[pos ->l][pos ->c] = 'P';
	else
	{
		map ->map[l][c] = 'P';
		map ->map[pos ->l][pos ->c] = '0';
	}
}

void	ft_mov(t_game *game, t_pos *pos, int key)
{
	t_map	*map;

	map = game ->map;
	if (key == 'w' && pos ->l)
		ft_putmov(game, pos ->l - 1, pos ->c, pos);
	else if (key == 'a' && pos ->c)
		ft_putmov(game, pos ->l, pos ->c - 1, pos);
	else if (key == 's' && pos ->l != map ->nb_l)
		ft_putmov(game, pos ->l + 1, pos ->c, pos);
	else if (key == 'd' && pos ->c != map ->nb_c)
		ft_putmov(game, pos ->l, pos ->c + 1, pos);
	else
		map ->map[pos ->l][pos ->c] = 'P';
}

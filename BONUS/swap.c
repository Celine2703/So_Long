/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:16:40 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/27 17:53:47 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_do_left_right(t_game *game, int l, int c, t_pos *pos)
{
	t_map *map;

	map = game ->map;
	if (map ->map[pos ->l][pos ->c] == BLOOD_RIGHT)
	{
		map ->map[pos ->l][pos ->c] = BLOOD;
		map ->map[l][c] = RIGHT;
	}
	else if (map ->map[pos ->l][pos ->c] == BLOOD_LEFT)
	{
		map ->map[pos ->l][pos ->c] = BLOOD;
		map ->map[l][c] = LEFT;
	}
	else
	{
		map ->map[l][c] = map ->map[pos ->l][pos ->c];
		map ->map[pos ->l][pos ->c] = '0';
	}
}

void	ft_left_right(t_game *game, t_pos *pos, int key)
{
	t_map	*map;

	map = game ->map;
	ft_pos(map, pos);
	if (key == 'a' && map ->map[pos ->l][pos ->c] == RIGHT)
		map ->map[pos ->l][pos ->c] = 'L';
	else if (key == 'd' && map ->map[pos ->l][pos ->c] == LEFT)
		map ->map[pos ->l][pos ->c] = 'P';
	else if (key == 'a' && map ->map[pos ->l][pos ->c] == BLOOD_RIGHT)
		map ->map[pos ->l][pos ->c] = BLOOD_LEFT;
	else if (key == 'd' && map ->map[pos ->l][pos ->c] == BLOOD_LEFT)
		map ->map[pos ->l][pos ->c] = BLOOD_RIGHT;
}

void	ft_exit_open(t_game *game)
{
	int		c;
	int		l;
	t_map	*map;

	map = game ->map;
	l = 0;
	while (map ->map[l])
	{
		c = 0;
		while (map ->map[l][c])
		{
			if (map ->map[l][c] == 'E')
			{
				map ->map[l][c] = 'O';
				image(map ->map[l][c], l, c, game ->mlx);
				return ;
			}
			c++;
		}
		l++;
	}
}

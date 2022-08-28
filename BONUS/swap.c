/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:16:40 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 15:42:13 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_do_left_right(t_game *game, int l, int c, t_pos *pos)
{
	t_map	*map;

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
		map ->map[pos ->l][pos ->c] = LEFT;
	else if (key == 'd' && map ->map[pos ->l][pos ->c] == LEFT)
		map ->map[pos ->l][pos ->c] = RIGHT;
	else if (key == 'a' && map ->map[pos ->l][pos ->c] == BLOOD_RIGHT)
		map ->map[pos ->l][pos ->c] = BLOOD_LEFT;
	else if (key == 'd' && map ->map[pos ->l][pos ->c] == BLOOD_LEFT)
		map ->map[pos ->l][pos ->c] = BLOOD_RIGHT;
}

void	ft_knife(t_game *game, t_pos *pos, t_pos *pat)
{
	t_map	*map;

	map = game ->map;
	ft_pos_pat(map, pat);
	if (pos->c - pat->c <= 1 && pos->c - pat->c >= -1 && pos->l - pat->l <= 1
		&& pos->l - pat->l >= -1)
	{
		if (map->map[pat->l][pat->c] == YELLOW_RIGHT)
			map->map[pat->l][pat->c] = YELLOW_K;
		else if (map->map[pat->l][pat->c] == YELLOW_LEFT)
			map->map[pat->l][pat->c] = YELLOW_KL;
	}
	else
	{
		if (map->map[pat->l][pat->c] == YELLOW_K)
			map->map[pat->l][pat->c] = YELLOW_RIGHT;
		else if (map->map[pat->l][pat->c] == YELLOW_KL)
			map->map[pat->l][pat->c] = YELLOW_LEFT;
	}
}

int	ft_case_ok(char c)
{
	if (c == '0' || c == 'P' || c == 'L' || c == BLOOD_RIGHT || c == BLOOD_LEFT)
		return (1);
	return (0);
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

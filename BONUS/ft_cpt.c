/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:51 by cmartin-          #+#    #+#             */
/*   Updated: 2022/09/02 14:47:05 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_cpt(t_game *game, int l, int c)
{
	t_map 	*map;
	char	*string;

	map = game ->map;
	if (map ->map[l][c] != '1' && map ->map[l][c] != 'E')
	{
		string = ft_itoa(++map ->cpt);
		image(map ->map[0][0], 0, 0, game ->mlx);
		mlx_string_put(game ->mlx ->mlx, game -> mlx ->win, 3, 10, 0x00FF0000, string);
		free(string);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:13:25 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/19 13:34:24 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapclear(t_map *map)
{
	int	i;

	map ->nb_l = 0;
	map ->nb_c = 0;
	if (!map ->map)
		return ;
	i = 0;
	while (map ->map[i])
	{
		free(map ->map[i]);
		i++;
	}
	free(map ->map);
}

void	ft_stop(t_map *map, void *mlx)
{
	ft_mapclear(map);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	ft_destroy(t_game *game)
{
	ft_mapclear(game ->map);
	mlx_destroy_window(game ->mlx ->mlx, game ->mlx ->win);
	mlx_destroy_display(game ->mlx ->mlx);
	free(game ->mlx ->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_cross(t_game *game)
{
	ft_destroy(game);
	return (0);
}
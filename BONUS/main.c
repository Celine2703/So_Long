/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:41:29 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 10:39:12 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_game(t_map *map)
{
	t_mlx	mlx;
	t_game	game;
	int		x;
	int		y;

	game.map = map;
	game.map ->cpt = 0;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (ft_stop(map, mlx.mlx));
	mlx_get_screen_size(mlx.mlx, &x, &y);
	if (map ->nb_c * 64 > x || map ->nb_l * 64 > y)
	{
		write (2, "Error\nTaille non valide\n", 24);
		return (ft_stop(map, mlx.mlx));
	}
	mlx.win = mlx_new_window(mlx.mlx,
			64 * map ->nb_c, 64 * map ->nb_l, "so_long");
	game.mlx = &mlx;
	ft_display(map, &mlx);
	mlx_key_hook (mlx.win, ft_key, &game);
	mlx_hook(mlx.win, 17, 0, ft_cross, &game);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		if (!argv[1])
			return (write(2, "Error\nFichier absent\n", 21), 0);
		else if (ft_verif_map(argv[1], &map))
			return (0);
		else
			ft_game(&map);
	}
	else
		write(2, "Error\nIl faut un fichier\n", 24);
}

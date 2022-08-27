/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:41:29 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/27 17:40:18 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image(int elem, int nb_l, int nb_c, t_mlx *mlx)
{
	void	*image;
	int		a;

	if (elem == '1')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/wall.xpm", &a, &a);
	else if (elem == '0')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/sol.xpm", &a, &a);
	else if (elem == 'P')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/right.xpm", &a, &a);
	else if (elem == 'L')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/left.xpm", &a, &a);
	else if (elem == 'C')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/collect.xpm", &a, &a);
	else if (elem == 'F')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/b_right.xpm", &a, &a);
	else if (elem == BLOOD_LEFT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/b_left.xpm", &a, &a);
	else if (elem == 'B')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/blood.xpm", &a, &a);
	else if (elem == 'O')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/exit.xpm", &a, &a);
	else
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/exit_c.xpm", &a, &a);
	mlx_put_image_to_window(mlx ->mlx, mlx ->win, image, nb_c * 64, nb_l * 64);
	mlx_destroy_image(mlx ->mlx, image);
}

void	ft_display(t_map *map, t_mlx *mlx)
{
	int		nb_l;
	int		nb_c;

	nb_l = 0;
	while (map ->map[nb_l])
	{
		nb_c = 0;
		while (map ->map[nb_l][nb_c])
		{
			image(map ->map[nb_l][nb_c], nb_l, nb_c, mlx);
			nb_c++;
		}
		nb_l++;
	}
}

void	ft_display_bis(t_map *map, t_mlx *mlx, t_pos *pos)
{
	image(map ->map[pos ->l][pos ->c], pos ->l, pos ->c, mlx);
	image(map ->map[pos ->l - 1][pos ->c], pos ->l - 1, pos ->c, mlx);
	image(map ->map[pos ->l + 1][pos ->c], pos ->l + 1, pos ->c, mlx);
	image(map ->map[pos ->l][pos ->c - 1], pos ->l, pos ->c - 1, mlx);
	image(map ->map[pos ->l][pos ->c + 1], pos ->l, pos ->c + 1, mlx);
}

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

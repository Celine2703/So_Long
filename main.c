/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:41:29 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/19 13:42:10 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

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
	else if (elem == 'C')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/collectible.xpm", &a, &a);
	else
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/exit.xpm", &a, &a);
	mlx_put_image_to_window(mlx ->mlx, mlx ->win, image,nb_c * 64, nb_l * 64);
}

void	ft_display(t_map *map)
{
	t_mlx	mlx;
	int		nb_l;
	int		nb_c;
	
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1900, 1000, "so_long");
	nb_l = 0;
	while (map ->map[nb_l])
	{
		nb_c = 0;
		while (map ->map[nb_l][nb_c])
		{
			image(map ->map[nb_l][nb_c], nb_l, nb_c, &mlx);
			nb_c++;
		}
		nb_l++;
	}
	
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc == 2)
	{
		if(!argv[1])
			return (write(2, "Error\nFichier absent\n", 21), 0);
		else if (ft_verif_map(argv[1], &map))
			return (0);
		else
			ft_display(&map);
	}
	else
		write(2, "Error\nIl faut un fichier\n", 24);
}
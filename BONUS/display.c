/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:39:33 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 13:10:27 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*image_bonus(int elem, t_mlx *mlx)
{
	void	*image;
	int		a;

	if (elem == 'O')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/exit.xpm", &a, &a);
	else if (elem == YELLOW_RIGHT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/Yellow.xpm", &a, &a);
	else if (elem == YELLOW_LEFT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/Yellow_l.xpm", &a, &a);
	else if (elem == YELLOW_K)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/Yellow_k.xpm", &a, &a);
	else if (elem == YELLOW_KL)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/Yellow_kl.xpm", &a, &a);
	return (image);
}

void	image(int elem, int nb_l, int nb_c, t_mlx *mlx)
{
	void	*image;
	int		a;

	if (elem == '1')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/wall.xpm", &a, &a);
	else if (elem == '0')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/sol.xpm", &a, &a);
	else if (elem == RIGHT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/right.xpm", &a, &a);
	else if (elem == LEFT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/left.xpm", &a, &a);
	else if (elem == 'C')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/collect.xpm", &a, &a);
	else if (elem == BLOOD_RIGHT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/b_right.xpm", &a, &a);
	else if (elem == BLOOD_LEFT)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/b_left.xpm", &a, &a);
	else if (elem == BLOOD)
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/blood.xpm", &a, &a);
	else if (elem == 'E')
		image = mlx_xpm_file_to_image(mlx ->mlx, "tiles/exit_c.xpm", &a, &a);
	else
		image = image_bonus(elem, mlx);
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

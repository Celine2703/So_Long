/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:00:36 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/20 10:00:38 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] != 'r' || str[i--] != 'e' || str[i--] != 'b' || str[i] != '.')
		return (write(2, "Error\nNom de fichier non valide\n", 32), 1);
	return (0);
}

int	ft_verif_cpe(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map ->map[i])
	{
		j = 0;
		while (map ->map[i][j])
		{
			if (map ->map[i][j] == 'C')
				map ->cpe.c ++;
			if (map ->map[i][j] == 'P')
				map ->cpe.p ++;
			if (map ->map[i][j] == 'E')
				map ->cpe.e ++;
			j++;
		}
		i++;
	}
	if (map ->cpe.c && map ->cpe.p && map ->cpe.e)
		return (0);
	return (write(2, "Error\nIl faut au moins un C, un P et un E\n", 42), 1);
}

int	ft_verif_one_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (write(2, "Error\nIl faut un mur en haut et en bas\n", 39), 1);
		i++;
	}
	return (i);
}

int	ft_verif_line(char *str, int nb_c)
{
	int	i;

	if (str[0] != '1')
		return (write(2, "Error\nIl faut un mur a gauche\n", 30), 1);
	i = 1;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E')
			return (write(2, "Error\nElement inconnu\n", 22), 1);
		i++;
	}
	i--;
	if (str[i] != '1')
		return (write(2, "Error\nIl faut un mur a doite\n", 29), 1);
	if (i + 1 != nb_c)
		return (write(2, "Error\nLa map doit etre un rectangle\n", 36), 1);
	return (0);
}

int	ft_verif_map(char *file, t_map *map)
{
	int		fd;
	int		i;

	if (!file || ft_ber(file))
		return (1);
	fd = open(file, O_RDONLY);
	ft_nb_l(fd, map);
	fd = open(file, O_RDONLY);
	map ->map = ft_recup_map(fd, map ->nb_l);
	if (fd == -1 || !map ->map)
		return (ft_mapclear(map), write(2, "Error\nFichier absent\n", 25), 1);
	map ->nb_c = ft_verif_one_line(map ->map[0]);
	ft_init_cpe(map);
	i = 0;
	while (map ->map[i])
		if (ft_verif_line(map ->map[i++], map ->nb_c))
			return (ft_mapclear(map), 1);
	if (ft_verif_cpe(map) || ft_verif_one_line(map ->map[0]) <= 1
		|| ft_verif_one_line(map ->map[map ->nb_l - 1]) <= 1)
		return (ft_mapclear(map), 1);
	return (0);
}

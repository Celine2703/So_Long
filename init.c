/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:14:33 by cmartin-          #+#    #+#             */
/*   Updated: 2022/09/02 15:48:52 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_cpe(t_map *map)
{
	map ->cpe.c = 0;
	map ->cpe.p = 0;
	map ->cpe.e = 0;
}

void	ft_nb_l(int fd, t_map *map)
{
	char	*line;
	int		cpt;

	if (fd == -1)
		return ;
	line = get_next_line(fd);
	cpt = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		cpt++;
	}
	free(line);
	line = 0;
	close(fd);
	map ->nb_l = cpt - 1;
}

char	**ft_recup_map(int fd, int nb_l)
{
	char	**map;
	char	*line;
	int		i;

	if (!nb_l || fd == -1)
		return (0);
	map = ft_calloc(sizeof(char *), nb_l + 1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	line = 0;
	return (map);
}

void	ft_init_map(t_map *map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map ->map[i])
	{
		j = 0;
		while (map ->map[i][j])
		{
			if (map ->map[i][j] == 'P' && p++ > 0)
				map ->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

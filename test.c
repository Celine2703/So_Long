/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:52:58 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/18 15:07:04 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_affiche(t_game *game)
{
	int	c;
	int	l;

	l = 0;
	while (game ->map ->map[l])
	{
		c = 0;
		while (game ->map ->map[l][c])
		{
			printf("%c", game ->map ->map[l][c]);
			c++;
		}
		printf("\n");
		l++;
	}
}

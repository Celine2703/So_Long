/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrouille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:03:00 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/28 15:12:18 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_pos_pat(t_map *map, t_pos *pos)
{
	int		c;
	int		l;

	l = 0;
	while (map ->map[l])
	{
		c = 0;
		while (map ->map[l][c])
		{
			if (map ->map[l][c] == 'Y' || map ->map[l][c] == YELLOW_K
				|| map ->map[l][c] == YELLOW_LEFT
					|| map ->map[l][c] == YELLOW_KL)
			{
				pos ->c = c;
				pos ->l = l;
				return ;
			}
			c++;
		}
		l++;
	}
}

char	ft_patmv(int mv, char pat)
{
	if (mv == 'l' || pat == YELLOW_KL)
		return (YELLOW_LEFT);
	else if (mv == 'r' || pat == YELLOW_K)
		return (YELLOW_RIGHT);
	else
		return (pat);
}

void	ft_patmov(char *map_av, char *map_ap, char av, char ap)
{
	*map_av = av;
	*map_ap = ap;
}

void	ft_tourne(t_pos *pat, t_map *map)
{
	if (ft_case_ok(map ->map[pat ->l][pat ->c - 1]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l][pat->c - 1]),
			'0', ft_patmv('l', map->map[pat ->l][pat ->c]));
	else if (ft_case_ok(map ->map[pat ->l][pat ->c + 1]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l][pat->c + 1]),
			'0', ft_patmv('r', map->map[pat ->l][pat ->c]));
	else if (ft_case_ok(map ->map[pat ->l - 1][pat ->c]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l - 1][pat->c]),
			'0', ft_patmv('i', map->map[pat ->l][pat ->c]));
}

void	ft_patrouille(t_pos *pos, t_pos *pat, t_map *map)
{
	if (pos ->c < pat ->c && ft_case_ok(map ->map[pat ->l][pat ->c - 1]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l][pat->c - 1]),
			'0', ft_patmv('l', map->map[pat ->l][pat ->c]));
	else if (pos ->c > pat ->c && ft_case_ok(map ->map[pat ->l][pat ->c + 1]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l][pat->c + 1]),
			'0', ft_patmv('r', map->map[pat ->l][pat ->c]));
	else if (pos ->l < pat ->l && ft_case_ok(map ->map[pat ->l - 1][pat ->c]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l - 1][pat->c]),
			'0', ft_patmv('i', map->map[pat ->l][pat ->c]));
	else if (ft_case_ok(map ->map[pat ->l + 1][pat ->c]))
		ft_patmov(&(map ->map[pat->l][pat->c]), &(map->map[pat->l + 1][pat->c]),
			'0', ft_patmv('i', map->map[pat ->l][pat ->c]));
	else
		ft_tourne(pat, map);
}

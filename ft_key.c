/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:34:12 by cmartin-          #+#    #+#             */
/*   Updated: 2022/08/18 12:09:04 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int touche, void *game)
{
	if (touche == 65307)
	{
		ft_destroy(game);
		return (touche);
	}
	printf("%dAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n", touche);
	return (touche);
}

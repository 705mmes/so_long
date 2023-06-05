/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:04 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/05 18:54:33 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_hitbox(t_game *game, int x, int y)
{
	int	i;
	int	u;

	i = -1;
	u = -1;
	while (game->map->array[++i])
	{
		while (game->map->array[i][++u])
		{
			if ((x < (u * TS + TS))
				&& ((x + game->p->width) > (u * TS))
				&& (y < (i * TS + TS))
				&& ((y + game->p->height) > (i * TS))
				&& game->map->array[i][u] == '1')
				return (1);
		}
		u = -1;
	}
	return (0);
}

int	nb_ct(char **map)
{
	int	i;
	int	u;
	int	r;

	r = 0;
	u = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				r++;
			u++;
		}
		u = 0;
		i++;
	}
	return (r);
}

void	find_spawn(int	*i, int	*u, char **map)
{
	while (map[++(*i)])
	{
		while (map[*i][++(*u)])
		{
			if (map[*i][*u] == 'S')
				return ;
		}
		*u = -1;
	}
}

int	check_hitbox_c(t_game	*g, int c_c, int p_x, int p_y)
{
	if ((p_x < (g->c[c_c]->x + TS))
		&& ((p_x + g->p->width) > (g->c[c_c]->x))
		&& (p_y < (g->c[c_c]->y + TS))
		&& ((p_y + g->p->height) > (g->c[c_c]->y))
		&& (g->c[c_c]->is_collected == false))
		return (0);
	return (1);
}

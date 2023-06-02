/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:12 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/01 14:27:16 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_collectibles(char	**map, t_game	*g)
{
	int	i;
	int	u;
	int	j;

	i = -1;
	u = -1;
	j = -1;
	g->c = malloc(sizeof(t_collectibles *) * nb_ct(map) + 1);
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'C')
			{
				g->c[++j] = init_collectibles(g, i, u);
			}
		}
		u = -1;
	}
	g->c[j] = 0;
}

t_collectibles	*init_collectibles(t_game	*g, int i, int u)
{
	t_collectibles	*c;

	c = malloc(sizeof(t_collectibles));
	c->x = u * 64;
	c->y = i * 64;
	c->img = mlx_texture_to_image(g->mlx, g->textures[1]);
	c->is_collected = false;
	mlx_image_to_window(g->mlx, c->img, c->x + 16, c->y + 16);
	return (c);
}

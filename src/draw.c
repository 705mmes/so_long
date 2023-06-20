/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:12 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/06 13:56:06 by sammeuss         ###   ########.fr       */
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
	g->c = malloc(sizeof(t_collectibles *) * ((nb_ct(map) + 1)));
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'C')
				g->c[++j] = init_collectibles(g, i, u);
		}
		u = -1;
	}
	g->c[j + 1] = 0;
}

void	draw_map(char	**map, t_game *game)
{
	int			i;
	int			u;
	mlx_image_t	*floor;
	mlx_image_t	*wall;

	i = -1;
	u = -1;
	wall = mlx_texture_to_image(game->mlx, game->textures[3]);
	floor = mlx_texture_to_image(game->mlx, game->textures[2]);
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == '0' || map[i][u] == 'S'
				|| map[i][u] == 'C' || map[i][u] == 'E')
				mlx_image_to_window(game->mlx, floor, (u * TS), (i * TS));
			else if (map[i][u] == '1')
				mlx_image_to_window(game->mlx, wall, (u * TS), (i * TS));
		}
		u = -1;
	}
	draw_exit_and_player(map, game);
}

void	draw_exit_and_player(char **map, t_game *g)
{
	int			i;
	int			u;

	i = -1;
	u = -1;
	g->p->img = mlx_texture_to_image(g->mlx, g->textures[0]);
	g->e->img = mlx_texture_to_image(g->mlx, g->textures[4]);
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'E')
			{
				mlx_image_to_window(g->mlx, g->e->img, (u * TS) + 36, (i * TS));
				g->e->x = u * TS;
				g->e->y = i * TS;
			}
			if (map[i][u] == 'S')
				mlx_image_to_window(g->mlx, g->p->img, (u * TS), (i * TS));
		}
		u = -1;
	}
	draw_collectibles(map, g);
}

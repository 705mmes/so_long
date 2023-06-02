/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_and_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:40 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/01 14:07:39 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*init_game(void)
{
	t_game	*s_l;

	printf("1");
	s_l = malloc(sizeof(t_game));
	s_l->map = malloc(sizeof(t_map));
	s_l->p = malloc(sizeof(t_player));
	s_l->mlx = NULL;
	s_l->p->height = 61;
	s_l->p->width = 64;
	init_textures(s_l);
	return (s_l);
}

void	init_textures(t_game *game)
{
	game->textures = malloc(sizeof(mlx_texture_t *) * 6);
	game->textures[0] = mlx_load_png("./images/biker.png");
	game->textures[1] = mlx_load_png("./images/collectibles.png");
	game->textures[2] = mlx_load_png("./images/outdoor_floor.png");
	game->textures[3] = mlx_load_png("./images/brick_walls.png");
	game->textures[4] = mlx_load_png("./images/exit.png");
	game->textures[5] = NULL;
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
	printf("drawing\n");
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
	mlx_image_t	*exit;

	i = -1;
	u = -1;
	g->p->img = mlx_texture_to_image(g->mlx, g->textures[0]);
	exit = mlx_texture_to_image(g->mlx, g->textures[4]);
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'E')
				mlx_image_to_window(g->mlx, exit, (u * TS) + 36, (i * TS));
			if (map[i][u] == 'S')
				mlx_image_to_window(g->mlx, g->p->img, (u * TS), (i * TS));
		}
		u = -1;
	}
	draw_collectibles(map, g);
}

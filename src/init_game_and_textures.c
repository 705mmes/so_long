/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_and_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:40 by sammeuss          #+#    #+#             */
/*   Updated: 2023/07/03 15:12:03 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*init_game(void)
{
	t_game	*s_l;

	s_l = malloc(sizeof(t_game));
	s_l->map = malloc(sizeof(t_map));
	s_l->p = malloc(sizeof(t_player));
	s_l->e = malloc(sizeof(t_exit));
	s_l->mlx = NULL;
	s_l->p->height = 61;
	s_l->p->width = 64;
	s_l->game_on = false;
	s_l->p->count_c = 0;
	s_l->p->score = 0;
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

void	free_necessary(t_game *game)
{	
	if (game->map->array)
		free_map(game);
	else if (game->map)
		free(game->map);
	if (game->e)
		free(game->e);
	if (game->p)
		free(game->p);
	if (game->textures)
		free_textures(game);
	free(game);
}

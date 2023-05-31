/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_and_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:40 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/31 11:25:36 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start(t_game	*game)
{
	int	width;
	int	height;

	width = ft_strlen(game->map->array[0]);
	height = ft_array_len(game->map->array);
	printf("starting\n");
	game->mlx = mlx_init(width * T_S, height * T_S, "MLX42", true);
	draw_map(game->map->array, game);
	mlx_loop_hook(game->mlx, hook, game);
	mlx_loop(game->mlx);
}

void	*init_game(void)
{
	t_game	*so_long;

	so_long = malloc(sizeof(t_game));
	so_long->map = malloc(sizeof(t_map));
	so_long->mlx = NULL;
	so_long->p = malloc(sizeof(t_player));
	so_long->p->height = 61;
	so_long->p->width = 64;
	init_textures(so_long);
	return (so_long);
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
				mlx_image_to_window(game->mlx, floor, (u * T_S), (i * T_S));
			else if (map[i][u] == '1')
				mlx_image_to_window(game->mlx, wall, (u * T_S), (i * T_S));
		}
		u = -1;
	}
	draw_collectibles_exit_and_player(map, game);
}

void	draw_collectibles_exit_and_player(char **map, t_game *g)
{
	int			i;
	int			u;
	mlx_image_t	*exit;
	mlx_image_t	*ct;

	i = -1;
	u = -1;
	g->p->img = mlx_texture_to_image(g->mlx, g->textures[0]);
	exit = mlx_texture_to_image(g->mlx, g->textures[4]);
	ct = mlx_texture_to_image(g->mlx, g->textures[1]);
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'C')
				mlx_image_to_window(g->mlx, ct, (u * T_S) + 16, (i * T_S) + 16);
			if (map[i][u] == 'E')
				mlx_image_to_window(g->mlx, exit, (u * T_S) + 36, (i * T_S));
			if (map[i][u] == 'S')
				mlx_image_to_window(g->mlx, g->p->img, (u * T_S), (i * T_S));
		}
		u = -1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runnin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:19:32 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/02 09:59:23 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start(t_game	*game)
{
	int	width;
	int	height;

	width = ft_strlen(game->map->array[0]);
	height = ft_array_len(game->map->array);
	game->mlx = mlx_init(width * TS, height * TS, "MLX42", true);
	draw_map(game->map->array, game);
	mlx_loop_hook(game->mlx, main_hook, game);
	mlx_loop_hook(game->mlx, collectibles_hook, game);
	mlx_loop(game->mlx);
}

void	main_hook(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->p->img->instances[0].x;
	y = game->p->img->instances[0].y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& check_hitbox(game, x, y - 2) == 0)
		game->p->img->instances[0].y -= 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& check_hitbox(game, x, y + 2) == 0)
		game->p->img->instances[0].y += 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& check_hitbox(game, x - 2, y) == 0)
		game->p->img->instances[0].x -= 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& check_hitbox(game, x + 2, y) == 0)
		game->p->img->instances[0].x += 2;
}

void	collectibles_hook(void	*param)
{
	int		i;
	int		u;
	int		c_c;
	t_game	*g;

	i = -1;
	u = -1;
	c_c = 0;
	g = (t_game *)param;
	while (g->map->array[++i])
	{
		while (g->map->array[i][++u])
		{
			if (g->p->img->instances[0].x == g->c[c_c]->img->instances[0].x
				&& g->p->img->instances[0].y == g->c[c_c]->img->instances[0].y)
				collect_c(g, &c_c);
		}
		printf("c_c = %d\n", c_c);
		u = -1;
	}
}

void	collect_c(t_game	*g, int		*c_c)
{
	if (g->c[*c_c]->is_collected == false)
	{
		mlx_delete_image(g->mlx, g->c[*c_c]->img);
		(*c_c)++;
		g->c[*c_c]->is_collected = true;
	}
}

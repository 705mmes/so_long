/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runnin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:19:32 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/02 16:03:34 by sammeuss         ###   ########.fr       */
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
	game->game_on = true;
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
	int		c_c;
	int		p_x;
	int		p_y;
	t_game	*g;

	g = (t_game *)param;
	p_x = g->p->img->instances[0].x;
	p_y = g->p->img->instances[0].y;
	c_c = 0;
	while (g->c[c_c])
	{
		if (check_hitbox_c(g, c_c, p_x, p_y) == 0)
		{
			mlx_delete_image(g->mlx, g->c[c_c]->img);
			g->c[c_c]->is_collected = true;
			g->p->count_c++;
		}
		c_c++;
	}
	ft_exit(g, g->p->count_c);
}

void	ft_exit(t_game	*g, int counter)
{
	int	p_x;
	int	p_y;
	int	nb_c;

	nb_c = nb_ct(g->map->array);
	p_x = g->p->img->instances[0].x;
	p_y = g->p->img->instances[0].y;
	if (g->game_on == true)
	{
		if ((counter == nb_c)
			&& (p_x < (g->e->x + TS))
			&& ((p_x + g->p->width) > (g->e->x))
			&& (p_y < (g->e->y + TS))
			&& ((p_y + g->p->height) > (g->e->y)))
		{
			mlx_close_window(g->mlx);
		}
	}
}

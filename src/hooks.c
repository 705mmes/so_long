/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:19:32 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/31 12:14:30 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hook(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->p->x;
	y = game->p->y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& check_hitbox(game, x + 2, y + 2) == 0)
		game->p->img->instances[0].y -= 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& check_hitbox(game, x + 2, y + 2) == 0)
		game->p->img->instances[0].y += 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& check_hitbox(game, x + 2, y + 2) == 0)
		game->p->img->instances[0].x -= 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& check_hitbox(game, x + 2, y + 2) == 0)
		game->p->img->instances[0].x += 2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:05:54 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/02 16:12:59 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (game->textures[i] && game->textures)
	{
		if (game->textures[i])
			mlx_delete_texture(game->textures[i]);
		i++;
	}
	free(game->textures);
}

void	free_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (game->c[i] && game->c)
	{
		if (game->c[i]->img)
			mlx_delete_image(game->mlx, game->c[i]->img);
		free(game->c[i]);
		i++;
	}
	free(game->c);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->array[i])
	{
		free(game->map->array[i]);
		i++;
	}
	free(game->map->array);
	free(game->map);
}

void	free_all(t_game *game)
{
	if (game->c)
		free_collectible(game);
	if (game->p->img)
		mlx_delete_image(game->mlx, game->p->img);
	if (game->e->img)
		mlx_delete_image(game->mlx, game->e->img);
	free_map(game);
	free_textures(game);
}

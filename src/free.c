/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:05:54 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/05 18:42:37 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_int_array(int	**array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_textures(t_game *game)
{
	int	i;

	i = -1;
	while (game->textures[++i] && game->textures)
	{
		if (game->textures[i])
			mlx_delete_texture(game->textures[i]);
	}
	free(game->textures);
}

void	free_collectible(t_game *game)
{
	int	i;

	i = -1;
	while (game->c[++i] && game->c)
	{
		if (game->c[i]->img)
			mlx_delete_image(game->mlx, game->c[i]->img);
		free(game->c[i]);
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
	free(game->p);
	free(game->e);
	free(game);
}

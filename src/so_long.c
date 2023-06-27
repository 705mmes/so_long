/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:59:50 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/27 13:25:56 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, const char	**argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of args\n");
		return (EXIT_FAILURE);
	}
	if (!check_ext((char *)argv[1], ".ber"))
		return (EXIT_FAILURE);
	game = init_game();
	if (argc == 2)
		game->map->array = map_init((char *)argv[1]);
	if (map_checker(game->map->array) == 1)
	{
		free_necessary(game);
		return (EXIT_FAILURE);
	}
	start(game);
	return (EXIT_SUCCESS);
}

void	ft_score_hook(void *param)
{
	t_game	*game;
	char	*s;

	game = (t_game *)param;
	s = ft_strjoin("Score -> ", ft_itoa(game->score));
	if (game->score_img == NULL)
		game->score_img = mlx_put_string(game->mlx, s, 0, 0);
	else
	{
		mlx_delete_image(game->mlx, game->score_img);
		game->score_img = mlx_put_string(game->mlx, s, 0, 0);
	}
}

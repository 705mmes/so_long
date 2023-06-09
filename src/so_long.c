/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:59:50 by sammeuss          #+#    #+#             */
/*   Updated: 2023/07/03 15:15:04 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, const char	**argv)
{
	t_game	*game;

	if (open(argv[1], O_RDONLY) == -1)
		return (ft_printf("Error\nFile does not exist\n"));
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

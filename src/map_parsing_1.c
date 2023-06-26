/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:23:25 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/26 12:06:45 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_chars_in_map(char	**map)
{
	int	i;
	int	u;

	i = -1;
	u = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] != 'S' && map[i][u] != 'E'
				&& map[i][u] != '1' && map[i][u] != '0'
				&& map[i][u] != 'C')
			{
				ft_printf("Error\nMap cursed\n");
				return (1);
			}
		}
		u = -1;
	}
	return (0);
}

int	check_for_collectibles(char **map)
{
	int	i;
	int	u;

	u = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				return (0);
			u++;
		}
		u = 0;
		i++;
	}
	ft_printf("Error\nMissing collectible(s)\n");
	return (1);
}

int	map_is_closed(char **map)
{
	int	i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (ft_printf("Error\nMap is not closed\n"));
	i = -1;
	while (map[ft_array_len(map) - 1][++i])
		if (map[ft_array_len(map) - 1][i] != '1')
			return (ft_printf("Error\nMap is not closed\n"));
	i = -1;
	while (++i < ft_array_len(map))
		if (map[i][0] != '1')
			return (ft_printf("Error\nMap is not closed\n"));
	i = -1;
	while (++i < ft_array_len(map))
		if (map[i][ft_strlen(map[0]) - 1] != '1')
			return (ft_printf("Error\nMap is not closed\n"));
	return (0);
}

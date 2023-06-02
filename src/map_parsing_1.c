/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:23:25 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/02 16:04:38 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_is_possible(char **map, int **array)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	(void)array;
	find_spawn(&i, &u, map);
	return (0);
}

int	**init_int_array(char **map)
{
	int	**array;
	int	i;
	int	u;

	u = -1;
	i = -1;
	array = malloc(sizeof(int *) * ft_array_len(map));
	while (++i < ft_array_len(map))
		array[i] = malloc(sizeof(int) * ft_strlen(map[i]));
	i = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == '1')
				array[i][u] = 1;
			else if (map[i][u] == 'C')
				array[i][u] = 2;
			else
				array[i][u] = 0;
		}
		u = 0;
	}
	return (array);
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
	return (1);
}

int	map_is_closed(char **map)
{
	int	i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (1);
	i = -1;
	while (map[ft_array_len(map) - 1][++i])
		if (map[ft_array_len(map) - 1][i] != '1')
			return (1);
	i = 0;
	while (i < ft_array_len(map))
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < ft_array_len(map))
	{
		if (map[i][ft_strlen(map[0]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

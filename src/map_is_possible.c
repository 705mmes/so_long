/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:08:10 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/05 18:29:40 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	final_check(char **map, int **array)
{
	int	i;
	int	u;

	u = -1;
	i = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'C' && array[i][u] < 0)
				return (1);
			if (map[i][u] == 'E' && array[i][u] < 0)
				return (1);
		}
		u = -1;
	}
	return (0);
}

int	nb_possibilities(int **array, int count)
{
	int	i;
	int	u;
	int	r;

	r = 0;
	u = -1;
	i = -1;
	while (array[++i])
	{
		while (array[i][++u])
		{
			if (array[i][u] >= 2)
				r += check_sides(array, count, i, u);
		}
		u = -1;
	}
	return (r);
}

int	check_sides(int	**array, int count, int i, int u)
{
	int	r;

	r = 0;
	if (array[i][u + 1] == -1)
	{
		array[i][u + 1] = count + 1;
		r++;
	}
	if (array[i][u - 1] == -1)
	{
		array[i][u - 1] = count + 1;
		r++;
	}
	if (array[i + 1][u] == -1)
	{
		array[i + 1][u] = count + 1;
		r++;
	}
	if (array[i - 1][u] == -1)
	{
		array[i - 1][u] = count + 1;
		r++;
	}
	return (r);
}

int	map_is_possible(char **map)
{
	int	count;
	int	**array;

	count = 2;
	array = init_int_array(map);
	while (nb_possibilities(array, count) > 0)
		count++;
	if (final_check(map, array) == 1)
	{
		ft_printf("Error\nMap isn't possible\n");
		free_int_array(array);
		return (1);
	}
	free_int_array(array);
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
		array[i] = malloc(sizeof(int) * ft_strlen(map[i]) + 1);
	i = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == '1')
				array[i][u] = 1;
			else if (map[i][u] == 'S')
				array[i][u] = 2;
			else
				array[i][u] = -1;
		}
		u = -1;
	}
	return (array);
}

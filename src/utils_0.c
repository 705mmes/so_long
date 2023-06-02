/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:04 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/01 14:01:40 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_hitbox(t_game *game, int x, int y)
{
	int	i;
	int	u;

	i = -1;
	u = -1;
	while (game->map->array[++i])
	{
		while (game->map->array[i][++u])
		{
			if ((x < (u * TS + TS))
				&& ((x + game->p->width) > (u * TS))
				&& (y < (i * TS + TS))
				&& ((y + game->p->height) > (i * TS))
				&& game->map->array[i][u] == '1')
				return (1);
		}
		u = -1;
	}
	return (0);
}

int	nb_ct(char **map)
{
	int	i;
	int	u;
	int	r;

	r = 0;
	u = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				r++;
			u++;
		}
		u = 0;
		i++;
	}
	return (r);
}

void	find_spawn(int	*i, int	*u, char **map)
{
	while (map[*i])
	{
		while (map[*i][*u])
		{
			if (map[*i][*u] == 'S')
				return ;
			(*u)++;
		}
		*u = 0;
		(*i)++;
	}
}

void	print_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("char_array[i(%d)] : %s\n", i, array[i]);
		i++;
	}
}

void	print_int_array(int **array)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (array[i])
	{
		while (array[i][u])
		{
			printf("int_array[i(%d)][u(%d)] : %d\n", i, u, array[i][u]);
			u++;
		}
		u = 0;
		i++;
	}
}
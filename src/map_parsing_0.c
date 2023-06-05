/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:47:08 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/05 19:40:01 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**map_init(char *map)
{
	char	**map_array;
	char	*line;
	int		fd;
	int		i;

	i = -1;
	map_array = NULL;
	line = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		map_array = ft_array_join(map_array, line);
		line = get_next_line(fd);
	}
	free(line);
	return (map_array);
}

int	map_checker(char **map)
{
	if (check_chars_in_map(map) == 0)
		if (map_is_rectangle(map) == 0)
			if (check_for_spawn(map) == 0)
				if (check_for_collectibles(map) == 0)
					if (check_for_exit(map) == 0)
						if (map_is_closed(map) == 0)
							if (map_is_possible(map) == 0)
								return (0);
	return (1);
}

int	map_is_rectangle(char **map)
{
	int	i;
	int	array_len;
	int	line_len;

	line_len = ft_strlen(map[0]);
	array_len = ft_array_len(map);
	i = -1;
	while (++i < array_len)
	{
		if (ft_strlen(map[i]) != (size_t)line_len)
		{
			ft_printf("Error\nMap is not rectangle\n");
			return (1);
		}
	}
	return (0);
}

int	check_for_spawn(char **map)
{
	int	i;
	int	u;

	u = -1;
	i = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'S')
				return (0);
		}
		u = -1;
	}
	ft_printf("Error\nMissing a spawn point");
	return (1);
}

int	check_for_exit(char **map)
{
	int	i;
	int	u;

	u = -1;
	i = -1;
	while (map[++i])
	{
		while (map[i][++u])
		{
			if (map[i][u] == 'E')
				return (0);
		}
		u = -1;
	}
	ft_printf("Error\nCan't get out\n");
	return (1);
}

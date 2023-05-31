/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:47:08 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/30 15:20:21 by sammeuss         ###   ########.fr       */
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
	printf("fd : %d\n", fd);
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
	int	**array;

	array = init_int_array(map);
	if (map_is_rectangle(map) == 0)
		if (check_for_spawn(map) == 0)
			if (check_for_exit(map) == 0)
				if (check_for_exit(map) == 0)
					if (map_is_closed(map) == 0)
						if (map_is_possible(map, array) == 0)
							return (0);
	return (ft_error());
}

int	map_is_rectangle(char **map)
{
	int				i;
	unsigned int	colonnes;

	i = 0;
	colonnes = ft_array_len(map);
	while (map[i])
	{
		if (ft_strlen(map[i]) == colonnes)
			return (1);
		i++;
	}
	printf("ft_strlen(map[i]) :%zu\ncolonnes :%d\n", ft_strlen(map[i - 1]), colonnes);
	return (0);
}

int	check_for_spawn(char **map)
{
	int	i;
	int	u;

	u = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][u])
		{
			if (map[i][u] == 'S')
				return (0);
			u++;
		}
		u = 0;
		i++;
	}
	return (1);
}

int	check_for_exit(char **map)
{
	int	i;
	int	u;

	u = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][u])
		{
			if (map[i][u] == 'E')
				return (0);
			u++;
		}
		u = 0;
		i++;
	}
	return (1);
}

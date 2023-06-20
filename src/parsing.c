/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:46:12 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/20 11:04:46 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_array_len(char	**array)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	ft_array_len_int(int	**array, char **map)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (map[i])
		i++;
	return (i);
}

bool	check_ext(char	*file_name, char	*ext)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (file_name[i])
		i++;
	if (i < 5)
	{
		ft_printf("Error\nFile name too short\n");
		return (false);
	}
	i -= 4;
	while (file_name[i] && ext[j])
	{
		if (file_name[i] != ext[j])
		{
			ft_printf("Error\nWrong file extension\n");
			return (false);
		}
		i++;
		j++;
	}
	return (true);
}

char	**ft_array_join(char **array, char *line)
{
	char	**new_array;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (array)
		while (array[i])
			i++;
	len = i;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = -1;
	while (++i < len)
		new_array[i] = array[i];
	if (line[ft_strlen(line) - 1] == '\n')
		new_array[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		new_array[i] = ft_strdup(line);
	new_array[++i] = NULL;
	free(array);
	freeall(&line);
	return (new_array);
}

char	*freeall(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
		return (*str);
	}
	return (NULL);
}

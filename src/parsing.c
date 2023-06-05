/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:46:12 by sammeuss          #+#    #+#             */
/*   Updated: 2023/06/05 17:51:12 by sammeuss         ###   ########.fr       */
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

	i = 0;
	if (!array)
	{
		new_array = malloc(sizeof(char *) * 2);
		new_array[0] = ft_substr(line, 0, ft_strlen(line) - 1);
		new_array[1] = NULL;
		return (new_array);
	}
	new_array = malloc(sizeof(char *) * (ft_array_len(array) + 2));
	while (array[i])
	{
		new_array[i] = array[i];
		i++;
	}
	if (line[ft_strlen(line) - 1] == '\n')
		new_array[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		new_array[i] = line;
	new_array[++i] = NULL;
	return (new_array);
}

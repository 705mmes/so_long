/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:52:29 by smunio            #+#    #+#             */
/*   Updated: 2023/06/14 10:15:28 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*buff;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	buff = malloc(sizeof(char) * (len) + 1);
	if (!buff)
		return (NULL);
	if (len > i)
	{
		while ((i < len) && s[start])
		{
			buff[i] = s[start];
			start++;
			i++;
		}
	}
	buff[i] = '\0';
	return (buff);
}

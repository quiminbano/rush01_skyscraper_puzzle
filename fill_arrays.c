/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:32:49 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 21:36:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**ft_fill_with_zero(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	map = (int **)malloc(sizeof(int *) * (SIZE));
	if (!map)
		return (NULL);
	while (i < SIZE)
	{
		j = 0;
		map[i] = (int *)malloc(sizeof(int) * SIZE);
		if (!map[i])
			return (ft_free_int_ar(map, i), NULL);
		while (j < SIZE)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int	**ft_fill_clue(char **split)
{
	int	**clues;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	clues = (int **)malloc(sizeof(int *) * (4));
	if (!clues)
		return (NULL);
	while (i < 4)
	{
		j = 0;
		clues[i] = (int *)malloc(sizeof(int) * SIZE);
		if (!clues[i])
			return (ft_free_int_ar(clues, i), NULL);
		while (j < SIZE)
		{
			clues[i][j] = ft_atoi(split[k]);
			k++;
			j++;
		}
		i++;
	}
	return (clues);
}

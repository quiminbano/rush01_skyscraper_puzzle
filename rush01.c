/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:23:42 by corellan          #+#    #+#             */
/*   Updated: 2023/07/10 21:54:18 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	solve_and_check(int **map, int **clues, int row, int col)
{
	int	value;

	value = 0;
	while (value <= SIZE)
	{
		if (find_repeated(map, value, row, col))
		{
			map[row][col] = value;
			if (col == (SIZE - 1) && !ft_solve_map(map, clues, (row + 1), 0))
				return (0);
			else if (col != (SIZE - 1) && \
				!ft_solve_map(map, clues, row, (col + 1)))
				return (0);
			map[row][col] = 0;
		}
		value++;
	}
	return (1);
}	

int	ft_solve_map(int **map, int **clues, int row, int col)
{
	if (row == SIZE)
	{
		if (!ft_clue_check(map, clues))
			return (0);
		return (1);
	}
	if (map[row][col] != 0)
	{
		if (col == (SIZE - 1))
			return (ft_solve_map(map, clues, (row + 1), 0));
		else
			return (ft_solve_map(map, clues, row, (col + 1)));
	}
	return (solve_and_check(map, clues, row, col));
}

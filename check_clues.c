/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:39:01 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 22:08:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_check_up(int **map, int **clues)
{
	int	count;
	int	size;
	int	col;
	int	row;

	col = 0;
	while (col < SIZE)
	{
		row = 0;
		count = 0;
		size = 0;
		while (row < SIZE)
		{
			if (map[row][col] > size)
			{
				size = map[row][col];
				count++;
			}
			row++;
		}
		if (count != clues[0][col])
			return (1);
		col++;
	}
	return (0);
}

static int	ft_check_down(int **map, int **clues)
{
	int	count;
	int	size;
	int	col;
	int	row;

	col = 0;
	while (col < SIZE)
	{
		row = (SIZE - 1);
		count = 0;
		size = 0;
		while (row >= 0)
		{
			if (map[row][col] > size)
			{
				size = map[row][col];
				count++;
			}
			row--;
		}
		if (count != clues[1][col])
			return (1);
		col++;
	}
	return (0);
}

static int	ft_check_left(int **map, int **clues)
{
	int	count;
	int	size;
	int	col;
	int	row;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		count = 0;
		size = 0;
		while (col < SIZE)
		{
			if (map[row][col] > size)
			{
				size = map[row][col];
				count++;
			}
			col++;
		}
		if (count != clues[2][row])
			return (1);
		row++;
	}
	return (0);
}

static int	ft_check_right(int **map, int **clues)
{
	int	count;
	int	size;
	int	col;
	int	row;

	row = 0;
	while (row < SIZE)
	{
		col = (SIZE - 1);
		count = 0;
		size = 0;
		while (col >= 0)
		{
			if (map[row][col] > size)
			{
				size = map[row][col];
				count++;
			}
			col--;
		}
		if (count != clues[3][row])
			return (1);
		row++;
	}
	return (0);
}

int	ft_clue_check(int **map, int **clues)
{
	if (ft_check_up(map, clues))
		return (1);
	if (ft_check_down(map, clues))
		return (1);
	if (ft_check_left(map, clues))
		return (1);
	if (ft_check_right(map, clues))
		return (1);
	return (0);
}

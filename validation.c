/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:06:29 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 21:29:27 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	find_repeated(int **map, int value, int row, int col)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (map[i][col] == value)
			return (0);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (map[row][i] == value)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	while ((str[i] <= 57 && str[i] >= 48))
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	ft_valid_input(char **split)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	if (!split)
		return (1);
	while (split[i])
	{
		if (!ft_is_number(split[i]))
			number = ft_atoi(split[i]);
		else
			return (1);
		if (number < 1 || number > SIZE)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_strings(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

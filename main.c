/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:58:59 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 22:29:40 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	main_cont(int **map, int **clues, char **split)
{
	clues = ft_fill_clue(split);
	if (!clues)
	{
		ft_putstr_fd("Allocation error\n", 2);
		return (ft_free_split(split), 1);
	}
	map = ft_fill_with_zero();
	if (!map)
	{
		ft_putstr_fd("Allocation error\n", 2);
		return (ft_free_split(split), ft_free_int_ar(clues, 4), 1);
	}
	if (!ft_solve_map(map, clues, 0, 0))
		ft_print_map(map);
	else
		ft_putstr_fd("No solution found\n", 2);
	ft_free_split(split);
	ft_free_int_ar(clues, SIZE);
	ft_free_int_ar(map, SIZE);
	return (0);
}

int	main(int argc, char **argv)
{
	int		**map;
	int		**clues;
	char	**split;

	map = NULL;
	clues = NULL;
	split = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Invalid ammount of parameters\n", 2);
		return (1);
	}
	split = ft_split_spaces(argv[1]);
	if (!split)
	{
		ft_putstr_fd("Allocation error\n", 2);
		return (1);
	}
	if (ft_count_strings(split) != (SIZE * 4) || ft_valid_input(split))
	{
		ft_putstr_fd("Invalid argumments\n", 2);
		return (ft_free_split(split), 1);
	}
	return (main_cont(map, clues, split));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:28:02 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 22:30:31 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_print_map(int **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putnbr_fd(arr[i][j], 1);
			if (j != (SIZE - 1))
				ft_putchar_fd(' ', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

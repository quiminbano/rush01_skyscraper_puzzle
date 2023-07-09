/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:36:35 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 22:19:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int			i;
	long long	number;
	long long	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += (str[i++] - '0');
	}
	if ((number < 0) && (sign == 1))
		return (-1);
	if ((number < 0) && (sign == -1))
		return (0);
	return ((int)(sign * number));
}

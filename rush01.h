/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:09:09 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 22:30:05 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

# define SIZE 4

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_atoi(char *str);
void	ft_free_split(char **split);
void	ft_free_int_ar(int	**array, int ammount);
int		ft_count_strings(char **split);
int		ft_valid_input(char **split);
char	**ft_split_spaces(char *str);
int		**ft_fill_clue(char **split);
int		**ft_fill_with_zero(void);
int		ft_solve_map(int **map, int **clues, int row, int col);
int		find_repeated(int **map, int value, int row, int col);
int		ft_clue_check(int **map, int **clues);
void	ft_print_map(int **arr);

#endif
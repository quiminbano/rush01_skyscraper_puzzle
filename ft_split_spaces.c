/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:59:49 by corellan          #+#    #+#             */
/*   Updated: 2023/07/09 11:18:16 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_strlen_pos(char *str, int start)
{
	int	i;

	i = 0;
	while (str[i + start] != '\0' && str[i + start] != ' ')
		i++;
	return (i);
}

static int	ft_index_after_space(char *str, int pos)
{
	int	i;

	i = 0;
	while (str[i + pos] == ' ')
		i++;
	return (i + pos);
}

static int	ft_words(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != 32 && str[i] != 0) && (str[i + 1] == 32 || \
			str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_strdup_pos(char *src, int start)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen_pos(src, start);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[start + i] != '\0' && src[start + i] != ' ')
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_spaces(char *str)
{
	int		words;
	char	**split;
	int		index;
	int		i;

	words = ft_words(str);
	i = 0;
	index = 0;
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	while (i < words)
	{
		index = ft_index_after_space(str, index);
		split[i] = ft_strdup_pos(str, index);
		if (!split[i])
			return (ft_free_split(split), NULL);
		index += ft_strlen_pos(str, index);
		i++;
	}
	return (split);
}

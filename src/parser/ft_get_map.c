/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:36:49 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:36:51 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	ft_is_map(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0' && \
		str[i] != 'W' && str[i] != 'E' && str[i] != 'N' && str[i] != 'S')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_last(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int	ft_len_of_map(char **arr)
{
	int	i;
	int	count;
	int	stat;

	count = 0;
	stat = 0;
	i = 0;
	while (arr[i])
	{
		if (ft_is_map(arr[i]) && stat == 0)
		{
			count++;
			stat = 1;
		}
		else if (ft_is_map(arr[i]) && stat == 1)
			count++;
		else if (!ft_is_map(arr[i]) && stat == 1)
		{
			if (ft_check_last(&arr[i]) == 0)
				return (0);
			return (count);
		}
		i++;
	}
	return (count);
}

static	int	ft_start_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_is_map(arr[i]))
			return (i);
		i++;
	}
	return (-1);
}

char	**get_map(char **arr)
{
	char	**map;
	int		len;
	int		i;
	int		j;

	len = ft_len_of_map(arr);
	map = malloc(sizeof (char *) * (ft_len_of_map(arr) + 1));
	if (map)
	{
		i = ft_start_map(arr) - 1;
		j = -1;
		while (++i >= 0 && arr[i] && ++j < len)
		{
			map[j] = ft_strdup(arr[i]);
			if (map[j] == NULL)
			{
				ft_clear_arr(map);
				return (NULL);
			}
		}
		map[++j] = NULL;
		return (map);
	}
	return (NULL);
}

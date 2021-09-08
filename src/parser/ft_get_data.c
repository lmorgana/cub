/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:59:00 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/24 19:59:02 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	ft_check_last_t(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		if (str[i] == '\0')
			return (0);
		while (str[i] == ' ')
			i++;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				return (0);
			i++;
		}
	}
	return (1);
}

static char	*ft_get_str_of_data(char *str)
{
	int		i;
	int		j;
	int		stat_sp;
	char	*str_new;

	if (str[0] == '\0')
		return (NULL);
	str_new = malloc (sizeof (char) * (ft_strlen(str) - ft_len_space(str) + 2));
	i = -1;
	j = -1;
	stat_sp = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' && stat_sp == 0)
		{
			str_new[++j] = str[i];
			stat_sp = 1;
		}
		else if (str[i] == ' ')
			continue ;
		else
			str_new[++j] = str[i];
	}
	str_new[++j] = '\0';
	return (str_new);
}

static int	ft_is_data(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == 'N' && str[i + 1] && str[i + 1] == 'O') || \
		(str[i] == 'S' && str[i + 1] && str[i + 1] == 'O') || \
		(str[i] == 'W' && str[i + 1] && str[i + 1] == 'E') || \
		(str[i] == 'E' && str[i + 1] && str[i + 1] == 'A') || \
		str[i] == 'F' || str[i] == 'C')
		{
			if (ft_check_last_t(&str[i + 2]) == 0)
				return (0);
			return (1);
		}
		else if (str[i] == ' ')
			i++;
		else
			return (0);
		i++;
	}
	return (1);
}

int	fill_data(char **arr, char **data)
{
	int	i;
	int	count;

	i = -1;
	count = -1;
	while (arr[++i] && !ft_is_map(arr[i]))
	{
		if (ft_is_data(arr[i]))
		{
			if (++count >= 6)
				return (0);
			data[count] = ft_get_str_of_data(arr[i]);
			if (data[count] == NULL)
				return (0);
		}
		else if (ft_is_spases(arr[i]))
			continue ;
		else
			return (0);
	}
	return (1);
}

char	**get_data(char **arr)
{
	char	**data;

	data = malloc (sizeof (char *) * (7));
	ft_set_null(data, 7);
	if (data)
	{
		if (fill_data(arr, data) == 0)
		{
			ft_clear_arr(data);
			return (0);
		}
	}
	return (data);
}

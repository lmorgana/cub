/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:32:13 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:32:16 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	ft_get_hero(char **map, t_hero *hero)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'W' || map[i][j] == 'E')
			{
				hero->i = i;
				hero->j = j;
				hero->ch = map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static	int	ft_new_cell(t_splst **lst, char **map, int i, int j)
{
	t_splst	*new;

	if (i >= 0 && j >= 0 && \
	map[i] && map[i][j] && map[i][j] != '\0' && map[i][j] != ' ')
	{
		if (map[i][j] == '0')
		{
			new = ft_create_splst(i, j);
			ft_add_front(new, lst);
		}
		return (1);
	}
	return (0);
}

static	int	ft_start_paint(char **map, t_splst *lst)
{
	int	i;
	int	j;

	if (lst)
	{
		i = lst->i;
		j = lst->j;
		map[i][j] = 'P';
		ft_del_first(&lst);
		if (ft_new_cell(&lst, map, i, j + 1) == 0)
			return (0);
		if (ft_new_cell(&lst, map, i - 1, j) == 0)
			return (0);
		if (ft_new_cell(&lst, map, i, j - 1) == 0)
			return (0);
		if (ft_new_cell(&lst, map, i + 1, j) == 0)
			return (0);
		return (ft_start_paint(map, lst));
	}
	return (1);
}

void	ft_get_back(char **map, t_hero *hero)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				map[i][j] = '0';
			if (i == hero->i && j == hero->j)
				map[i][j] = hero->ch;
			j++;
		}
		i++;
	}
}

int	ft_is_surround(char **map)
{
	t_hero	hero;
	t_splst	*lst;

	ft_get_hero(map, &hero);
	lst = ft_create_splst(hero.i, hero.j);
	if (lst)
	{
		if (ft_start_paint(map, lst))
		{
			ft_get_back(map, &hero);
			return (1);
		}
	}
	return (0);
}

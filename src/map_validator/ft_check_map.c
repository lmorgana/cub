/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:32:05 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:32:07 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	ft_check_elem(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
			|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	ft_check_map(char **map, t_vars *vars)
{
	(void) vars;
	if (!map)
		return (0);
	if (ft_check_elem(map) == 0)
		return (0);
	if (ft_is_surround(map) == 0)
		return (0);
	return (1);
}

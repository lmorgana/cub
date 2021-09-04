/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:03:28 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/31 22:18:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_set_dir(t_vars *vars, char ch)
{
	if (ch == 'N')
	{
		vars->plr.dirX = 0;
		vars->plr.dirY = -1;
	}
	if (ch == 'S')
	{
		vars->plr.dirX = 0;
		vars->plr.dirY = 1;
	}
	if (ch == 'W')
	{
		vars->plr.dirX = 1;
		vars->plr.dirY = 0;
	}
	if (ch == 'E')
	{
		vars->plr.dirX = -1;
		vars->plr.dirY = 0;
	}
	return (1);
}

static	int	ft_plr(t_vars *vars)
{
	int	i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S' \
			|| vars->map[i][j] == 'W' || vars->map[i][j] == 'E')
			{
				vars->plr.posX = i;
				vars->plr.posY = j;
				ft_set_dir(vars, vars->map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_plr_init(t_vars *vars)
{
	ft_plr(vars);
	vars->plr.planeX = -0.66;
	vars->plr.planeY = 0;
	vars->plr.time = 0;
	vars->plr.oldTime = 0;
}

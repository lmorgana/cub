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
	if (ch == 'E')
	{
		vars->plr.dirX = 0;
		vars->plr.dirY = -1;
		vars->plr.planeX = -0.66;
		vars->plr.planeY = 0;
	}
	if (ch == 'W')
	{
		vars->plr.dirX = 0;
		vars->plr.dirY = 1;
		vars->plr.planeX = 0.66;
		vars->plr.planeY = 0;
	}
	if (ch == 'N')
	{
		vars->plr.dirX = -1;
		vars->plr.dirY = 0;
		vars->plr.planeX = 0;
		vars->plr.planeY = 0.66;
	}
	if (ch == 'S')
	{
		vars->plr.dirX = 1;
		vars->plr.dirY = 0;
		vars->plr.planeX = 0;
		vars->plr.planeY = -0.66;
	}
	return (1);
}

static	int	ft_get_xy(t_vars *vars, int *posX, int *posY)
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
				*posX = i;
				*posY = j;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_set_XY(t_vars *vars)
{
	int	posX;
	int	posY;

	posX = (int) vars->plr.posX;
	posY = (int) vars->plr.posY;
	if (vars->map[posX + 1][posY + 1] && vars->map[posX + 1][posY + 1] == '0')
	{
		vars->plr.posX += 0.5;
		vars->plr.posY += 0.5;
	}
	else if (vars->map[posX - 1][posY - 1] && vars->map[posX - 1][posY - 1] == '0')
	{
		vars->plr.posX -= 0.5;
		vars->plr.posY -= 0.5;
	}
}

void	ft_plr_init(t_vars *vars)
{
	int	posX;
	int	posY;

	ft_get_xy(vars, &posX, &posY);
	vars->plr.posX = posX;
	vars->plr.posY = posY;
	ft_set_dir(vars, vars->map[posX][posY]);
	vars->map[posX][posY] = '0';
	ft_set_XY(vars);
}

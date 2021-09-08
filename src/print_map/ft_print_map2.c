/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:03:44 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:03:46 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_set_dir_print(t_inside_data *id, t_comm_data *cd, t_vars *vars)
{
	double	cameraX;

	cameraX = 2 * cd->x / (double) SCREENWIDTH - 1;
	cd->rayDirX = vars->plr.dirX + vars->plr.planeX * cameraX;
	cd->rayDirY = vars->plr.dirY + vars->plr.planeY * cameraX;
	id->mapX = (int) vars->plr.posX;
	id->mapY = (int) vars->plr.posY;
	if (cd->rayDirY == 0)
		id->deltaDistX = 0;
	else if (cd->rayDirX == 0)
		id->deltaDistX = 1;
	else
		id->deltaDistX = ft_abs(1 / cd->rayDirX);
	if (cd->rayDirX == 0)
		id->deltaDistY = 0;
	else if (cd->rayDirY == 0)
		id->deltaDistY = 1;
	else
		id->deltaDistY = ft_abs(1 / cd->rayDirY);
	return (1);
}

static	int	ft_init_side_step(t_inside_data *id, t_vars	*vars, \
	double rayDirX, double rayDirY)
{
	if (rayDirX < 0)
	{
		id->stepX = -1;
		id->sideDistX = (vars->plr.posX - id->mapX) * id->deltaDistX;
	}
	else
	{
		id->stepX = 1;
		id->sideDistX = (id->mapX + 1.0 - vars->plr.posX) * id->deltaDistX;
	}
	if (rayDirY < 0)
	{
		id->stepY = -1;
		id->sideDistY = (vars->plr.posY - id->mapY) * id->deltaDistY;
	}
	else
	{
		id->stepY = 1;
		id->sideDistY = (id->mapY + 1.0 - vars->plr.posY) * id->deltaDistY;
	}
	return (1);
}

int	ft_cast_ray(t_inside_data *id, t_comm_data *cd, t_vars *vars)
{
	ft_init_side_step(id, vars, cd->rayDirX, cd->rayDirY);
	cd->stepX = id->stepX;
	cd->stepY = id->stepY;
	id->hit = 0;
	while (id->hit == 0)
	{
		if (id->sideDistX < id->sideDistY)
		{
			id->sideDistX += id->deltaDistX;
			id->mapX += cd->stepX;
			cd->side = 0;
		}
		else
		{
			id->sideDistY += id->deltaDistY;
			id->mapY += cd->stepY;
			cd->side = 1;
		}
		if (vars->map[id->mapX][id->mapY] == '1')
			id->hit = 1;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:04:37 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:04:38 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	turn_left(t_vars *vars, double rotSpeed)
{
	double	oldDirx;
	double	oldPlaneX;

	oldDirx = vars->plr.dirX;
	vars->plr.dirX = vars->plr.dirX * cos(rotSpeed) - \
	vars->plr.dirY * sin(rotSpeed);
	vars->plr.dirY = oldDirx * sin(rotSpeed) + \
	vars->plr.dirY * cos(rotSpeed);
	oldPlaneX = vars->plr.planeX;
	vars->plr.planeX = vars->plr.planeX * cos (rotSpeed) - \
	vars->plr.planeY * sin(rotSpeed);
	vars->plr.planeY = oldPlaneX * sin (rotSpeed) + \
	vars->plr.planeY * cos(rotSpeed);
}

void	turn_right(t_vars *vars, double rotSpeed)
{
	double	oldDirx;
	double	oldPlaneX;

	oldDirx = vars->plr.dirX;
	vars->plr.dirX = vars->plr.dirX * cos(-rotSpeed) - \
	vars->plr.dirY * sin(-rotSpeed);
	vars->plr.dirY = oldDirx * sin(-rotSpeed) + \
	vars->plr.dirY * cos(-1 * rotSpeed);
	oldPlaneX = vars->plr.planeX;
	vars->plr.planeX = vars->plr.planeX * cos (-rotSpeed) - \
	vars->plr.planeY * sin(-rotSpeed);
	vars->plr.planeY = oldPlaneX * sin (-rotSpeed) + \
	vars->plr.planeY * cos(-rotSpeed);
}

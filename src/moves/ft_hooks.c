/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:09:30 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 20:00:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	move_up(t_vars *vars, double moveSpeed)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;

	posX = vars->plr.posX;
	posY = vars->plr.posY;
	dirX = vars->plr.dirX;
	dirY = vars->plr.dirY;
	if (vars->map[(int)(posX + dirX * moveSpeed * 1.2)][(int)posY] && \
	vars->map[(int)(posX + dirX * moveSpeed * 1.2)][(int)posY] == '0')
		vars->plr.posX += vars->plr.dirX * moveSpeed;
	if (vars->map[(int)posX][(int)(posY + dirY * moveSpeed * 1.2)] && \
	vars->map[(int)posX][(int)(posY + dirY * moveSpeed * 1.2)] == '0')
		vars->plr.posY += vars->plr.dirY * moveSpeed;
}

void	move_down(t_vars *vars, double moveSpeed)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;

	posX = vars->plr.posX;
	posY = vars->plr.posY;
	dirX = vars->plr.dirX;
	dirY = vars->plr.dirY;
	if (vars->map[(int)(posX - dirX * moveSpeed * 1.2)][(int)(posY)] \
	&& vars->map[(int)(posX - dirX * moveSpeed * 1.2)][(int)(posY)] == '0')
		vars->plr.posX -= vars->plr.dirX * moveSpeed;
	if (vars->map[(int)(posX)][(int)(posY - dirY * moveSpeed * 1.2)] \
	&& vars->map[(int)(posX)][(int)(posY - dirY * moveSpeed * 1.2)] == '0')
		vars->plr.posY -= vars->plr.dirY * moveSpeed;
}

void	move_left(t_vars *vars, double moveSpeed)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;

	posX = vars->plr.posX;
	posY = vars->plr.posY;
	dirX = vars->plr.dirX;
	dirY = vars->plr.dirY;
	if (vars->map[(int)(posX - dirY * moveSpeed * 1.2)][(int)(posY)] \
	&& vars->map[(int)(posX - dirY * moveSpeed * 1.2)][(int)(posY)] == '0')
		vars->plr.posX -= vars->plr.dirY * moveSpeed;
	if (vars->map[(int)(posX)][(int)(posY + dirX * moveSpeed * 1.2)] \
	&& vars->map[(int)(posX)][(int)(posY + dirX * moveSpeed * 1.2)] == '0')
		vars->plr.posY += vars->plr.dirX * moveSpeed;
}

void	move_right(t_vars *vars, double moveSpeed)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;

	posX = vars->plr.posX;
	posY = vars->plr.posY;
	dirX = vars->plr.dirX;
	dirY = vars->plr.dirY;
	if (vars->map[(int)(posX + \
	dirY * moveSpeed * 1.2)][(int)(posY)] && vars->map[(int)(posX + \
	dirY * moveSpeed * 1.2)][(int)(posY)] == '0')
		vars->plr.posX += vars->plr.dirY * moveSpeed;
	if (vars->map[(int)(posX)][(int)(posY - dirX * moveSpeed * 1.2)] \
	&& vars->map[(int)(posX)][(int)(posY - dirX * moveSpeed * 1.2)] == '0')
		vars->plr.posY -= vars->plr.dirX * moveSpeed;
}

int	ft_hooks(int keycode, t_vars *vars)
{
	double	moveSpeed;
	double	rotSpeed;

	moveSpeed = 0.3;
	rotSpeed = 0.03;
	if (keycode == 53)
		ft_close_all(vars);
	if (keycode == 13)
		move_up(vars, moveSpeed);
	if (keycode == 1)
		move_down(vars, moveSpeed);
	if (keycode == 0)
		move_left(vars, moveSpeed);
	if (keycode == 2)
		move_right(vars, moveSpeed);
	if (keycode == 123)
		turn_left(vars, rotSpeed);
	if (keycode == 124)
		turn_right(vars, rotSpeed);
	return (0);
}

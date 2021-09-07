#include "../../header.h"

void	move_up(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->plr.posX + vars->plr.dirX * \
	moveSpeed)][(int)(vars->plr.posY)] && vars->map[(int)(vars->plr.posX + vars->plr.dirX * \
	moveSpeed)][(int)(vars->plr.posY)] == '0')
		vars->plr.posX += vars->plr.dirX * moveSpeed;
	if (vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY + \
	vars->plr.dirY * moveSpeed)] && vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY + \
	vars->plr.dirY * moveSpeed)] == '0')
		vars->plr.posY += vars->plr.dirY * moveSpeed;
}

void	move_down(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->plr.posX - vars->plr.dirX * \
	moveSpeed)][(int)(vars->plr.posY)] && vars->map[(int)(vars->plr.posX - vars->plr.dirX * \
	moveSpeed)][(int)(vars->plr.posY)] == '0')
		vars->plr.posX -= vars->plr.dirX * moveSpeed;
	if (vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY - \
	vars->plr.dirY * moveSpeed)] && vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY - \
	vars->plr.dirY * moveSpeed)] == '0')
		vars->plr.posY -= vars->plr.dirY * moveSpeed;
}

void	move_left(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->plr.posX - vars->plr.dirY * \
	moveSpeed)][(int)(vars->plr.posY)] && vars->map[(int)(vars->plr.posX - vars->plr.dirY * \
	moveSpeed)][(int)(vars->plr.posY)] == '0')
		vars->plr.posX -= vars->plr.dirY * moveSpeed;
	if (vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY + \
	vars->plr.dirX * moveSpeed)] && vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY + \
	vars->plr.dirX * moveSpeed)] == '0')
		vars->plr.posY += vars->plr.dirX * moveSpeed;
}

void	move_right(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->plr.posX + \
	vars->plr.dirY * moveSpeed)][(int)(vars->plr.posY)] && vars->map[(int)(vars->plr.posX + \
	vars->plr.dirY * moveSpeed)][(int)(vars->plr.posY)] == '0')
		vars->plr.posX += vars->plr.dirY * moveSpeed;
	if (vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY - \
	vars->plr.dirX * moveSpeed)] && vars->map[(int)(vars->plr.posX)][(int)(vars->plr.posY - \
	vars->plr.dirX * moveSpeed)] == '0')
		vars->plr.posY -= vars->plr.dirX * moveSpeed;
}

int	ft_hooks(int keycode, t_vars *vars)
{
	double	moveSpeed;
	double	rotSpeed;

	moveSpeed = 0.5;
	rotSpeed = 0.03;
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

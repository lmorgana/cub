/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:04:14 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/31 23:03:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_close_all(t_vars *vars)
{
	mlx_destroy_window(vars->win.mlx, vars->win.win);
	ft_clear_arr(vars->map);
	exit(0);
}

int	ft_hooks(int keycode, t_vars *vars)
{
	double moveSpeed = 0.5;
	double rotSpeed = 0.03;
	if (keycode == 0)
	{
		//right;
		double oldDirx = vars->plr.dirX;
		vars->plr.dirX = vars->plr.dirX * cos(rotSpeed) - vars->plr.dirY * sin(rotSpeed);
		vars->plr.dirY = oldDirx * sin(rotSpeed) + vars->plr.dirY * cos(rotSpeed);
		double oldPlaneX = vars->plr.planeX;
		vars->plr.planeX = vars->plr.planeX * cos (rotSpeed) - vars->plr.planeY * sin(rotSpeed);
		vars->plr.planeY = oldPlaneX * sin (rotSpeed) + vars->plr.planeY * cos(rotSpeed);
	}
	else if (keycode == 13)
	{
		if (vars->map[(int)(vars->plr.posX + vars->plr.dirX * moveSpeed)][(int) (vars->plr.posY)] == '0')
			vars->plr.posX += vars->plr.dirX * moveSpeed;
		if (vars->map[(int)(vars->plr.posX)][(int) (vars->plr.posY + vars->plr.dirY * moveSpeed)] == '0')
			vars->plr.posY += vars->plr.dirY * moveSpeed;
	}
	else if (keycode == 2)
	{
		//left;
		double oldDirx = vars->plr.dirX;
		vars->plr.dirX = vars->plr.dirX * cos(-rotSpeed) - vars->plr.dirY * sin(-rotSpeed);
		vars->plr.dirY = oldDirx * sin(-rotSpeed) + vars->plr.dirY * cos(-1 * rotSpeed);
		double oldPlaneX = vars->plr.planeX;
		vars->plr.planeX = vars->plr.planeX * cos (-rotSpeed) - vars->plr.planeY * sin(-rotSpeed);
		vars->plr.planeY = oldPlaneX * sin (-rotSpeed) + vars->plr.planeY * cos(-rotSpeed);
	}
	else if (keycode == 1)
	{
//		printf("%d %d\n", (int) (vars.plr.posY), (int) (vars.plr.posX - vars.plr.dirX * moveSpeed));
//		printf("%d %d\n", (int) (vars.plr.posY - vars.plr.dirY * moveSpeed),(int)(vars.plr.posX));
		if (vars->map[(int)(vars->plr.posX - vars->plr.dirX * moveSpeed)][(int) (vars->plr.posY)] == '0')
			vars->plr.posX -= vars->plr.dirX * moveSpeed;
		if (vars->map[(int)(vars->plr.posX)][(int) (vars->plr.posY - vars->plr.dirY * moveSpeed)] == '0')
			vars->plr.posY -= vars->plr.dirY * moveSpeed;
	}
//	printf("posX=%f posY=%f\n", vars->plr.posX, vars->plr.posY);
//	printf("dirX=%f dirY=%f\n", vars->plr.dirX, vars->plr.dirY);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	vars->win.img = mlx_new_image(vars->win.mlx, screenWidth, screenHeight);
	vars->win.addr = mlx_get_data_addr(vars->win.img, &vars->win.bpp, &vars->win.line_l,
								 &vars->win.en);
	ft_print_map(vars);
	//printf("dirX=%f dirY=%f\n", vars->plr.dirX, vars->plr.dirY);
	mlx_put_image_to_window(vars->win.mlx, vars->win.win, vars->win.img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	vars;

	(void) argc;
	(void) argv;

	vars.map = parser(&vars, argv[1]);
	if (vars.map == NULL)
		return (printf("Error \nmap is invalid\n"));
	ft_plr_init(&vars);
	vars.win.mlx = mlx_init();
	vars.win.win = mlx_new_window(vars.win.mlx, screenWidth, \
		screenHeight, "cub3d");
	mlx_loop_hook(vars.win.mlx, render_next_frame, &vars);
	mlx_hook(vars.win.win, 2, 1L << 0, ft_hooks, &vars);
	mlx_hook(vars.win.win, 17, 7L << 0, ft_close_all, &vars);
	mlx_loop(vars.win.mlx);
}

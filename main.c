/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:04:14 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 17:51:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_close_all(t_vars *vars)
{
	mlx_destroy_window(vars->win.mlx, vars->win.win);
	ft_clear_arr(vars->map);
	exit(0);
}

int	render_next_frame(t_vars *vars)
{
	ft_print_map(vars);
	mlx_clear_window(vars->win.mlx, vars->win.win);
	mlx_put_image_to_window(vars->win.mlx, vars->win.win, vars->win.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.map = parser(&vars, argv[1]);
	if (vars.map == NULL)
		return (printf("Error \nmap is invalid\n") * 0);
	if (ft_valid_data(&vars) == 0)
		return (printf("Error \nmap is invalid2\n") * 0);
	ft_plr_init(&vars);
	vars.win.mlx = mlx_init();
	vars.win.win = mlx_new_window(vars.win.mlx, SCREENWIDTH, \
	SCREENHEIGHT, "cub3d");
	vars.win.img = mlx_new_image(vars.win.mlx, SCREENWIDTH, \
	SCREENHEIGHT);
	vars.win.addr = mlx_get_data_addr(vars.win.img, &vars.win.bpp, \
	&vars.win.line_l, &vars.win.en);
	mlx_put_image_to_window(vars.win.mlx, vars.win.win, vars.win.img, 0, 0);
	mlx_loop_hook(vars.win.mlx, render_next_frame, &vars);
	mlx_hook(vars.win.win, 2, 1L << 0, ft_hooks, &vars);
	mlx_hook(vars.win.win, 17, 7L << 0, ft_close_all, &vars);
	mlx_loop(vars.win.mlx);
}

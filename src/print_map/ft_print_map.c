/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:03:37 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:03:39 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	ft_get_cd(t_comm_data *cd, t_vars *vars)
{
	t_inside_data	id;

	ft_set_dir_print(&id, cd, vars);
	ft_cast_ray(&id, cd, vars);
	if (cd->side == 0)
		cd->perpWallDist = (id.mapX - vars->plr.posX + \
		(double)(1 - cd->stepX) / 2) / cd->rayDirX;
	else
		cd->perpWallDist = (id.mapY - vars->plr.posY + \
		(double)(1 - cd->stepY) / 2) / cd->rayDirY;
	cd->lineHeight = (int)(SCREENHEIGHT / cd->perpWallDist);
	cd->drawStart = -cd->lineHeight / 2 + SCREENHEIGHT / 2;
	if (cd->drawStart < 0)
		cd->drawStart = 0;
	cd->drawEnd = cd->lineHeight / 2 + SCREENHEIGHT / 2;
	if (cd->drawEnd >= SCREENHEIGHT)
		cd->drawEnd = SCREENHEIGHT - 1;
	return (1);
}

static	int	ft_get_texX(t_comm_data *cd, t_vars *vars)
{
	int		texX;
	double	wallX;

	if (cd->side == 0)
		wallX = vars->plr.posY + cd->perpWallDist * cd->rayDirY;
	else
		wallX = vars->plr.posX + cd->perpWallDist * cd->rayDirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)vars->img_text[0].width);
	if (cd->side == 0 && cd->rayDirX > 0)
		texX = vars->img_text[0].width - texX - 1;
	if (cd->side == 1 && cd->rayDirY < 0)
		texX = vars->img_text[0].width - texX - 1;
	return (texX);
}

static	int	ft_put_pxl(t_comm_data *cd, t_vars *vars, int texX, int texY)
{
	int	color;

	if (cd->side)
	{
		if (cd->stepY == 1)
			color = ft_get_clr_txt(texX, texY, &vars->img_text[3]);
		else
			color = ft_get_clr_txt(texX, texY, &vars->img_text[2]);
	}
	else
	{
		if (cd->stepX == 1)
			color = ft_get_clr_txt(texX, texY, &vars->img_text[1]);
		else
			color = ft_get_clr_txt(texX, texY, &vars->img_text[0]);
	}
	my_mlx_pixel_put(vars, cd->x, cd->y, color);
	return (1);
}

static	int	ft_print_image(t_comm_data *cd, t_vars *vars)
{
	int		texX;
	int		texY;
	double	step;
	double	texPos;

	texX = ft_get_texX(cd, vars);
	step = 1.0 * vars->img_text[0].height / cd->lineHeight;
	texPos = (cd->drawStart - SCREENHEIGHT / 2 + cd->lineHeight / 2) * step;
	cd->y = cd->drawStart;
	piece(vars, cd->x, 0, cd->drawStart);
	while (cd->y < cd->drawEnd)
	{
		texY = (int)texPos & (vars->img_text[0].height - 1);
		texPos += step;
		ft_put_pxl(cd, vars, texX, texY);
		cd->y++;
	}
	piece(vars, cd->x, cd->drawEnd, SCREENHEIGHT - 1);
	return (1);
}

int	ft_print_map(t_vars *vars)
{
	t_comm_data	cd;

	cd.x = 0;
	while (cd.x < SCREENWIDTH)
	{
		ft_get_cd(&cd, vars);
		ft_print_image(&cd, vars);
		cd.x++;
	}
	return (1);
}

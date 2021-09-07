#include "../../header.h"

double	ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (y <= 0)
		return;
	dst = vars->win.addr + (y * vars->win.line_l + x * (vars->win.bpp / 8));
	*(unsigned int *) dst = color;
}

int piece(t_vars *vars, int x, int start, int end, int color)
{
	while (start < end)
	{
		my_mlx_pixel_put(vars, x, start, color);
		start++;
	}
	return (0);
}

int	verLine (t_vars *vars, int x, int start, int end, int color)
{
	piece(vars, x, 0, start, (int) vars->color_c);
	piece(vars, x, start, end, color);
	piece(vars, x, end, screenHeight - 1, (int) vars->color_f);
	return (0);
}

int	ft_get_clr_txt(int x, int y, t_img_text *txt)
{
	return (*(unsigned int *) (txt->addr + (y * txt->line_length + x * (txt->bits_per_pixel / 8))));
}

int	ft_print_map(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < screenWidth)
	{
		double cameraX = 2 * x / (double) screenWidth - 1; //x-coordinate in camera space
		double rayDirX = vars->plr.dirX +  vars->plr.planeX * cameraX;
		double rayDirY =  vars->plr.dirY +  vars->plr.planeY * cameraX;

		int mapX = (int) vars->plr.posX;
		int mapY = (int) vars->plr.posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : ft_abs(1 / rayDirX));
		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : ft_abs(1 / rayDirY));

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?


		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (vars->plr.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - vars->plr.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (vars->plr.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - vars->plr.posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (vars->map[mapX][mapY] == '1') hit = 1;
		}

		if (side == 0) perpWallDist = (mapX - vars->plr.posX + (double) (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - vars->plr.posY + (double) (1 - stepY) / 2) / rayDirY;


		int lineHeight = (int)(screenHeight / perpWallDist);


		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;


		//int texNum = 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = vars->plr.posY + perpWallDist * rayDirY;
		else           wallX = vars->plr.posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int) (wallX * (double) vars->img_text[0].width);

		if(side == 0 && rayDirX > 0) texX = vars->img_text[0].width - texX - 1;
		if(side == 1 && rayDirY < 0) texX = vars->img_text[0].width - texX - 1;


		double step = 1.0 * vars->img_text[0].height / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		int y = drawStart;

		piece(vars, x, 0, drawStart, (int) vars->color_c);
		while (y < drawEnd)
		{// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (vars->img_text[0].height - 1);
			texPos += step;

			int	color;
			if (side)
			{
				if (stepY == 1)
					color = ft_get_clr_txt(texX, texY, &vars->img_text[3]);
				else
					color = ft_get_clr_txt(texX, texY, &vars->img_text[2]);
			}
			else
			{
				if (stepX == 1)
					color = ft_get_clr_txt(texX, texY, &vars->img_text[1]);
				else
					color = ft_get_clr_txt(texX, texY, &vars->img_text[0]);
			}
			my_mlx_pixel_put(vars, x, y, color);
			y++;
		}
		piece(vars, x, drawEnd, screenHeight - 1, (int) vars->color_f);
		x++;
	}
	return (1);
}


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

	dst = vars->win.addr + (y * vars->win.line_l + x * (vars->win.bpp / 8));
	*(unsigned int *) dst = color;
}

int	verLine (t_vars *vars, int x, int start, int end, int color)
{
	while (start < end)
	{
		my_mlx_pixel_put(vars, x, start, color);
		start++;
	}
	return (0);
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

		if (side == 1)
			verLine(vars, x, drawStart, drawEnd, 0x57f542);
		else
			verLine(vars, x, drawStart, drawEnd, 0x498c41);
		x++;
	}
	return (1);
}

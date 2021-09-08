/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:03:51 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:03:53 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MAP_H
# define PRINT_MAP_H

typedef struct s_comm_data
{
	double	perpWallDist;
	double	rayDirX;
	double	rayDirY;
	int		x;
	int		y;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		stepX;
	int		stepY;
}				t_comm_data;

typedef struct s_inside_data
{
	int		mapX;
	int		mapY;
	int		hit;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
}				t_inside_data;

#endif

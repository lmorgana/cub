/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:04:01 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:04:03 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return ;
	dst = vars->win.addr + (y * vars->win.line_l + x * (vars->win.bpp / 8));
	*(unsigned int *) dst = color;
}

int	piece(t_vars *vars, int x, int start, int end)
{
	int	color;

	if (start == 0)
		color = (int) vars->color_c;
	else
		color = (int) vars->color_f;
	while (start < end)
	{
		my_mlx_pixel_put(vars, x, start, color);
		start++;
	}
	return (0);
}

int	ft_get_clr_txt(int x, int y, t_img_text *txt)
{
	return (*(unsigned int *)(txt->addr + \
	(y * txt->line_length + x * (txt->bits_per_pixel / 8))));
}

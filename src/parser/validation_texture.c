/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:51:33 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/05 18:51:34 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_get_xmp_to_img(t_vars *vars, t_img_text	*textures)
{
	textures[0].img_texture = mlx_xpm_file_to_image(&vars->win.mlx, \
	vars->texture.no, &(textures[0].width), &(textures[0].height));
	if (textures[0].img_texture == NULL)
		return (0);
	textures[1].img_texture = mlx_xpm_file_to_image(&vars->win.mlx, \
	vars->texture.so, &(textures[1].width), &(textures[1].height));
	if (textures[1].img_texture == NULL)
		return (0);
	textures[2].img_texture = mlx_xpm_file_to_image(&vars->win.mlx, \
	vars->texture.ea, &(textures[2].width), &(textures[2].height));
	if (textures[2].img_texture == NULL)
		return (0);
	textures[3].img_texture = mlx_xpm_file_to_image(&vars->win.mlx, \
	vars->texture.we, &(textures[3].width), &(textures[3].height));
	if (textures[3].img_texture == NULL)
		return (0);
	return (1);
}

int	ft_get_adress(t_vars *vars, t_img_text *textures)
{
	(void) vars;
	textures[0].addr = mlx_get_data_addr(textures[0].img_texture, \
	&textures[0].bits_per_pixel, &textures[0].line_length, &textures[0].endian);
	textures[1].addr = mlx_get_data_addr(textures[1].img_texture, \
	&textures[1].bits_per_pixel, &textures[1].line_length, &textures[1].endian);
	textures[2].addr = mlx_get_data_addr(textures[2].img_texture, \
	&textures[2].bits_per_pixel, &textures[2].line_length, &textures[2].endian);
	textures[3].addr = mlx_get_data_addr(textures[3].img_texture, \
	&textures[3].bits_per_pixel, &textures[3].line_length, &textures[3].endian);
	return (1);
}

int	ft_clear_img_text(t_img_text *textures)
{
	if (textures)
		free(textures);
	return (1);
}

int	ft_valid_texture(t_vars *vars)
{
	t_img_text	*textures;

	textures = malloc(sizeof (t_img_text) * 4);
	if (textures)
	{
		if (ft_get_xmp_to_img(vars, textures) == 1)
		{
			ft_get_adress(vars, textures);
			vars->img_text = textures;
			return (1);
		}
		ft_clear_img_text(textures);
	}
	return (0);
}

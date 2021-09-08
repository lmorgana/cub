/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:05:03 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 18:08:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define BUFFER_SIZE 128

# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# include "src/map_validator/map_validator.h"
# include "src/print_map/print_map.h"

typedef struct s_img_text
{
	void	*img_texture;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int		height;
	int		width;
}				t_img_text;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
}				t_texture;

typedef struct s_plr
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

}				t_plr;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		en;
}			t_win;

typedef struct s_vars
{
	t_plr			plr;
	t_win			win;
	t_texture		texture;
	t_img_text		*img_text;
	unsigned long	color_c;
	unsigned long	color_f;
	char			**map;
}					t_vars;

void			ft_plr_init(t_vars *vars);
void			ft_clear_arr(char **arr);
unsigned long	ft_get_rgb(int r, int g, int b);

int				ft_print_map(t_vars *vars);
int				piece(t_vars *vars, int x, int start, int end);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
double			ft_abs(double n);
int				ft_get_clr_txt(int x, int y, t_img_text *txt);
int				ft_set_dir_print(t_inside_data *id, t_comm_data *cd, \
														t_vars *vars);
int				ft_cast_ray(t_inside_data *id, t_comm_data *cd, t_vars *vars);

char			**parser(t_vars *vars, char *path);
char			**get_data(char **arr);
int				ft_len_space(char *str);
char			**get_map(char **arr);
int				ft_check_data(char **data, t_vars *vars);
int				ft_free_texture(t_texture *texture);
int				ft_check_map(char **map, t_vars *vars);
int				ft_set_null(char **arr, int len);

int				ft_is_map(char *str);
int				ft_is_spases(char *str);

int				ft_is_equal(char *str1, char *str2);

int				get_next_line(int fd, char **line);

int				ft_is_texture_ea(char **name_value, t_vars *vars);
int				ft_is_texture_we(char **name_value, t_vars *vars);
int				ft_is_texture_no(char **name_value, t_vars *vars);
int				ft_is_texture_so(char **name_value, t_vars *vars);
int				ft_is_texture_c(char **name_value, t_vars *vars);
int				ft_is_texture_f(char **name_value, t_vars *vars);

int				ft_valid_texture(t_vars *vars);
int				ft_valid_data(t_vars *vars);

int				ft_hooks(int keycode, t_vars *vars);
void			turn_right(t_vars *vars, double rotSpeed);
void			turn_left(t_vars *vars, double rotSpeed);

#endif

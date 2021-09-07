#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# include "src/map_validator/map_validator.h"

typedef struct s_img_text
{
	void	*img_texture;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int 	height;
	int 	width;
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
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;

}				t_plr;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void 		*img;
	void 		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

#define screenWidth 640
#define screenHeight 480
#define BUFFER_SIZE 128

typedef struct s_vars
{
	t_plr 		plr;
	t_win		win;
	t_texture	texture;
	t_img_text	*img_text;
	unsigned long color_c;
	unsigned long color_f;
	char		**map;
}				t_vars;

void	ft_plr_init(t_vars *vars);
int		ft_print_map(t_vars *vars);
void	ft_clear_arr(char **arr);
unsigned	long	ft_get_rgb(int r, int g, int b);

char	**parser(t_vars *vars, char *path);
char	**get_data(char **arr);
int		ft_len_space(char *str);
char	**get_map(char **arr);
int		ft_check_data(char **data, t_vars *vars);
int		ft_free_texture(t_texture *texture);
int		ft_check_map(char **map, t_vars *vars);
int		ft_set_null(char **arr, int len);

int		ft_is_map(char *str);
int		ft_is_spases(char *str);

int		ft_is_equal(char *str1, char *str2);

int		get_next_line(int fd, char **line);

int		ft_is_texture_ea(char **name_value, t_vars *vars);
int		ft_is_texture_we(char **name_value, t_vars *vars);
int		ft_is_texture_no(char **name_value, t_vars *vars);
int		ft_is_texture_so(char **name_value, t_vars *vars);
int		ft_is_texture_c(char **name_value, t_vars *vars);
int		ft_is_texture_f(char **name_value, t_vars *vars);

int		ft_valid_texture(t_vars *vars);
int		ft_valid_data(t_vars *vars);

int		ft_hooks(int keycode, t_vars *vars);
void	turn_right(t_vars *vars, double rotSpeed);
void	turn_left (t_vars *vars, double rotSpeed);

#endif

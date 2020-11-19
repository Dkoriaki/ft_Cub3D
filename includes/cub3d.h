/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <dkoriaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:20:21 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/11/19 13:55:47 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define PI 3.1416
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define map_y 8
# define map_x 8
# define SCALE 64
# define FOV 180

typedef struct  s_player {
    int     x;
    int     y;
    double  fov;
}               t_player;

typedef struct  s_cross {
    double  dist;
    double  x;
    double  y;
    double  dx;
    double  dy;
}               t_cross;

typedef struct  s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_player    player;
    t_cross     v_cross;
    t_cross     h_cross;
    t_cross     cross;
}               t_data;


int             main(void);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             destroy_win(t_data *vars);
int             draw_player(t_data *data);
int             draw_map(t_data *img);
double          dist_btw_points(double x0, double y0, double x1, double y1);
int             is_in_map(t_cross cross);
double          correct_angle(double angle);

#endif
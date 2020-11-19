/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <dkoriaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:20:30 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/11/19 13:55:29 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double          correct_angle(double angle)
{
    if (angle < 0)
        angle += (2 * PI);
    return (angle);
}

int             is_in_map(t_cross cross)
{
    if (cross.x > 0 && cross.x < 600 && cross.y > 0 && cross.y < 600)
        return (1);
    return(0);
}

double          dist_btw_points(double x0, double y0, double x1, double y1)
{
    return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             destroy_win(t_data *vars)
{
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
        return (0);
}

int             draw_player(t_data *data)
{
    my_mlx_pixel_put(data, data->player.x, data->player.y, 0xFF0000);
    return (0);
}

int             draw_map(t_data *img)
{
    int     x = 0;
    int     y = 0;
    int     draw_x;
    int     draw_y;
    int map[map_y][map_x] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };

    while (y < map_y)
    {
        x = 0;
        while (x < map_x)
        {
            if (map[y][x] == 1)
            {
                draw_x = 0;
                while (draw_x++ < 63)
                {
                    draw_y = 0;
                    while (draw_y++ < 63)
                        my_mlx_pixel_put(img, draw_x + (x*64), draw_y + (y*64), 0xFFFFFF);
                }
            }
            x++;
        }
        y++;
    }
    draw_player(img);
    return (0);
}
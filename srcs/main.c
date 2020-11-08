#include "cub3d.h"
#include <stdio.h>

typedef struct  s_player {
    int     x;
    int     y;
}               t_player;

typedef struct  s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_player    player;
}               t_data;



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
    int map[64] =
    {
        1, 1, 1, 0, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    int     map_x = 8;
    int     map_y = 8;

    //img->img = mlx_new_image(img->mlx, 600, 600);
    //img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
    //                             &img->endian);
    while (y < map_y)
    {
        x = 0;
        while (x < map_x)
        {
            if (map[y * map_x + x] == 1)
            {
                draw_x = 0;
                while (draw_x++ < 49)
                {
                    draw_y = 0;
                    while (draw_y++ < 49)
                        my_mlx_pixel_put(img, draw_x + (x*50), draw_y + (y*50), 0xFFFFFF);
                }
            }
            x++;
        }
        y++;
    }
    draw_player(img);
    return (0);
}

/*int             clause(int keycode, t_data *vars)
{
    //mlx_clear_window(vars->mlx, vars->win);
    printf("keycode = %d\n", keycode);
    if (keycode == ESC)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    if (keycode == W)
    {
        vars->player.y += 1;
    }    
    draw_map(vars);
    return (1);
}
*/
int             control_player(int keycode, t_data *data)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if (keycode == W)
        data->player.y -= 1;
    if (keycode == S)
        data->player.y += 1;
    if (keycode == A)
        data->player.x -= 1;
    if (keycode == D)
        data->player.x += 1;
    printf("player.x = %d\nplayer.y= %d\n", data->player.x, data->player.y);
    return (0);
}

int             ft_next_frame(t_data *data)
{
    data->img = mlx_new_image(data->mlx, 600, 600);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
                                 &data->endian);
    draw_map(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_destroy_image(data->mlx, data->img);
    //printf("ouistiti %d\n", data->player.x);
    return(0);
}



int             main(void)
{
    t_data  img;

    img.player.x = 100;
    img.player.y = 100;

    

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, 600, 600, "Hello world!");
    //img.img = mlx_new_image(img.mlx, 600, 600);
    //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                             &img.endian);
    //draw_map(&img);
    //mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);


    mlx_hook(img.win, 2, 1L<<0, control_player, &img);
    mlx_hook(img.win, 17, 1L<<17, destroy_win, &img);
    mlx_loop_hook(img.mlx, ft_next_frame, &img);
    mlx_loop(img.mlx);
    return (0);
}

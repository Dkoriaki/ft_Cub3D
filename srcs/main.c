#include "cub3d.h"


void            found_horizontal_cross(t_data *data)
{
    /*int map[map_y][map_x] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };*/

    //double  angle = FOV * (PI/180); // pour travailer avec des angles normaux, IL FAUDRA LE CHANGER

    if (data->player.fov > 0 && data->player.fov < PI)    // the ray looking up
    {
        data->h_cross.dy = -SCALE;
        data->h_cross.y = floor(data->player.y/SCALE) * SCALE - 0.001;
        data->h_cross.dx = SCALE/tan(data->player.fov);
        data->h_cross.x = data->player.x + (data->player.y - data->h_cross.y)/tan(data->player.fov);
    }
    else                        // the ray looking down
    {
        data->h_cross.dy = SCALE;
        data->h_cross.y = floor(data->player.y/SCALE) * SCALE + SCALE;
        data->h_cross.dx = -SCALE/tan(data->player.fov);
        data->h_cross.x = data->player.x + (data->player.y - data->h_cross.y)/tan(data->player.fov);
    }
    
    /*double  alpha = 60 * (PI/180);
    double  Ya = -SCALE;
    double  Xa = floor(64/tan(alpha));

    data->cross.hy = floor(data->player.y/64) * 64 - 0.0001;                         //position y du croisement
    data->cross.hx = data->player.x + (data->player.y - data->cross.hy)/tan(alpha); //position x du croisement
    pos_y = data->cross.hy/SCALE;    //Ordonnee de la case
    pos_x = h_dist.x/SCALE;    //Abscisse de la case 
    while (map[pos_y][pos_x] != 1)  //On cherche la case ou il y a un mur
    {
       h_dist.x += Xa;        //incrementation d'ordonnee en ordonnee
       h_dist.y += Ya;
       pos_y = h_dist.y/64;      //changement de case
       pos_x = h_dist.x/64;
    }
    h_dist.dist = sqrt((data->player.x - h_dist.x) * (data->player.x - h_dist.x) + (data->player.y - h_dist.y) * (data->player.y - h_dist.y));*/
}

void             found_vertical_cross(t_data *data)
{
    /*int map[map_y][map_x] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };*/

    //double  angle = FOV * (PI/180); // pour travailer avec des angles normaux, IL FAUDRA LE CHANGER

    if (data->player.fov > M_PI_2 && data->player.fov < 3 * M_PI_2)    // the ray looking left
    {
        data->v_cross.dx = -SCALE;
        data->v_cross.x = floor(data->player.x/SCALE) * SCALE - 0.001;
        data->v_cross.dy = SCALE*tan(data->player.fov);
        data->v_cross.y = data->player.y + (data->player.x - data->v_cross.x)*tan(data->player.fov);
    }
    else                        // the ray looking right
    {
        data->v_cross.dx = SCALE;
        data->v_cross.x = floor(data->player.x/SCALE) * SCALE + SCALE;
        data->v_cross.dy = -SCALE * tan(data->player.fov);
        data->v_cross.y = data->player.y + (data->player.x - data->v_cross.x)*tan(data->player.fov);
        
    }
    
    /*
    t_dist  v_dist;
    int     pos_x;
    int     pos_y;
    double  alpha = 60 * (PI/180);
    double  Ya = floor(64/tan(alpha));
    double  Xa = 64;

    v_dist.x = floor(data->player.x/64) * 64 + 64;
    v_dist.y = data->player.y + (data->player.x - v_dist.x) * tan(alpha);
    pos_x = v_dist.x/64;
    pos_y = v_dist.y/64;

    while (map[pos_y][pos_x] != 1)  //On cherche la case ou il y a un mur
    {
       v_dist.x += Xa;        //incrementation d'ordonnee en ordonnee
       v_dist.y += Ya;
       pos_y = v_dist.y/64;      //changement de case
       pos_x = v_dist.x/64;
    }
    v_dist.dist = sqrt((data->player.x - v_dist.x) * (data->player.x - v_dist.x) + (data->player.y - v_dist.y) * (data->player.y - v_dist.y));
    return(v_dist);*/
}

void            found_cross(t_data *data)
{
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
    //t_cross     cross;


    found_horizontal_cross(data);
    while (is_in_map(data->h_cross) && map[(int)(data->h_cross.y/SCALE)][(int)(data->h_cross.x/SCALE)] != 1)
    {
        data->h_cross.x += data->h_cross.dx;
        data->h_cross.y += data->h_cross.dy;
    }
    data->h_cross.dist = dist_btw_points(data->player.x, data->player.y, data->h_cross.x, data->h_cross.y);
    found_vertical_cross(data);
    //printf("v_y = %lf\nv_x = %lf\n", data->v_cross.y, data->v_cross.x);
    while (is_in_map(data->v_cross) && map[(int)data->v_cross.y/SCALE][(int)data->v_cross.x/SCALE] != 1)
    {
        data->v_cross.x += data->v_cross.dx;
        data->v_cross.y += data->v_cross.dy;
        //printf("cross_x = %lf\ncross_y = %lf\n", data->v_cross.x, data->v_cross.y);
        printf("fov = %lf\n", data->player.fov);
    }
    data->v_cross.dist = dist_btw_points(data->player.x, data->player.y, data->v_cross.x, data->v_cross.y);
    data->cross = (data->h_cross.dist < data->v_cross.dist) ? data->h_cross : data->v_cross;
    //return(cross);
}

int             draw_ray(t_data *data)
{
    double     dx;
    double     dy;
    double     steps;
    double     Xinc;
    double     Yinc;
    double     x;
    double     y;

    /*while ()
    found_horizontal_cross(data);
    found_vertical_cross(data);
    data->cross = (H_dist.dist < V_dist.dist)? H_dist : V_dist;
    dx = data->wall.x - data->player.x;
    dy = data->wall.y - data->player.y;*/
    //cross = found_cross(data);
    dx = data->cross.x - data->player.x;
    dy = data->cross.y - data->player.y;
    steps = (fabs(dx) > fabs(dy))? fabs(dx) : fabs(dy);
    Xinc = dx / steps;
    Yinc = dy / steps;
    x = data->player.x;
    y = data->player.y;
    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(data, x, y, 0xFF0000);
        x += Xinc;
        y += Yinc;
    }
    return (0);
}

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
    if (keycode == RIGHT)
        data->player.fov -= 0.05;
    if (keycode == LEFT)
        data->player.fov += 0.05;
    //data->player.fov = correct_angle(data->player.fov);
    found_cross(data);
    return (0);
}

int             ft_next_frame(t_data *data)
{
    data->img = mlx_new_image(data->mlx, 600, 600);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
                                 &data->endian);
    draw_map(data);
    draw_ray(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_destroy_image(data->mlx, data->img);
    return(1);
}

int             main(void)
{
    t_data  img;

    img.player.x = 100;
    img.player.y = 100;
    img.player.fov = FOV * (PI/180);

    

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, 600, 600, "Hello world!");
    mlx_hook(img.win, 2, 1L<<0, &control_player, &img);
    mlx_hook(img.win, 17, 1L<<17, destroy_win, &img);
    mlx_loop_hook(img.mlx, ft_next_frame, &img);
    mlx_loop(img.mlx);
    return (0);
}

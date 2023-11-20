/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <larzuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:24:35 by larzuman          #+#    #+#             */
/*   Updated: 2022/04/21 19:19:37 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_mlx *mlx)
{
	mlx->data.img = mlx_new_image(mlx->mlx, mlx->screen_w, mlx->screen_h);
	mlx->cat.img = mlx_xpm_file_to_image(mlx->mlx,
			"./texture/cat.xpm", &mlx->cat.width, &mlx->cat.height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx,
			"./texture/wall.xpm", &mlx->wall.width, &mlx->wall.height);
	mlx->cheese.img = mlx_xpm_file_to_image(mlx->mlx,
			"./texture/cheese.xpm", &mlx->cheese.width, &mlx->cheese.height);
	mlx->d.img = mlx_xpm_file_to_image(mlx->mlx,
			"./texture/d.xpm", &mlx->d.width, &mlx->d.height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx,
			"./texture/exit.xpm", &mlx->exit.width, &mlx->exit.height);
}

void	set_addr(t_mlx *mlx)
{
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,
			&mlx->data.line_length, &mlx->data.endian);
	mlx->wall.addr = mlx_get_data_addr(mlx->wall.img, &mlx->wall.bits_per_pixel,
			&mlx->wall.line_length, &mlx->wall.endian);
	mlx->cheese.addr = mlx_get_data_addr(mlx->cheese.img, &mlx->cheese.bits_per_pixel,
			&mlx->cheese.line_length, &mlx->cheese.endian);
	mlx->d.addr = mlx_get_data_addr(mlx->d.img,
			&mlx->d.bits_per_pixel, &mlx->d.line_length, &mlx->d.endian);
	mlx->exit.addr = mlx_get_data_addr(mlx->exit.img, &mlx->exit.bits_per_pixel,
			&mlx->exit.line_length, &mlx->exit.endian);
}

void	clear(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->screen_h)
	{
		x = 0;
		while (x < mlx->screen_w)
		{
			my_mlx_pixel_put(&mlx->data, x, y, rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}

int	release(int key)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		g_globs.is_pressed = 0;
	return (0);
}

int	is_wall(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '1')
		return (1);
	return (0);
}

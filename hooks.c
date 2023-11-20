/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <larzuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:23:50 by larzuman          #+#    #+#             */
/*   Updated: 2022/04/19 23:12:19 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_data *data, int x, int y)
{
	int		res;

	res = *(int *)(data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8)));
	return (res);
}

int	rgb(int r, int g, int b)
{
	int		res;

	res = r << 16 | g << 8 | b;
	return (res);
}

void	draw_walls(t_mlx *mlx, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->wall.height)
	{
		j = 0;
		while (j < mlx->wall.width)
		{
			my_mlx_pixel_put(&mlx->data, x + j, y + i,
				get_color(&mlx->wall, j, i));
			++j;
		}
		++i;
	}
}

void	draw_texture(t_mlx *mlx, int x, int y, t_data texture)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < texture.height)
	{
		j = 0;
		while (j < texture.width)
		{
			color = get_color(&texture, j, i);
			if (color == 0xff000000)
			{
				color = rgb(0, 0, 0);
				my_mlx_pixel_put(&mlx->data, x + j, y + i, color);
			}
			else
				my_mlx_pixel_put(&mlx->data, x + j, y + i, color);
			++j;
		}
		++i;
	}
}

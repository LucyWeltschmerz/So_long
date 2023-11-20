/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <larzuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:18:27 by larzuman          #+#    #+#             */
/*   Updated: 2022/04/20 20:43:55 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bon_bonus.h"

void	bon(t_mlx *mlx)
{
	char	*tmp;

	mlx_string_put(mlx->mlx, mlx->win, 20, 20,
		rgb(255, 255, 255), "count = ");
	tmp = ft_itoa(g_globs.move_count);
	mlx_string_put(mlx->mlx, mlx->win, 100, 20,
		rgb(255, 255, 255), tmp);
	free(tmp);
}

void	esc_n(t_mlx *mlx)
{
	if (mlx->map[(int)mlx->posy][(int)mlx->posx] == 'N')
	{
		ft_sleep();
		esc("");
	}
}

int	esc(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0);
}

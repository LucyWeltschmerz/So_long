/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_this_shit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <larzuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:25:44 by larzuman          #+#    #+#             */
/*   Updated: 2022/04/19 23:11:56 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit(0);
	return (0);
}

void	strdel(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

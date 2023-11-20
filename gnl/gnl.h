/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <larzuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:17:55 by larzuman          #+#    #+#             */
/*   Updated: 2022/04/19 23:18:38 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		get_char(char *str, char c);
char	*get_before_str(char *buf);
char	*del(char *memory);
int		read_result(int r, char **line, char **tmp);
int		get_next_line(int fd, char **line);

#endif

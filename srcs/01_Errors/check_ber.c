/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:22:18 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 16:09:22 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"
#include <stdio.h>

int	check_extension(char *path)
{
	size_t len;
	int fd;

	len = ft_strlen(path);
	fd = open(path, O_RDONLY);
	close(fd);
	if ((path[len - 2] != 'r' && path[len - 3] != 'e' && path[len - 4] != 'b'
		&& path[len - 5] != '.') || fd < 0)
		return (FAILURE);
	else
		return (SUCCESS);
}
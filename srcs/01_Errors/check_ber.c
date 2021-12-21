/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:22:18 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 14:11:27 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

int	check_extension(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if ((path[len - 3] != 'b' && path[len - 2] != 'e'
				&& path[len - 1] != 'r'
				&& path[len - 4] != '.') || fd < 0)
			return (FAILURE);
		else
			return (SUCCESS);
	}
}

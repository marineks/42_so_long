/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:41:45 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 14:55:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"
#include <stdio.h>

void	printMap(int line_count, char **map)
{
	for (int row = 0; row < line_count; row++)
		printf("map : %s\n", map[row]);
}

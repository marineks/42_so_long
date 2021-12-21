/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:41:45 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/20 13:41:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include "../../includes/get_next_line.h"
#include <stdio.h>

void	printMap_bonus(t_data *data)
{
	for (int row = 0; row < data->map.line_count; row++)
		printf("map : %s\n", data->map.map[row]);
}

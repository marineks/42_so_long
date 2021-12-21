/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:28:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 14:27:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include "../../includes/get_next_line.h"

void	error_msg_bonus(char *str, t_data *data)
{
	if (data->map.map)
		ft_free_bonus(data->map.map);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}

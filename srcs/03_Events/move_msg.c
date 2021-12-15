/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:28:57 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 10:51:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(PEACH, 1);
	printf("Moves counter : %d\n", data->steps_count);
	ft_putstr_fd(RESET, 1);
}
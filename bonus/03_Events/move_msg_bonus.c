/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:28:57 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/20 13:41:17 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	move_msg_bonus(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(PEACH, 1);
	printf("Moves counter : %d\n", data->steps_count);
	ft_putstr_fd(RESET, 1);
}

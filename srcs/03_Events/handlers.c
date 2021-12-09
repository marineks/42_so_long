/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:11:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 09:25:49 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	// frees all the ressources that have been allocated for the window when it is no longer needed.
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // set to NULL after the call to mlx_destroy_window to make the "mlx put pixel" check actually works.
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}
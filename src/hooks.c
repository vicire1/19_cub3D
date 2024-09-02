/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:42 by vdecleir          #+#    #+#             */
/*   Updated: 2024/09/02 11:02:47 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == W)
		data->rc->move_f = 1;
	if (keysym == S)
		data->rc->move_b = 1;
	if (keysym == L_ARR)
		data->rc->rot_l = 1;
	if (keysym == R_ARR)
		data->rc->rot_r = 1;
	if (keysym == A)
		data->rc->move_l = 1;
	if (keysym == D)
		data->rc->move_r = 1;
	if (keysym == TAB)
		data->rc->mouse = 1;
	if (keysym == SPACE)
		data->rc->shoot = 1;
	if (keysym == ESC)
		free_all(data, NULL, 0);
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == W)
		data->rc->move_f = 0;
	if (keysym == S)
		data->rc->move_b = 0;
	if (keysym == L_ARR)
		data->rc->rot_l = 0;
	if (keysym == R_ARR)
		data->rc->rot_r = 0;
	if (keysym == A)
		data->rc->move_l = 0;
	if (keysym == D)
		data->rc->move_r = 0;
	if (keysym == TAB)
		data->rc->mouse = 0;
	if (keysym == SPACE)
	{
		data->rc->shoot = 0;
		data->counter = 0;
	}
	return (0);
}

int	cross_escape(t_data *data)
{
	free_all(data, NULL, 0);
	return (0);
}

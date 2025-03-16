/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:30:43 by aakhrif           #+#    #+#             */
/*   Updated: 2025/03/14 16:31:43 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_thread_status(t_game *game, int status)
{
	pthread_mutex_lock(&game->mutex);
	game->exit_thread = status;
	pthread_mutex_unlock(&game->mutex);
}

void	set_thread_animation(t_game *g, int val)
{
	pthread_mutex_lock(&g->mutex);
	g->animation = val;
	pthread_mutex_unlock(&g->mutex);
}

int	get_thread_animation(t_game *g)
{
	int	val;

	pthread_mutex_lock(&g->mutex);
	val = g->animation;
	pthread_mutex_unlock(&g->mutex);
	return (val);
}

int	get_thread_status(t_game *g)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&g->mutex);
	status = g->exit_thread;
	pthread_mutex_unlock(&g->mutex);
	return (status);
}

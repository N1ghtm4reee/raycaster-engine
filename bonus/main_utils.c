/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:12 by mzeouaou          #+#    #+#             */
/*   Updated: 2025/03/14 16:31:36 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	init_keys2(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'E')
	{
		game->keys.left = 115;
		game->keys.right = 119;
		game->keys.forward = 97;
		game->keys.backward = 100;
		game->player.direction = 1;
	}
	if (game->map[game->player.y][game->player.x] == 'S')
	{
		game->keys.left = 100;
		game->keys.right = 97;
		game->keys.forward = 115;
		game->keys.backward = 119;
		game->player.direction = 2;
	}
}

void	init_keys(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'N')
	{
		game->keys.left = 97;
		game->keys.right = 100;
		game->keys.forward = 119;
		game->keys.backward = 115;
		game->player.direction = 0;
	}
	if (game->map[game->player.y][game->player.x] == 'W')
	{
		game->keys.left = 119;
		game->keys.right = 115;
		game->keys.forward = 100;
		game->keys.backward = 97;
		game->player.direction = 3;
	}
	init_keys2(game);
}

void	*draw_animation_thread(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	while (1)
	{
		if (get_thread_status(g) == 1)
			return (NULL);
		if (get_thread_animation(g) == 1)
		{
			usleep(100000);
			set_thread_animation(g, 2);
		}
		else if (get_thread_animation(g) == 2)
		{
			usleep(100000);
			set_thread_animation(g, 3);
		}
		else if (get_thread_animation(g) == 3)
		{
			usleep(100000);
			set_thread_animation(g, 0);
		}
		else
			usleep(100000);
	}
}

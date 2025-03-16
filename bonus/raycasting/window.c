/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:59:31 by aakhrif           #+#    #+#             */
/*   Updated: 2025/03/14 16:31:02 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_images(t_game *game)
{
	if (game->wall_north.img)
		mlx_destroy_image(game->window.cnx, game->wall_north.img);
	if (game->wall_south.img)
		mlx_destroy_image(game->window.cnx, game->wall_south.img);
	if (game->wall_east.img)
		mlx_destroy_image(game->window.cnx, game->wall_east.img);
	if (game->wall_west.img)
		mlx_destroy_image(game->window.cnx, game->wall_west.img);
	if (game->door.img)
		mlx_destroy_image(game->window.cnx, game->door.img);
	if (game->p0.img)
		mlx_destroy_image(game->window.cnx, game->p0.img);
	if (game->p1.img)
		mlx_destroy_image(game->window.cnx, game->p1.img);
	if (game->p2.img)
		mlx_destroy_image(game->window.cnx, game->p2.img);
	if (game->p3.img)
		mlx_destroy_image(game->window.cnx, game->p3.img);
}

int	ft_close(t_game *game, int e_status)
{
	if (e_status != 0 && e_status != 1)
		e_status = 0;
	set_thread_status(game, 1);
	pthread_join(game->thread, NULL);
	destroy_images(game);
	if (game->window.img.img)
		mlx_destroy_image(game->window.cnx, game->window.img.img);
	if (game->window.win)
		mlx_destroy_window(game->window.cnx, game->window.win);
	if (game->window.cnx)
	{
		mlx_destroy_display(game->window.cnx);
		free(game->window.cnx);
	}
	pthread_mutex_destroy(&game->mutex);
	free_all_in_gc();
	exit(e_status);
}

void	ft_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->window.img.addr + (y * game->window.img.line_length + \
	x * (game->window.img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	drawer(t_game *game)
{
	cast_rays(game);
	mlx_put_image_to_window(game->window.cnx, game->window.win \
	, game->window.img.img, 0, 0);
	draw_mini_map(game);
	if (!get_thread_animation(game))
		draw_animation(game, &game->p0);
	else if (get_thread_animation(game) == 1)
		draw_animation(game, &game->p1);
	else if (get_thread_animation(game) == 2)
		draw_animation(game, &game->p2);
	if (get_thread_animation(game) == 3)
		draw_animation(game, &game->p3);
	return (0);
}

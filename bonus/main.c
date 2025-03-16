/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:09:34 by mzeouaou          #+#    #+#             */
/*   Updated: 2025/03/14 15:41:22 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	*get_game(void)
{
	static t_game	game;

	return (&game);
}

void	link_data(t_game *game, t_data *data)
{
	game->exit_thread = 0;
	game->view_height = 2.5;
	game->map = data->map;
	game->map_width = ft_strlen(game->map[0]);
	game->map_len = map_len(game->map);
	game->c_color = r_g_b(data->ceiling->r, data->ceiling->g, data->ceiling->b);
	game->f_color = r_g_b(data->floor->r, data->floor->g, data->floor->b);
	game->door.path = data->map_lines->line_d;
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	data = get_data();
	game = get_game();
	game->window.cnx = mlx_init();
	game->window.win = mlx_new_window(game->window.cnx, WIDTH, HEIGHT, "Cub3D");
	if (ac != 2)
		ft_error("Wrong number of arguments");
	check_path(av[1]);
	init_data(data);
	ft_check_file(av[1], data);
	check_valid_map(av[1], data);
	store_texture(data->map_lines);
	convert_f_c_to_rgb(data);
	link_data(game, data);
	find_player(game);
	init_keys(game);
	pthread_mutex_init(&game->mutex, NULL);
	pthread_create(&game->thread, NULL, draw_animation_thread, game);
	return (ft_mlx(game, data), free_all_in_gc(), 0);
}

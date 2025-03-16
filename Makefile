
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
UTILS_B = bonus/error.c
UTILS_M = mandatory/error.c

GET_NEXT_LINE = ./utils/get_next_line/get_next_line.c
PARSING = $(addprefix mandatory/parsing/, check_map.c ft_substr_parsing.c pars_color.c pars_texture.c parsing.c pars_color_utils.c pars_texture_utils.c \
			check_map_utils.c utils_prs.c)
RAYCASTING = mandatory/ft_gc_strdup.c mandatory/gc.c mandatory/main_utils.c $(addprefix mandatory/raycasting/, precasting.c raycaster.c raycaster_utils.c mlx_hooks.c directions.c draw_textures.c \
			window.c raycaster2.c ray_dir.c player.c)

PARSING_B = $(addprefix bonus/parsing/, check_map.c ft_substr_parsing.c pars_color.c pars_texture.c parsing.c pars_color_utils.c pars_texture_utils.c check_map_utils.c utils_prs.c)
RAYCASTING_B = bonus/gc_strdup.c bonus/gc.c bonus/main_utils.c $(addprefix bonus/raycasting/, ray_dir.c doors.c window.c player.c mini_map.c mouse_hooks.c precasting.c raycaster.c \
			mini_map_utils.c raycaster2.c raycaster_utils.c  mlx_hooks.c directions.c draw_textures.c)

CFILES = mandatory/main.c  ${PARSING} ${UTILS_M} ${RAYCASTING} ${GET_NEXT_LINE}
CFILES_B = bonus/main.c bonus/threads.c ${PARSING_B} ${UTILS_B} ${RAYCASTING_B} ${GET_NEXT_LINE}
OFILES = ${CFILES:.c=.o}
OFILES_B = ${CFILES_B:.c=.o}
NAME = cub3D

MLX = -lmlx -lX11 -lXext -lm

LIBFT = -Llibft -lft

all : ${NAME}

${NAME} : ${OFILES}
	${CC} ${CFLAGS} ${OFILES} -o ${NAME} ${MLX} ${LIBFT}


bonus: ${NAME} ${OFILES_B}
	${CC} ${CFLAGS} ${OFILES_B} -o ${NAME} ${MLX} ${LIBFT}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean :
	${RM} ${OFILES} ${OFILES_B}

fclean : clean
	${RM} $(NAME)
re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 12:08:52 by bahaas            #+#    #+#              #
#    Updated: 2021/06/11 14:17:44 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRCS		= srcs/render_bonus.c srcs/cast_hz_bonus.c srcs/cast_vt_bonus.c \
			  srcs/cast_ray_bonus.c srcs/minimap_bonus.c \
			  srcs/utils_bonus.c srcs/key_events_bonus.c \
			  srcs/parsing_bonus.c srcs/player_bonus.c srcs/texture_bonus.c \
			  srcs/grid_bonus.c srcs/utils_parsing_bonus.c \
			  srcs/grid_parsing_bonus.c srcs/colors_bonus.c \
			  srcs/resolution_bonus.c srcs/images_bonus.c \
			  srcs/window_bonus.c srcs/utils_init_bonus.c srcs/main_bonus.c \
			  srcs/sprites_bonus.c srcs/utils_sprites_bonus.c \
			  srcs/utils_render_bonus.c srcs/render_sprites_bonus.c \
			  srcs/save_bonus.c srcs/healthbar_bonus.c \
			  srcs/utils_colors_bonus.c

SRCS_BONUS = bonus/main.c bonus/grid_bonus.c bonus/images_bonus.c \
			 bonus/player_bonus.c bonus/window_bonus.c bonus/parsing_bonus.c \
			 bonus/texture_bonus.c bonus/utils_parsing_bonus.c bonus/sprites_bonus.c \
			 bonus/healthbar_bonus.c bonus/utils_bonus.c bonus/grid_parsing_bonus.c \
			 bonus/utils_render_bonus.c bonus/key_events_bonus.c bonus/render_bonus.c \
			 bonus/minimap_bonus.c bonus/render_sprites_bonus.c

CC		= gcc
#CFLAGS	= -Wextra -Werror -Wall
RM		= rm -f
LIB_D	= ./libft
MLX_D	= ./minilibx
HEADER	= -I /includes
HEADER_BONUS	= -I /includes
OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
			${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${LIB_D}
			${CC} ${HEADER} ${OBJS} -o ${NAME} -O -O3 -L ${LIB_D} -lft -L ${MLX_D} -lmlx -lXext -lX11 -lm

all:		${NAME}

clean:
			make clean -C ${LIB_D}
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			make fclean -C ${LIB_D}
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_BONUS}
			make -C ${LIB_D}
			${CC} ${HEADER} ${OBJS_BONUS} -o ${NAME} -O -O3 -L ${LIB_D} -lft -L ${MLX_D} -lmlx -lXext -lX11 -lm



.PHONY:		all clean fclean re run
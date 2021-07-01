# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 12:08:52 by bahaas            #+#    #+#              #
#    Updated: 2021/07/01 16:24:45 by bahaas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS		= srcs/main.c srcs/grid.c srcs/images.c \
			srcs/player.c srcs/window.c srcs/parsing.c \
			srcs/texture.c srcs/utils_parsing.c  \
		 	srcs/utils.c srcs/grid_parsing.c \
			srcs/utils_render.c srcs/key_events.c srcs/render.c 

SRCS_BONUS	= bonus/main_bonus.c bonus/grid_bonus.c bonus/images_bonus.c \
			bonus/player_bonus.c bonus/window_bonus.c bonus/parsing_bonus.c \
			bonus/texture_bonus.c bonus/utils_parsing_bonus.c \
			bonus/utils_bonus.c bonus/grid_parsing_bonus.c \
			bonus/utils_render_bonus.c bonus/key_events_bonus.c bonus/render_bonus.c \
			bonus/ennemy_bonus.c

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g
RM		= rm -f
LIB_D	= ./libft
MLX_D	= ./minilibx
HEADER	= -I /includes/solong.h
HEADER_BONUS	= -I /includes/solong_bonus.h
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
			${CC} ${HEADER_BONUS} ${OBJS_BONUS} -o ${NAME} -O -O3 -L ${LIB_D} -lft -L ${MLX_D} -lmlx -lXext -lX11 -lm



.PHONY:		all clean fclean re run

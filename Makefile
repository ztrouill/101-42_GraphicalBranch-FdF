#**************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/28 12:06:19 by ztrouill     #+#   ##    ##    #+#        #
#    Updated: 2019/03/27 21:21:13 by ztrouill    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = FdF

# FLAGS

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

FLAGS_FRMWRK = -framework OpenGL -framework AppKit -framework Carbon

# PATH_GENERAL

INCLUDE_PATH = ./includes/

LIB_PATH = ./lib/

SRCS_PATH = ./srcs/

OBJ_PATH = ./obj/

# LIB_PATH

LIBFT_PATH = $(LIB_PATH)libft/

LIBMLX_PATH = $(LIB_PATH)minilibx_macos/

LIBFMOD_PATH =  $(LIB_PATH)fmod/lib/

# INCLUDES

INCLUDE = $(INCLUDE_PATH)fdf.h

INCLUDE_STRUCT = $(INCLUDE_PATH)fdf_struct.h

INCLUDE_DEFINE = $(INCLUDE_PATH)fdf_define.h

# LIB

LIBFT = $(LIBFT_PATH)libft.a

LIBMLX = $(LIBMLX_PATH)libmlx.a

LIBFMOD = $(LIB_PATH)libfmod.dylib

# SRCS & OBJ

SRCS_NAME = main.c stock_param.c place_point.c draw.c events.c bresenham.c \
		tool_bar.c color.c check_error.c manage_events.c animation.c sound.c transform.c \
		projection.c init_struct.c init_segment.c freedom.c init_tab_3d.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)

# RULES // COMP AND CLEANING

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "."
		@sleep 0.5
		@echo "."
		@sleep 0.5
		@echo "."
		@sleep 0.5
	@make -C $(LIBFT_PATH)
	@make -C $(LIBMLX_PATH)
	@gcc $(FLAGS) -L$(LIBFMOD_PATH) -lfmod $(LIBFT) $(LIBMLX) $(FLAGS_FRMWRK) $^ -o  $@ -rpath $(LIBFMOD_PATH)
	@echo ":)"

$(OBJ_PATH)%.o : $(SRCS_PATH)%.c $(INCLUDE) $(INCLUDE_STRUCT) $(INCLUDE_DEFINE)
	@mkdir $(OBJ_PATH) 2< /dev/null || true
	@gcc $(FLAGS) -c $< -o $@

clean :
	@echo "."
	@sleep 0.5
	@echo "."
	@sleep 0.5
	@echo "."
	@sleep 0.5
	@echo "Bye Bye"
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(LIBMLX_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH) 2< /dev/null || true

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 19:04:17 by nrivoire          #+#    #+#              #
#    Updated: 2020/03/11 19:25:43 by nrivoire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


#################
##  VARIABLES  ##
#################

#	Output
NAME		=	rt

#	Sources
SRC_SUP		=	{events,draw_tools,parser,post_process,obj_generating,ui,procedural_texture}
SRC_PATH	=	src

SRC_NAME	=	main.c
SRC_NAME	+=	rays.c
SRC_NAME	+=	usage.c
SRC_NAME	+=	init.c

SRC_NAME	+=	events/key_event.c
SRC_NAME	+=	events/mouse_event.c

SRC_NAME	+=	draw_tools/get_pixel.c
SRC_NAME	+=	draw_tools/display.c

SRC_NAME	+=	parser/parser.c
SRC_NAME	+=	parser/parser_init_value.c
SRC_NAME	+=	parser/parser_block_base.c
SRC_NAME	+=	parser/parser_block_light.c
SRC_NAME	+=	parser/parser_block_object.c
SRC_NAME	+=	parser/parser_utils.c
SRC_NAME	+=	parser/parser_color.c
SRC_NAME	+=	parser/parser_color_hexa.c
SRC_NAME	+=	parser/parser_list.c

SRC_NAME	+=	post_process/negative.c
SRC_NAME	+=	post_process/cel_shading.c
SRC_NAME	+=	post_process/greyscale.c
SRC_NAME	+=	post_process/sepia.c
SRC_NAME	+=	post_process/post_process.c

SRC_NAME	+=	obj_generating/put_texture_on_surface.c
SRC_NAME	+=	obj_generating/inter_ray_quadric.c
SRC_NAME	+=	obj_generating/make_obj.c
SRC_NAME	+=	obj_generating/create_tab_obj.c

SRC_NAME	+=	procedural_texture/noise.c
SRC_NAME	+=	procedural_texture/perlin_noise.c

SRC_NAME	+=	closest_intersect.c

SRC_NAME	+=	ui/menu.c
SRC_NAME	+=	ui/menu_selected.c
SRC_NAME	+=	ui/menu_bouton.c
SRC_NAME	+=	ui/write_text_menu.c
SRC_NAME	+=	ui/ui_utils.c
SRC_NAME	+=	ui/stats.c
SRC_NAME	+=	bonus_tools.c

#	Objects
OBJ_PATH	=	.objects
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#	Includes
INC_PATH	=	includes
INC_NAME	=	rt.h
INC_NAME	+=	pp.h
INC			=	$(addprefix $(INC_PATH)/,$(INC_NAME))

CPPFLAGS	=	-I $(INC_PATH)
LDFLAGS		=	-O3 -flto -ffast-math -march=native -L libft
LDLIBS		=	-lft

PWD			:=	$(shell pwd)
#	SDL
#SDL = -lft -F /Library/Frameworks/ -L sdl2/2.0.10/lib/ -lSDL2 -L sdl2_image/2.0.5/lib/ -lSDL2_image
#PATH_TO_SDL = ./
INC_SDL		=	-I ./frameworks/SDL2.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_ttf.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_image.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_net.framework/Headers
INC_SDL		+=	-F ./frameworks
FRAMEWORKSDIR := ./frameworks
SDL 		=	-F $(FRAMEWORKSDIR) -framework SDL2 -framework SDL2_image -framework SDL2_ttf -rpath $(FRAMEWORKSDIR)

#	Compiler
CC			=	clang
CFLAGS		=	-Wall -Wextra #-Werror -g
#CFLAGS		+=	-Wunused-command-line-argument
#CFLAGS		+=	-Wno-error
#CFLAGS		+=	--cflags --glibs
#CFLAGS		+=	-ggdb -g -fsanitize=address

################
##   COLORS   ##
################

GREY=$ \x1b[30m
RED=$ \x1b[31m
GREEN=$ \x1b[32m
YELLOW=$ \x1b[33m
BLUE=$ \x1b[34m
PINK=$ \x1b[35m
CYAN=$ \x1b[36m
WHITE=$ \x1b[37m

# This is a minimal set of ANSI/VT100 color codes
END=$ \x1b[0m
BOLD=$ \x1b[1m
UNDER=$ \x1b[4m
SUR=$ \x1b[7m

#################
##  TARGETS    ##
#################

# $@ -> nom de la règle
# $^ -> représente tout ce qui est apres le :
# $< -> nom de la dependance

#gtk : `pkg-config --cflags --libs gtk+-2.0`

# empêche le Makefile de confondre un fichier et une règle en cas de même nom
.PHONY: all clean fclean re sdl

all: make_libft $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

make_libft:
	@make -C ./libft/

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SDL) $(INC_SDL) libft/libft.a $^ -o $@
	@printf "\n$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/$(SRC_SUP)
	@printf "$(YELLOW)$(BOLD)[COMPILE] $(END) $(<:.c=).c.............."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_SDL) -o $@ -c $<
	@printf "\r																\r"

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
	norminette $(SRC_PATH) $(INC_PATH)

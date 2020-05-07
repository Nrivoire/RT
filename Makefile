# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 19:04:17 by nrivoire          #+#    #+#              #
#    Updated: 2020/05/07 20:17:02 by jacket           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

NAME = rtv1
SRC_SUP = 	events			\
			draw_tools		\
			parser			\
			post_process	\
			ray_tracer		\
			obj_generating	\
			ui				\
			init			\

SRC_PATH = src
SRC_NAME = 	draw_tools/display.c				\
			draw_tools/get_pixel.c				\
			draw_tools/pixel_put.c				\
			events/event_render.c				\
			events/key_event.c					\
			events/mouse_event.c				\
			events/obj_event.c					\
			events/plane_event.c				\
			events/rotate.c						\
			init/create_first_tab_obj.c			\
			init/create_first_tab_lgt.c			\
			init/init_value.c					\
			init/init_sdl.c						\
			init/init_menu.c					\
			obj_generating/make_tab_obj.c		\
			obj_generating/inter_ray_quadric.c	\
			obj_generating/make_plan.c			\
			obj_generating/make_sphere.c		\
			obj_generating/make_cone.c			\
			obj_generating/make_cylinder.c		\
			parser/parser_block_base.c			\
			parser/parser_block_light.c			\
			parser/parser_block_object.c		\
			parser/parser_color_hexa.c			\
			parser/parser_color.c				\
			parser/parser_init_value.c			\
			parser/parser_list.c				\
			parser/parser_utils.c				\
			parser/parser.c						\
			post_process/blur_utils.c			\
			post_process/blur.c					\
			post_process/cel_shading.c			\
			post_process/greyscale.c			\
			post_process/negative.c				\
			post_process/post_process_utils.c	\
			post_process/sepia.c				\
			post_process/supersampling.c		\
			ray_tracer/colors.c					\
			ray_tracer/loop.c					\
			ray_tracer/ray_tracer.c				\
			ray_tracer/select_obj.c				\
			ui/menu_bouton.c					\
			ui/menu_selected_utils.c			\
			ui/menu_selected.c					\
			ui/menu.c							\
			ui/stats.c							\
			ui/ui_utils.c						\
			ui/write_text_menu.c				\
			main.c								\
			usage.c
OBJ_PATH = .objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC_PATH = includes
INC_NAME = rt.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LIB = -L libft
LDFLAGS = -O3 -ffast-math -march=native
LDLIBS = -lm -lft
ifeq ($(OS), Windows_NT)
	INC_SDL = 	-I SDL\SDL2-2.0.12\i686-w64-mingw32\include\SDL2 		\
				-I SDL\SDL2_image-2.0.5\i686-w64-mingw32\include\SDL2 	\
				-I SDL\SDL2_ttf-2.0.15\i686-w64-mingw32\include\SDL2
	LIB_SDL = 	-L SDL\SDL2-2.0.12\i686-w64-mingw32\lib 		\
				-L SDL\SDL2_image-2.0.5\i686-w64-mingw32\lib 	\
				-L SDL\SDL2_ttf-2.0.15\i686-w64-mingw32\lib
	SDL = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
	NORMINETTE = ~/.norminette/norminette.rb
	OS = $(PINK)Windows
else
	OS = $(shell uname -s)
	ifeq ($(OS), Darwin)
		FM = SDL/frameworks
		INC_SDL = 	-I $(FM)/SDL2.framework/Versions/A/Headers 			\
					-I $(FM)/SDL2_image.framework/Versions/A/Headers 	\
					-I $(FM)/SDL2_ttf.framework/Versions/A/Headers
		SDL = -rpath $(FM) -F $(FM) -framework SDL2 -framework SDL2_image 	\
				-framework SDL2_ttf
		NORMINETTE = norminette
		OS = $(END)$(PINK)Mac OS
	else
		ifeq ($(OS), Linux)
			INC_SDL = -I/usr/include/SDL2 -D_REENTRANT
			SDL = -lSDL2 -lSDL2_image -lSDL2_ttf
			NORMINETTE = ~/.norminette/norminette.rb
			OS = $(END)$(PINK)Linux
		else
			OS = $(RED)This OS is not supported
		endif
	endif
endif
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(LDFLAGS)
CPPFLAGS = -I $(INC_PATH) -I libft/$(INC_PATH)

################
##   COLORS   ##
################

ERASE = 	\033[2K\r
GREY = 		\033[30m
RED = 		\033[31m
GREEN = 	\033[32m
YELLOW = 	\033[33m
BLUE = 		\033[34m
PINK = 		\033[35m
CYAN = 		\033[36m
WHITE = 	\033[37m
END = 		\033[0m
BOLD = 		\033[1m
UNDER = 	\033[4m
SUR = 		\033[7m

#################
##  TARGETS    ##
#################

.PHONY: all make_libft detected_OS clean fclean re norme

all: make_libft detected_OS $(NAME)
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "$(BLUE)> $(NAME) : $(RED)Project fail !$(END)\n"
else
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"
endif

make_libft:
	@make -C libft

detected_OS:
	@printf "$(BOLD)$(GREY)Detected OS : $(OS)$(END)\n"

$(NAME): $(OBJ)
ifneq ($(OS), $(RED)This OS is not supported)
	@$(CC) $(CFLAGS) $(LIB) $(LIB_SDL) $^ $(SDL) $(LDLIBS) -o $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"
endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) libft/libft.a
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/,$(SRC_SUP))
ifeq ($(OS), $(RED)This OS is not supported)
	@touch $@
else
	@printf "$(ERASE)$(YELLOW)$(BOLD)[COMPILE] $(END) $(<:.c=).c"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_SDL) -c $< -o $@
endif

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) $(NAME).exe
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "Norminette is not supported\n"
else
	$(NORMINETTE) libft/includes libft/sources $(INC_PATH) $(SRC_PATH)
endif

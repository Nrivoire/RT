# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/07 15:20:38 by nrivoire     #+#   ##    ##    #+#        #
#    Updated: 2020/02/13 12:57:03 by nrivoire    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Output
NAME = rt

#	Sources
SRC_SUP = {events,draw_tools}
SRC_PATH	=	src

SRC_NAME	=	main.c
SRC_NAME	+=	display.c
SRC_NAME	+=	events/key_event.c
SRC_NAME	+=	events/mouse_button_event.c
SRC_NAME	+=	events/mouse_motion_event.c
SRC_NAME	+=	draw_tools/draw_circle.c
SRC_NAME	+=	draw_tools/put_picture.c
SRC_NAME	+=	draw_tools/get_pixel.c
SRC_NAME	+=	rays.c
SRC_NAME	+=	inter_line_quadratic.c
SRC_NAME	+=	

#	Objects
OBJ_PATH = .objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#	Includes
INC_PATH = includes
INC_NAME = rt.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CPPFLAGS = -I $(INC_PATH)
LDFLAGS =  -O3 -flto -ffast-math -march=native -L libft
LDLIBS = -lft

PWD := $(shell pwd)
#	SDL
#SDL = -lft -F /Library/Frameworks/ -L sdl2/2.0.10/lib/ -lSDL2 -L sdl2_image/2.0.5/lib/ -lSDL2_image
#PATH_TO_SDL = ./
INC_SDL		=	-I ./frameworks/SDL2.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_ttf.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_image.framework/Versions/A/Headers
INC_SDL		+=	-I ./frameworks/SDL2_net.framework/Headers
INC_SDL		+=	-F ./frameworks
FRAMEWORKSDIR := ./frameworks
SDL 		= -F $(FRAMEWORKSDIR) -framework SDL2 -framework SDL2_image -framework SDL2_ttf -rpath $(FRAMEWORKSDIR)

#	Compiler
CC = clang
CFLAGS = -Wall -Wextra #-Werror

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
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_SDL) -o $@ -c $<
	@printf "\r$(YELLOW)$(BOLD)[COMPILE] $(END) $(<:.c=)..."

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

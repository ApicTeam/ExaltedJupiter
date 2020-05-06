NAME = endgame

INC = inc/minilib.h
	
HDR = minilib.h

SRC = src/main.c \
	src/allerror.c \
	src/create_window.c \
	src/render_res.c \

SRCS = main.c \
	allerror.c \
	create_window.c \
	render_res.c \

SDLF =  -I ./framework/SDL2.framework/Versions/A/Headers -F ./framework -framework SDL2 -rpath ./framework -I ./framework/SDL2_image.framework/Versions/A/Headers -F ./framework -framework SDL2_image -rpath ./framework 

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

SDLM = -I ./framework/SDL2_mixer.framework/Versions/A/Headers -F ./framework -framework SDL2_mixer -rpath ./framework

SDLT = -I ./framework/SDL2_ttf.framework/Versions/A/Headers -F ./framework -framework SDL2_ttf -rpath ./framework

all: install clean
install:
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAG) $(SDLM) $(SRCS) $(SDLF) $(SDLT) -o $(NAME) -I $(HDR) 
uninstall:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
reinstall: uninstall all

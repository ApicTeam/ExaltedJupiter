NAME = endgame

INC = game.h \
	minilib.h \
	Structures.h 

HDRS = inc/game.h \
	inc/minilib.h \
	inc/Structures.h 

SRC = main.c \
	game.c \
	sdl_initialization.c \
	error_handler.c \
	sdl_base.c \
	sdl_utils.c \
	garbage_collector.c \
	move_manager.c \
	animation.c \
	utils.c \
	Map.c \
	test_lvl.c \
	create_knight.c \
	knight_behaviour.c \
	get_distance_to_hero.c \
	knight_render.c \
	enemy_do_damage.c \
	animate_enemy.c \
	isBackground.c \
	knight_collision_detect.c \
	get_normalized_x.c \
	get_normalized_y.c \
	create_hero.c \
	hero_render.c \
	hero_collision_detect.c

SRCS = src/main.c \
	src/game.c \
	src/sdl_configs/sdl_initialization.c \
	src/utils/error_handler.c \
	src/sdl_configs/sdl_base.c \
	src/sdl_configs/sdl_utils.c \
	src/utils/garbage_collector.c \
	src/hero/movment/move_manager.c \
	src/hero/animation/animation.c \
	src/utils/utils.c \
	src/levels/Map/Map.c \
	src/levels/test_lvl.c \
	src/enemies/knight/create_knight.c \
	src/enemies/knight/knight_behaviour.c \
	src/enemies/get_distance_to_hero.c \
	src/enemies/knight/knight_render.c \
	src/enemies/enemy_do_damage.c \
	src/enemies/animate_enemy.c \
	src/levels/isBackground.c \
	src/enemies/knight/knight_collision_detect.c \
	src/enemies/get_normalized_x.c \
	src/enemies/get_normalized_y.c \
	src/hero/create_hero.c \
	src/hero/hero_render.c \
	src/hero/hero_collision_detect.c

SDLF =  -I ./resources/framework/SDL2.framework/Versions/A/Headers -F ./resource/framework -framework SDL2 -rpath ../resource/framework 

SDLI =  -I ./resource/framework/SDL2_image.framework/Versions/A/Headers -F ./resource/framework -framework SDL2_image -rpath ../framework 

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

SDLM = -I ./resource/framework/SDL2_mixer.framework/Versions/A/Headers -F ./resource/framework -framework SDL2_mixer -rpath ../resource/framework 

SDLT = -I ./resource/framework/SDL2_ttf.framework/Versions/A/Headers -F ./resource/framework -framework SDL2_ttf -rpath ../resource/framework 

all: install 
install: 
	@mkdir build
	@cp $(SRCS) .
	@cp $(HDRS) .
	@clang $(CFLAG) $(SDLF) $(SDLI) $(SDLM) $(SDLT) $(SRC) -o ./build/$(NAME)
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf ./*.gch
uninstall:
	@rm -rf ./build
clean:
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf ./*.gch
reinstall: uninstall all

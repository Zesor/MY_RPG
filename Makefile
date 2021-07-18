##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makes binary and more
##

SRC	=	main.c										\
		sources/main_loop.c							\
		sources/menu/window_and_co.c				\
		sources/menu/menu_loop.c					\
		sources/menu/handler_button.c				\
		sources/menu/music_menu.c					\
		sources/menu/htp_loop.c						\
		sources/menu/illuminate_button.c			\
		sources/menu/realeased_sprite.c				\
		sources/menu/htp_button.c					\
		sources/game/game_loop.c					\
		sources/game/init_sprite.c					\
		sources/game/init_sprite_next.c				\
		sources/pause/pause_loop.c					\
		sources/pause/init_pause.c					\
		sources/pause/button_pause_handler.c		\
		sources/pause/music_pause.c					\
		sources/game/move_character.c				\
		sources/game/view.c							\
		sources/game/init_object.c					\
		sources/game/enter_last_fight.c				\
		sources/settings/init_settings_sprt.c		\
		sources/settings/settings_loop.c			\
		sources/settings/settings_button.c			\
		sources/settings/init_buttons.c				\
		sources/settings/sf_text.c					\
		sources/settings/my_itoa.c					\
		sources/settings/change_volume.c			\
		sources/settings/my_strcat.c				\
		sources/settings/my_strlen.c				\
		sources/settings/change_framerate.c 		\
		sources/game/clock.c						\
		sources/game/life.c							\
		sources/game/shuriken.c						\
		sources/game/music_in_game.c				\
		sources/quest/create_quest.c				\
		sources/quest/print_quest.c					\
		sources/cursor/init_cursor.c 				\
		sources/game/mana.c							\
		sources/game/special_attack.c				\
		sources/tutorial/ask_for_tutorial.c			\
		sources/tutorial/text.c						\
		sources/tutorial/tutorial.c					\
		sources/tutorial/init_enemy.c				\
		sources/tutorial/clock_tutorial.c			\
		sources/tutorial/enemy_tutorial.c			\
		sources/tutorial/touch.c					\
		sources/dialogue/dialogue_tutorial.c		\
		sources/dialogue/init_dialogue.c			\
		sources/dialogue/text_dialogue.c			\
		sources/quest/check_quest.c					\
		sources/inventory/inventory.c				\
		sources/tutorial/kakashi.c					\
		sources/dialogue/print_characters.c			\
		sources/lose/lose.c							\
		sources/lose/button_lose.c					\
		sources/lose/ending_music.c					\
		sources/shop/print_shop_character.c			\
		sources/shop/shop.c							\
		sources/shop/tenten_dialogue.c				\
		sources/tutorial/reset_tutorial.c			\
		sources/parallax/init_parallax.c			\
		sources/parallax/moving_parallax.c			\
		sources/parallax/parallax_loop.c			\
		sources/particules/frame.c					\
		sources/particules/rain.c					\
		sources/particules/window.c					\
		sources/particules/gen.c					\
		sources/particules/init_ending.c			\
		sources/destroy/destroy_everything.c		\
		sources/destroy/destroy_quest_and_co.c		\
		sources/game/collision.c					\
		sources/game/general_collision.c			\
		sources/inventory/use_inventory.c			\
		sources/ramen_shop/print_ramen_character.c	\
		sources/ramen_shop/ramen.c					\
		sources/ramen_shop/teuchi_dialogue.c		\
		sources/parallax/init_player.c				\
		sources/parallax/move_final.c				\
		sources/game/fight.c						\
		sources/game/init_fight.c					\
		sources/game/shuriken_clone.c				\
		sources/game/init_life_clone.c				\
		sources/game/touch_clone.c					\
		sources/game/draw_clone.c					\
		sources/game/check_character_fight.c		\
		sources/quest/quest_game.c					\
		sources/dialogue/dialogue_kakashi.c			\
		sources/dialogue/print_dialogue.c			\
		sources/parallax/init_bars.c				\
		sources/parallax/shuriken_parallax.c		\
		sources/parallax/enemy_hit.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LDFLAGS = -L./lib/my -lmy

CPPFLAGS = -I./includes -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C lib/my re
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	@cd lib/my && make fclean
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@clear

re:	fclean all

.PHONY:	all clean fclean re

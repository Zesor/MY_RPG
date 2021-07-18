/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** destroy_everything
*/

#include "struct.h"
#include "function.h"

static void destroy_texture_background(rpg_t *rpg)
{
    sfTexture_destroy(rpg->back.back_htp_xt);
    sfTexture_destroy(rpg->back.back_texture);
    sfTexture_destroy(rpg->back.htp_key_tx);
    sfTexture_destroy(rpg->back.htp_real);
    sfTexture_destroy(rpg->back.opt_drk);
    sfTexture_destroy(rpg->back.option_text);
    sfTexture_destroy(rpg->back.play_text);
    sfTexture_destroy(rpg->back.return_drk_txt);
    sfTexture_destroy(rpg->back.return_text);
    sfTexture_destroy(rpg->back.quit_text);
    sfTexture_destroy(rpg->back.quit_drk);
    sfTexture_destroy(rpg->back.play_real);
    sfTexture_destroy(rpg->back.play_drk);
    sfTexture_destroy(rpg->back.htp_drk);
    sfTexture_destroy(rpg->back.opt_real);
}

static void destroy_sprite_background(rpg_t *rpg)
{
    sfSprite_destroy(rpg->back.back_htp_sprt);
    sfSprite_destroy(rpg->back.back_sprite);
    sfSprite_destroy(rpg->back.htp_key_sprt);
    sfSprite_destroy(rpg->back.htp_real_sprt);
    sfSprite_destroy(rpg->back.opt_real_sprt);
    sfSprite_destroy(rpg->back.option_sprt);
    sfSprite_destroy(rpg->back.play_sprt);
    sfSprite_destroy(rpg->back.return_drk_sprt);
    sfSprite_destroy(rpg->back.return_sprt);
    sfSprite_destroy(rpg->back.quit_sprt);
    sfSprite_destroy(rpg->back.quit_drk_sprt);
    sfSprite_destroy(rpg->back.play_real_sprt);
    sfSprite_destroy(rpg->back.htp_drk_sprt);
    sfSprite_destroy(rpg->back.opt_real_sprt);
}

static void destroy_all_parallax(rpg_t *rpg)
{
    sfTexture_destroy(rpg->paral.f_back_text);
    sfTexture_destroy(rpg->paral.mount_text);
    sfTexture_destroy(rpg->paral.w_mount_text);
    sfTexture_destroy(rpg->paral.cloud_text);
    sfSprite_destroy(rpg->paral.f_back_sprt);
    sfSprite_destroy(rpg->paral.mount_sprt);
    sfSprite_destroy(rpg->paral.w_mount_sprt);
    sfSprite_destroy(rpg->paral.cloud_sprt);
}

static void destroy_all_pause_menu(rpg_t *rpg)
{
    sfTexture_destroy(rpg->pause.menu_text);
    sfTexture_destroy(rpg->pause.menu_but_text);
    sfTexture_destroy(rpg->pause.quit_text);
    sfTexture_destroy(rpg->pause.menu_drk_t);
    sfTexture_destroy(rpg->pause.menu_real);
    sfSprite_destroy(rpg->pause.menu_sprt);
    sfSprite_destroy(rpg->pause.menu_but_sprt);
    sfSprite_destroy(rpg->pause.quit_sprt);
    sfSprite_destroy(rpg->pause.menu_drk_sprt);
    sfSprite_destroy(rpg->pause.quit_drk_sprt);
    sfSprite_destroy(rpg->pause.menu_real_spt);
}

void destroy_pause_back_paral(rpg_t *rpg)
{
    destroy_texture_background(rpg);
    destroy_sprite_background(rpg);
    destroy_all_parallax(rpg);
    destroy_all_pause_menu(rpg);
    destroy_every(rpg);
}
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "data.hpp"
#include "Batalha.hpp"
#include <iostream>
#include "interacao.hpp"
#include <string>
#include "Personagens.hpp"
#include "Grafico.hpp"

//FUNCOES
void desenhar();


//VARIAVEIS
ALLEGRO_BITMAP *player = NULL; // Variável que vai receber uma imagem
ALLEGRO_BITMAP *inimigo = NULL; // Variável que vai receber uma imagem
ALLEGRO_BITMAP *base_inimigo = NULL; // Variável que vai receber uma imagem


void Batalha1x1::batalhar(){

    ALLEGRO_EVENT ev2; //declarando o evento

    while (1)
    {
        al_wait_for_event(event_queue, &ev2);

        desenhar();

        if (ev2.type == ALLEGRO_EVENT_KEY_DOWN) {
        keys[ev2.keyboard.keycode] = true;

        if(keys[ALLEGRO_KEY_ESCAPE]) {
            break;
        }   
    }
     
    }
 
}

void desenhar(){
    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_scaled_bitmap(base, 0, 0, 1920, 1080, 790, 100, 20020*(res_x_comp/1920.0), 11000*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(silvio_batalha, 0, 0, 1920, 1080, 750, 0, 25020*(res_x_comp/1920.0), 16000*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(base, 0, 0, 1920, 1080, 220, 230, 20020*(res_x_comp/1920.0), 11000*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(player_batalha, 0, 0, 1920, 1080, 300, 200,  25020*(res_x_comp/1920.0), 16000*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 100, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_flip_display();
}



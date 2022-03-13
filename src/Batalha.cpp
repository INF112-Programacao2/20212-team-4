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

//VARIAVEIS

void Batalha1x1::batalhar(){
    while (1)
    {
        al_wait_for_event(event_queue, &ev0);
        al_clear_to_color(al_map_rgb(238,202,169));
        al_draw_bitmap(caixa_de_ataques,0,0,0);
        al_draw_bitmap(ataques,0,0,0);

        al_flip_display();
        if (ev0.type == ALLEGRO_EVENT_KEY_DOWN) {
        keys[ev0.keyboard.keycode] = true;

        if(keys[ALLEGRO_KEY_ESCAPE]) {
            return false;
        }   
    }
     
    }
 
}



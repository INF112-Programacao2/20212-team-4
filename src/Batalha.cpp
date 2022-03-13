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
void desenhar1x1();

//VARIAVEIS
bool d_ataques;
int ataque_do_vilao;

Batalha1x1::Batalha1x1(Inimigo *vilao, Protagonista *player){
    this->_vilao=vilao;
    this->_Player=player;
}

void Batalha1x1::batalhar(){

    ALLEGRO_EVENT ev2; //declarando o evento
    int cont=0;
    while (1)
    {
        desenhar1x1();
        if(_vilao->getNome()=="Billy"){
            al_draw_scaled_bitmap(billy_batalha, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            if(cont%2==0){
                al_draw_scaled_bitmap(ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            }else{
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.79*res_y_comp, 0,"Billy usou o tiro de revólver!");
                 al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.85*res_y_comp, 0,"Aperte ESPAÇO para continuar");
            }

        }
        else if(_vilao->getNome()=="Xerife_Espeto"){
            if(cont%2==0){

            }else{
                
            }
        }
        else if(_vilao->getNome()=="Geraldina"){
            if(cont%2==0){

            }else{
                
            }
        }

        al_wait_for_event(event_queue, &ev2);
    

        al_flip_display();
        if (ev2.type == ALLEGRO_EVENT_KEY_DOWN) {
        keys[ev2.keyboard.keycode] = true;
            if(keys[ALLEGRO_KEY_ESCAPE]) {
                break;
            }  
            switch (ev2.keyboard.keycode)
            {
            case ALLEGRO_KEY_SPACE:
                cont++;
                break;

            }// fim do switch
        }
    }//fim do while
 
}

void Batalha1x1::desenhar1x1(){
    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_scaled_bitmap(player_batalha, 0, 0, 1920, 1080, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar, 0, 0, 800, 100, RES_WIDTH(63*CELULA), RES_HEIGHT(29.5*CELULA), RES_WIDTH(1230*((double)_vilao->getVida()/_vilao->getMaxVida())), RES_HEIGHT(73), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar, 0, 0, 322, 100, RES_WIDTH(17*CELULA), RES_HEIGHT(9*CELULA), RES_WIDTH(322*((double)_Player->getVida()/_Player->getMaxVida())), RES_HEIGHT(73), 0);
}



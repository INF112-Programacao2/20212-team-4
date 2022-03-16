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

ALLEGRO_EVENT evfadebatalha;

//FUNCOES


//VARIAVEIS
bool desenha_ataques=true;
std::string nome_ataque;
int ataque_do_vilao;

Batalha1x1::Batalha1x1(Inimigo *vilao, Protagonista *player){
    this->_vilao=vilao;
    this->_Player=player;
}

void batalha_intro(Protagonista *Player, Inimigo* vilao){
    timer = al_create_timer(0.4);
    short int PLAYER_X = 27;
    short int INIMIGO_X = -27;

    while (PLAYER_X > 0){
        al_wait_for_event(event_queue, &evfadebatalha);

        if(evfadebatalha.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgb(238,202,169));
            al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_scaled_bitmap(lifebar, 0, 0, 800, 100, RES_WIDTH(63*CELULA), RES_HEIGHT(29.5*CELULA), RES_WIDTH(1230*((double)vilao->getVida()/vilao->getMaxVida())), RES_HEIGHT(73), 0);
            al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_scaled_bitmap(lifebar, 0, 0, 322, 100, RES_WIDTH(17*CELULA), RES_HEIGHT(9*CELULA), RES_WIDTH(322*((double)Player->getVida()/Player->getMaxVida())), RES_HEIGHT(73), 0);

            if(vilao->getNome() == "Billy")
                al_draw_scaled_bitmap(billy_batalha, 0, 0, 1920, 1080, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(vilao->getNome() == "Xerife Espeto")
                al_draw_scaled_bitmap(espeto_batalha, 0, 0, 1920, 1080, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(vilao->getNome() == "Geraldina")
                al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 1920, 1080, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(vilao->getNome() == "Jose do caixao")
                al_draw_scaled_bitmap(jose_batalha, 0, 0, 1920, 1080, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_scaled_bitmap(player_batalha,  0, 0, 1920, 1080, RES_WIDTH(PLAYER_X*CELULA), 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            PLAYER_X -= 3;
            INIMIGO_X += 3;
        }
        al_flip_display();
    }

    timer = al_create_timer(1.0/FPS);
}

bool Batalha1x1::batalhar(){

    ALLEGRO_EVENT ev2; //declarando o evento
    bool atacou=false;
    bool vilao_atacou=false;
    int cont=0;
    short int aux_ataque = 0;

    batalha_intro(this -> _Player, this -> _vilao);
    while (1){
        if(!_Player -> isDead() && !_vilao -> isDead()){
            desenhar(_Player, _vilao);

            if(_vilao->getNome() == "Billy")
                al_draw_scaled_bitmap(billy_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome()=="Xerife Espeto")
                al_draw_scaled_bitmap(espeto_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome()=="Geraldina")
                al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            if(cont % 2 == 0 && !atacou){
                desenha_ataques=true;
            }
            
            else if(atacou){
                std::string mensagem = "Você usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.79*res_y_comp, 0, mensagem.c_str());
                
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(605), 0.85*res_y_comp, 0,"Aperte ESPAÇO para continuar");

            }

            else if(cont % 2 != 0){
                if(!vilao_atacou){
                    nome_ataque = _vilao->atacar(*_Player);
                    vilao_atacou=true;
                }
                std::string mensagem = _vilao->getNome() + " usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.79*res_y_comp, 0, mensagem.c_str());

                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(605), 0.85*res_y_comp, 0,"Aperte ESPAÇO para continuar");
            }
        }

        else if(_Player -> isDead()){
            telaGameOver(reiniciar);
            _Player->setVida(_Player->getMaxVida());

            return false;
        }

        else if(_vilao -> isDead()){

            return true;
        }

        al_flip_display();



        // ATAQUE DO PLAYER
        al_wait_for_event(event_queue, &ev2);
        if (ev2.type == ALLEGRO_EVENT_KEY_DOWN) {
            keys[ev2.keyboard.keycode] = true;
            if(keys[ALLEGRO_KEY_ESCAPE]) {
                break;
            }

            switch (ev2.keyboard.keycode){
                case ALLEGRO_KEY_A:
                    if(cont%2==0 && _Player->getNivel()>=1){
                        atacou=true;
                        desenha_ataques=false;
                        aux_ataque=1;
                        nome_ataque = "Tiro de Revólver";
                        //_Player->atacar<Inimigo>(_vilao, "Revólver");    
                    }
                    break;
                case ALLEGRO_KEY_S:
                    if(cont%2==0 && _Player->getNivel()>=2){
                        atacou=true;
                        desenha_ataques=false;
                        aux_ataque=2;
                        nome_ataque = "Coquetel Molotov";
                        //_Player->atacar<Inimigo>(_vilao, "Coquetel Molotov");    
                    }
                    break;
                case ALLEGRO_KEY_D:
                    if(cont%2==0 && _Player->getNivel()>=3){
                        atacou=true;
                        desenha_ataques=false;
                        aux_ataque=3;
                        nome_ataque = "Shurikens";
                        //_Player->atacar<Inimigo>(_vilao, "Shurikens");    
                    }
                    break;
                case ALLEGRO_KEY_C:
                    if(cont%2==0 && _Player->qtdItem("Comida") > 0 && _Player->getVida() < _Player->getMaxVida() ){
                        atacou=true;
                        desenha_ataques=false;
                        nome_ataque = "Cura";
                        _Player-> curarVida(5);
                        _Player->addItem("Comida", -1);
                        aux_ataque=5;
                    }
                    break;    

                case ALLEGRO_KEY_SPACE:
                    atacou=false;
                    desenha_ataques=false;
                    cont++;
                    vilao_atacou=false;
                    break;

            } // fim do switch
        }
    } //fim do while
    keys[ALLEGRO_KEY_E]=false;
    keys[ALLEGRO_KEY_A]=false;
    keys[ALLEGRO_KEY_W]=false;
    keys[ALLEGRO_KEY_S]=false;
    keys[ALLEGRO_KEY_D]=false;

    return false;
}

void desenhar(Protagonista *_Player, Inimigo *_vilao){
    //desenhando as imagens comuns a todos as batalhas 1x1
    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar, 0, 0, 800, 100, RES_WIDTH(63*CELULA), RES_HEIGHT(29.5*CELULA), RES_WIDTH(1230*((double)_vilao->getVida()/_vilao->getMaxVida())), RES_HEIGHT(73), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar, 0, 0, 322, 100, RES_WIDTH(17*CELULA), RES_HEIGHT(9*CELULA), RES_WIDTH(322*((double)_Player->getVida()/_Player->getMaxVida())), RES_HEIGHT(73), 0);

    if(desenha_ataques){
        al_draw_scaled_bitmap(ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1605), 0.80*res_y_comp, 0,"Cura");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1575), 0.87*res_y_comp, 0,"C: +5 P.V.");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.80*res_y_comp, 0,"Revólver");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.87*res_y_comp, 0,"A: (02/08)");

        if(_Player->getNivel()<2){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(540), 0.80*res_y_comp, 0,"???????");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(540), 0.80*res_y_comp, 0,"Molotov");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(535), 0.87*res_y_comp, 0,"S: (10/15)");
        }

        if(_Player->getNivel()<3){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"?????????");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"Shurikens");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(875), 0.87*res_y_comp, 0,"D: (03/05)");
        }

        if(_Player->getNivel()<4){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1180), 0.80*res_y_comp, 0,"??????????");       
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1180), 0.80*res_y_comp, 0,"Pé de Coelho");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1215), 0.87*res_y_comp, 0,"F: (sorte)");
        }
    }

}




/*bool VerificaTeclaBatalha(){
    if(ev3.type == ALLEGRO_EVENT_KEY_DOWN){
        keys[ev3.keyboard.keycode] = true;

        if(Batalha1x1.batalhar() && keys[ALLEGRO_KEY_1]){
           
            keys[ev3.keyboard.keycode] = false;

            return true;
        }
    }

    return false;


}*/

// al_draw_scaled_bitmap(billy_dano, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*     (res_y_comp/1080.0), 0);
//                 al_flip_display();
//                 al_rest(0.2);
//                 desenhar(_Player, _vilao);
//                 al_rest(0.2);
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

#define PROP_PLAYER ((double) _Player->getVida() / _Player->getMaxVida())
#define PROP_ENEMY ((double) _vilao->getVida() / _vilao->getMaxVida())

ALLEGRO_EVENT evfadebatalha;

//VARIAVEIS
bool desenha_ataques=true;
bool player_atacou=false; //variavel que diz se o player fez o ataque ou não ***
bool vilao_atacou=false; //variavel que diz se o vilao fez o ataque ou nao ***
short int a=0, b=0, c=0, d=0; //auxiliares para desenhar a tela dos persoganes levando dano nas batalhas
std::string mensagem;
std::string nome_ataque;
short int aux_ataque = 0;
int cont;
int ataque_do_vilao;
ALLEGRO_EVENT ev2; //declarando o evento
ALLEGRO_BITMAP *img_vilao= NULL;
ALLEGRO_BITMAP *img_vilao_dano= NULL;

void al_init_timeout(ALLEGRO_TIMEOUT *timeout, double seconds);

Batalha1x1::Batalha1x1(Inimigo *vilao, Protagonista *player){
    this->_vilao=vilao;
    this->_Player=player;
}

void batalha_intro(Protagonista *_Player, Inimigo* _vilao){
    timer = al_create_timer(0.4);
    short int PLAYER_X = 27;
    short int INIMIGO_X = -27;

    while (PLAYER_X > 0){
        al_wait_for_event(event_queue, &evfadebatalha);

        if(evfadebatalha.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgb(238,202,169));

            al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);    
            al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0);      
            al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
            al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
            al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            if(_vilao->getNome() == "Billy")
                al_draw_scaled_bitmap(billy_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Xerife Espeto")
                al_draw_scaled_bitmap(espeto_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Geraldina")
                al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Jose do caixao")
                al_draw_scaled_bitmap(jose_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_scaled_bitmap(player_batalha, 0, 0, 120, 68,  RES_WIDTH(PLAYER_X*CELULA), 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            PLAYER_X -= 3;
            INIMIGO_X += 3;
        }
        al_flip_display();
    }

    timer = al_create_timer(1.0/FPS);
}

void batalha_fim(Protagonista *_Player, Inimigo* _vilao){
    timer = al_create_timer(0.4);
    int alfa = 130;

    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);    
    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    al_rest(0.02); 

    if(_vilao->getNome() == "Billy")
        al_draw_scaled_bitmap(billy_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "Xerife Espeto")
        al_draw_scaled_bitmap(espeto_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "Geraldina")
        al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "Jose do caixao")
        al_draw_scaled_bitmap(jose_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.82*res_y_comp, 0, "Você venceu!");
    al_flip_display();

    al_rest(3);

    while (alfa <= 255){
        al_wait_for_event(event_queue, &evfadebatalha);

        if(evfadebatalha.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgba(238, 202, 169, 255-alfa));
            
            al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);    
            al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
            al_draw_tinted_scaled_bitmap(lifebar_batalhas, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
            al_draw_tinted_scaled_bitmap(lifebar_batalhas, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
            al_draw_tinted_scaled_bitmap(vida_vilao, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_tinted_scaled_bitmap(vida_player, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            if(_vilao->getNome() == "Billy")
                al_draw_tinted_scaled_bitmap(billy_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Xerife Espeto")
                al_draw_tinted_scaled_bitmap(espeto_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Geraldina")
                al_draw_tinted_scaled_bitmap(geraldina_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Jose do caixao")
                al_draw_tinted_scaled_bitmap(jose_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_tinted_scaled_bitmap(player_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 120, 68,  0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_tinted_scaled_bitmap(caixa_de_ataques, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            alfa += 15;
        }

        al_flip_display();
    }

    timer = al_create_timer(1.0/FPS);
}

bool Batalha1x1::batalhar(){
    resetTeclas();
    cont=0;

    batalha_intro(this -> _Player, this -> _vilao);

    if(_vilao->getNome() == "Billy"){
        img_vilao=billy_batalha;
        img_vilao_dano=billy_dano;
    }
    else if(_vilao->getNome()=="Xerife Espeto"){
        img_vilao=espeto_batalha;
        img_vilao_dano=espeto_dano;
    }
    else if(_vilao->getNome()=="Geraldina"){
        img_vilao=geraldina_batalha;
        img_vilao_dano=geraldina_dano;
    }

    while (1){
        desenhar(_Player, _vilao);
        if(!_Player -> isDead() && !_vilao -> isDead()){

            //desenhar(_Player, _vilao);                

            if(cont % 2 == 0 && !player_atacou){
                desenha_ataques=true;
                c=0;
                d=0;
            }
            
            else if(player_atacou && c < 20){

                mensagem = "Você usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.82*res_y_comp, 0, mensagem.c_str());
                if(c==19){
                    player_atacou=false;
                    desenha_ataques=false;
                    cont++;
                    vilao_atacou=false;
                }
                c++;
                

            }

            else if(cont % 2 != 0 && d < 20){
                if(!vilao_atacou){
                    nome_ataque = _vilao->atacar(*_Player);
                    vilao_atacou=true;
                }
                mensagem = _vilao->getNome() + " usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.82*res_y_comp, 0, mensagem.c_str());
               if(d==19){
                    player_atacou=false;
                    desenha_ataques=false;
                    cont++;
                    vilao_atacou=false;
                }
                d++;
                

            }
        }

        else if(_Player -> isDead()){
            telaGameOver(reiniciar);
            _Player->setVida(_Player->getMaxVida());

            return false;
        }

        else if(_vilao -> isDead()){
            resetTeclas();
            batalha_fim(_Player, _vilao);
            return true;
        }
       
        al_flip_display();

        al_wait_for_event(event_queue, &ev2);

        if(!verificaTeclaBatalha(_Player, _vilao)) break;

    } //fim do while

    return false;
}

void desenhar(Protagonista *_Player, Inimigo *_vilao){
    //desenhando as imagens comuns a todos as batalhas
    al_clear_to_color(al_map_rgb(238,202,169));
    
    if(vilao_atacou && nome_ataque!="Cura"){
        al_rest(0.02); 
        if(a==0){
            al_draw_scaled_bitmap(player_dano, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            a++;
        }
        else if(a==1){
            al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0); 
            a=0;
        }
        al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }
    else if(player_atacou && aux_ataque!=5){
        al_rest(0.02); 
        if(b==0){
            al_draw_scaled_bitmap(img_vilao_dano, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            b++;
        }
        else if(b==1){
            al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            b=0;
        }
        al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0); 
    }
    else{
        al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }

    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);    
    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    
    if(desenha_ataques){
        al_draw_scaled_bitmap(ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.80*res_y_comp, 0,"Revólver");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.88*res_y_comp, 0, dano_revolver.c_str());

        if(_Player->qtdItem("Comida")==0){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1558), 0.80*res_y_comp, 0,"Esgotado!");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1605), 0.80*res_y_comp, 0,"Cura");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1575), 0.88*res_y_comp, 0,"C: +5 P.V.");
        }

        if(_Player->getNivel()<2){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(518), 0.80*res_y_comp, 0,"???????");
        }
        else if(!_Player->hasAtaque("Coquetel Molotov")){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(518), 0.80*res_y_comp, 0,"Esgotado!");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(540), 0.80*res_y_comp, 0,"Molotov");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(535), 0.88*res_y_comp, 0,"S: (10/15)");
        }

        if(_Player->getNivel()<3){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"???????");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"Shurikens");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(875), 0.88*res_y_comp, 0,"D: (03/05)");
        }

        if(_Player->getNivel()<4){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1210), 0.80*res_y_comp, 0,"???????");       
        }
        else if(!_Player->hasAtaque("Pé de Coelho")){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1210), 0.80*res_y_comp, 0,"Esgotado!"); 
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1180), 0.80*res_y_comp, 0,"Pé de Coelho");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1215), 0.88*res_y_comp, 0,"F: (sorte)");
        }
    }

}

bool verificaTeclaBatalha(Protagonista *_Player, Inimigo *_vilao){
    if (ev2.type == ALLEGRO_EVENT_KEY_DOWN) {
        keys[ev2.keyboard.keycode] = true;
        if(keys[ALLEGRO_KEY_ESCAPE]) {
            return false;
        }

        switch (ev2.keyboard.keycode){
            case ALLEGRO_KEY_A:
                if(cont%2==0 && _Player->getNivel()>=1){
                    player_atacou=true;
                    desenha_ataques=false;
                    aux_ataque=1;
                    nome_ataque = "Tiro de Revólver";
                    _Player->atacar<Inimigo>(_vilao, "Revólver");    
                }
                break;
            case ALLEGRO_KEY_S:
                if(cont%2==0 && _Player->getNivel()>=2 && _Player->hasAtaque("Coquetel Molotov")){
                    player_atacou=true;
                    desenha_ataques=false;
                    aux_ataque=2;
                    nome_ataque = "Coquetel Molotov";
                    _Player->atacar<Inimigo>(_vilao, "Coquetel Molotov");    
                }
                break;
            case ALLEGRO_KEY_D:
                if(cont%2==0 && _Player->getNivel()>=3){
                    player_atacou=true;
                    desenha_ataques=false;
                    aux_ataque=3;
                    nome_ataque = "Shurikens";
                    _Player->atacar<Inimigo>(_vilao, "Shurikens");    
                }
                break;
            case ALLEGRO_KEY_F:
                if(cont%2==0 && _Player->getNivel()>=4 && _Player->hasAtaque("Pé de Coelho")){
                    player_atacou=true;
                    desenha_ataques=false;
                    aux_ataque=4;
                    nome_ataque = "Pé de Coelho";
                    _Player->atacar<Inimigo>(_vilao, "Pé de Coelho");    
                }
                break;
            case ALLEGRO_KEY_C:
                if(cont % 2 == 0 && _Player->qtdItem("Comida") > 0 && _Player->getVida() < _Player->getMaxVida() ){
                    player_atacou=true;
                    desenha_ataques=false;
                    nome_ataque = "Cura";
                    _Player-> curarVida(5);
                    _Player->addItem("Comida", -1);
                    aux_ataque=5;
                }
                break;    

           
        } // fim do switch

        keys[ev2.keyboard.keycode] = false;
    }
    return true;
}

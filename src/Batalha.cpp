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
bool caixao_batalhando=false;
bool caixao_morreu=false;
bool missao_bruxa=false;
bool desenha_ataques=true;
bool player_atacou=false; //variavel que diz se o player fez o ataque ou não ***
bool vilao_atacou=false; //variavel que diz se o vilao fez o ataque ou nao ***
bool tocou = false;
short int a=0, b=0, c=0, d=0, e=0, f=0; //auxiliares para desenhar a tela dos persoganes levando dano nas batalhas
std::string mensagem="";
std::string nome_ataque="";
std::string nome_player="";
std::string nome_vilao="";
std::string qtd_comida="";
short int aux_ataque = 0;
short int desafinacao=1;
int cont;
int ataque_do_vilao;
ALLEGRO_EVENT ev2; //declarando o evento

void al_init_timeout(ALLEGRO_TIMEOUT *timeout, double seconds);

Batalha1x1::Batalha1x1(Inimigo *vilao, Protagonista *player){
    this->_vilao=vilao;
    this->_Player=player;
}

Batalha1x2::Batalha1x2(Inimigo *vilao, Inimigo *caixao, Protagonista *player){
    this->_vilao=vilao;
    this->_jose=vilao;
    this->_Player=player;
    this->_caixao=caixao;
}

BatalhaFantasma::BatalhaFantasma(Inimigo *vilao, Protagonista *player, MissaoSecundaria *bruxa){
    this->_vilao=vilao;
    this->_Player=player;
    this->_Bruxa=bruxa;
}


void dialogo_Geraldina(Protagonista *_Player){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-geraldina.bmp");
    std::string *falas = new std::string[9] {
        "1Onde tá o seu líder? Eu já perdi a paciência com o grupo de vocês.",
        "2Eu não sei.",
        "1Fala logo, lobinha. Eu não quero precisar duelar com você de novo.",
        "2Eu não sei!",
        "1Alguma coisa eu sei que você sabe.",
        "2O máximo que eu sei é que você pode ter mais informações com o coveiro.",
        "1Qual o nome do coveiro?",
        "2José...",
        "2*José do caixão."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar_batalha("Geraldina", opcoes, 3, _Player);
}

void dialogo_Jose(Protagonista *_Player){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (2, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"JOHNNY? (Z)", "ONDE? (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 9};


    icone = al_load_bitmap("./../assets/icone-coveiro.bmp");
    std::string *falas = new std::string[15] {
        "1A coiote disse que você sabe quem começou isso tudo aqui.",
        "1É o fim da linha, parceiro. Quem é o líder disso tudo?",
        "2O nome dele é Johnny.",
        "1Quem diabos é Johnny?"
        "2Cash...",
        "1Não, pera, o cantor?",
        "2Sua alma estava há dias me assombrando, dizendo que queria voltar para este mundo.",
        "1E por que permitiu isso? Sua gangue aterrorizou toda a cidade, matou pessoas!",
        "2O meu caixãozinho... Ele estava tão triste... Há tempos não enterrava ninguém!",
        "1...",
        "2Eu fiz isso por ele! Só por ele...",
        "1E onde ele está?",
        "2Na cabana mal assombrada da floresta... Ele comandou isso tudo por lá.",
        "2Mas antes de ir... Tome isso... São munições especiais, contra fantasmas.",
        "1*Obrigado, José"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar_batalha("José do Caixão", opcoes, 4, _Player);
}

void resetBatalha(Inimigo *vilao, Inimigo *vilao2){
    caixao_batalhando=false;
    caixao_morreu=false;
    missao_bruxa=false;
    desenha_ataques=true;
    player_atacou=false; //variavel que diz se o player fez o ataque ou não ***
    vilao_atacou=false; //variavel que diz se o vilao fez o ataque ou nao ***
    tocou = false;
    a= b = c = d = e = f = 0; //auxiliares para desenhar a tela dos persoganes levando dano nas batalhas
    mensagem="";
    nome_ataque="";
    nome_player="";
    nome_vilao="";
    qtd_comida="";
    aux_ataque = 0;
    desafinacao=1;
    cont = 0;
    ataque_do_vilao;


    if(vilao->getNome() == "Billy"){
        vilao->_total_ataques = 2;
        vilao->_total_curas = 3;
        vilao->_curas_usadas = 0;
        vilao->setVida(21);
        vilao->addAtaque("Tiro de Revólver", 0, -2);
        vilao->addAtaque("Cura", 0, 1);
    }

    else if(vilao->getNome() == "Xerife Espeto"){
        vilao->_curas_usadas = 0;
        vilao->_total_ataques = 3;
        vilao->_total_curas = 3;
        vilao->setVida(40);
        vilao->addAtaque("Tiro de Revólver", 0, -4);
        vilao->addAtaque("Espinhos", 0, -3);
        vilao->addAtaque("Cura", 0, 2);
    }

    else if(vilao->getNome() == "Geraldina"){
        vilao->_curas_usadas = 0;
        vilao->_total_ataques = 3;
        vilao->_total_curas = 3;
        vilao->setVida(58);
        vilao->addAtaque("Garras", 0, -7);
        vilao->addAtaque("Mordida", 0, -2);
        vilao->addAtaque("Cura", 0, 3);
    }

    else if(vilao->getNome() == "José do Caixão"){
        vilao->_curas_usadas = 0;
        vilao->_total_ataques = 3;
        vilao->_total_curas = 3;
        vilao->setVida(80);
        vilao->addAtaque("Tiro de Revólver", 0, -5);
        vilao->addAtaque("Pá", 0, -1);
        vilao->addAtaque("Cura", 0, 3);

        vilao->_total_ataques = 3;
        vilao->_total_curas = 3;
        vilao2->setVida(60);
        vilao2->addAtaque("Mordida Fúnebre", 0, -3);
        vilao2->addAtaque("Pá", 0, -1);
        vilao2->addAtaque("Cura", 0, 60);
    }

    else if(vilao->getNome() == "Johnny Cash"){
        vilao->_curas_usadas = 0;
        vilao->_total_ataques = 4;
        vilao->_total_curas = 3;
        vilao->setVida(75);
        vilao->addAtaque("Assombração", 0, -15);
        vilao->addAtaque("Desafinação", 0, -3);
        vilao->addAtaque("Tiro espectral", 0, -4);
        vilao->addAtaque("Cura", 0, 5);
    }
}


void batalha_intro(Protagonista *_Player, Inimigo* _vilao){
    timer = al_create_timer(0.4);
    short int PLAYER_X = 27;
    short int INIMIGO_X = -27;

    while (PLAYER_X > 0){
        al_wait_for_event(event_queue, &evfadebatalha);

        if(evfadebatalha.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgb(238,202,169));

            
            if(_vilao->getNome() == "Billy")
                al_draw_scaled_bitmap(billy_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Xerife Espeto")
                al_draw_scaled_bitmap(espeto_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "Geraldina")
                al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            else if(_vilao->getNome() == "José do Caixão")
                al_draw_scaled_bitmap(jose_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            
            else if(_vilao->getNome() == "Johnny Cash"){ 
                al_draw_scaled_bitmap(base_fantasma, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
                al_draw_scaled_bitmap(fantasma_batalha, 0, 0, 240, 135, RES_WIDTH(INIMIGO_X*CELULA), 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
               
                }
              
            al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
            if(_vilao->getNome() != "Johnny Cash") {
                al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);      
                al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
                al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            }
            al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
            al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

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

    if(_vilao->getNome() != "Johnny Cash"){
        al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0); 
        al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0); 
        al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
    }  

    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    al_rest(0.02); 

    if(_vilao->getNome() == "Billy")
        al_draw_scaled_bitmap(billy_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "Xerife Espeto")
        al_draw_scaled_bitmap(espeto_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "Geraldina")
        al_draw_scaled_bitmap(geraldina_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    else if(_vilao->getNome() == "José do Caixão")
        al_draw_scaled_bitmap(jose_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    
    else if(_vilao->getNome() == "Johnny Cash")
        al_draw_scaled_bitmap(fantasma_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    
    al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

    al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(800), 0.82*res_y_comp, 0, "Você venceu!");
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

            else if(_vilao->getNome() == "José do Caixão")
                al_draw_tinted_scaled_bitmap(jose_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            
            else if(_vilao->getNome() == "Johnny Cash")
                al_draw_tinted_scaled_bitmap(fantasma_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            
            al_draw_tinted_scaled_bitmap(player_batalha, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 120, 68,  0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_tinted_scaled_bitmap(caixa_de_ataques, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            alfa += 15;
        }

        al_flip_display();
    }

    timer = al_create_timer(1.0/FPS);
}

bool Batalha1x1::batalhar(){
    this->_Player->_batalhando = true;
    resetTeclas();
    cont=0;
    player_atacou = false;

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
        
        if(!_Player -> isDead() && !_vilao -> isDead()){

            desenhar(_Player, _vilao);                

            if(cont % 2 == 0 && !player_atacou){
                desenha_ataques=true;
                c=0;
                d=0;
            }
            
            else if(player_atacou && c<20){

                mensagem = "Você usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
                if(c==19){
                    player_atacou=false;
                    cont++;
                    vilao_atacou=false;
                }
                c++;          
            }

            else if(cont % 2 != 0 && d<20){
                if(!vilao_atacou){
                    nome_ataque = _vilao->atacar(*_Player);
                    vilao_atacou=true;
                }
                mensagem = _vilao->getNome() + " usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
               if(d==19){
                    player_atacou=false;
                    cont++;
                    vilao_atacou=false;
                }
                d++;                
            }
        }

        else if(_Player -> isDead()){
            this->_Player->_batalhando = false;
            resetBatalha(_vilao, _vilao);

            return false;
        }

        else if(_vilao -> isDead()){
            this->_Player->_batalhando = false;
            resetTeclas();
            if(_vilao->getNome() == "Geraldina") dialogo_Geraldina(this->_Player);
            else batalha_fim(_Player, _vilao);
            return true;
        }
       
        al_flip_display();

        al_wait_for_event(event_queue, &ev2);

        if(!verificaTeclaBatalha(_Player, _vilao)) break;

    } //fim do while

    return false;
}

bool Batalha1x2 :: batalhar(){
    this->_Player->_batalhando = true;
     batalha_intro(this -> _Player, this -> _vilao);
     img_vilao=jose_batalha;
     img_vilao_dano=jose_dano;

     player_atacou = false;
     cont = 0;
    
     resetTeclas();

    
    while (1){
        if(!_Player -> isDead() && !_vilao -> isDead()){

            desenhar(_Player, _vilao);                

            if(cont % 2 == 0 && !player_atacou){
                desenha_ataques=true;
                c=0;
                d=0;
            }
            
            else if(player_atacou && c<20){
                if(caixao_batalhando){
                    mensagem ="José do Caixão invocou o Caixão do José!";
                    al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(580), 0.82*res_y_comp, 0, mensagem.c_str());
                }
                else if(caixao_morreu){
                    mensagem ="Você derrotou o Caixão do José!";
                    al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(550), 0.82*res_y_comp, 0, mensagem.c_str());
                }
                else{
                    mensagem = "Você usou " + nome_ataque + "!";
                    al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
                }
                if(c==19){
                    player_atacou=false;
                    caixao_batalhando=false;
                    caixao_morreu=false;
                    cont++;
                    vilao_atacou=false;
                }
                c++;          
            }
            else if(cont % 2 != 0 && d<20){
                if(!vilao_atacou){
                    nome_ataque = _vilao->atacar(*_Player);
                    vilao_atacou=true;
                }
                mensagem = _vilao->getNome() + " usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
               if(d==19){
                    player_atacou=false;
                    cont++;
                    vilao_atacou=false;
                }
                d++;                
            }
           
        }

        else if(_Player -> isDead()){
            this->_Player->_batalhando = false;
            resetBatalha(_jose, _caixao);
            return false;
        }

        else if(_caixao -> isDead() && _jose->isDead()){
            this->_Player->_batalhando = false;
            resetTeclas();
            dialogo_Jose(this->_Player);
            return true;
        }
       
        al_flip_display();

        if(_jose->getVida()<=_jose->getMaxVida()/2 && !_caixao->isDead()){
            if(e==0){
                caixao_batalhando=true;
                e++;
            }
            _vilao = _caixao;
            img_vilao = caixao_batalha;
            img_vilao_dano = caixao_dano;
        }

        else{
            if(f==0 && _caixao->isDead()){
                caixao_morreu=true;
                f++;
            }
            _vilao = _jose;
            img_vilao = jose_batalha;
            img_vilao_dano = jose_dano;
         }

        al_wait_for_event(event_queue, &ev2);

        if(!verificaTeclaBatalha(_Player, _vilao)) break;

    } //fim do while

    return false;
    
}


bool BatalhaFantasma::batalhar(){
    batalha_intro(this -> _Player, this -> _vilao);
    player_atacou = false;
    cont = 0;
    img_vilao=fantasma_batalha;
    img_vilao_dano=fantasma_batalha;
    if(_Bruxa->completo()){
        missao_bruxa=true;
    }
    
    resetTeclas();

    while (1){
        
        if(!_Player -> isDead() && !_vilao -> isDead()){

            desenhar(_Player, _vilao);    

            if(nome_ataque=="Assombração" && cont % 2 == 0){
                cont++;
                d=0;
                _vilao->subAtaque("Assombração");
                _vilao->_total_ataques--;
            }

            if(nome_ataque=="Desafinação" && !tocou){
                if(desafinacao==1){
                    al_play_sample(desafinacao1, 0.8, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    desafinacao++;
                }
                else if(desafinacao==2){
                    al_play_sample(desafinacao2, 0.8, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    desafinacao++;
                }
                else if (desafinacao==3){
                    al_play_sample(desafinacao3, 0.8, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    desafinacao=1;
                }

                tocou = true;
            }  

            if(cont % 2 == 0 && !player_atacou && nome_ataque!="Assombração"){
                desenha_ataques=true;
                c=0;
                d=0;
            }
            
            else if(player_atacou && c<20){
                tocou = false;
                mensagem = "Você usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
                if(c==19){
                    player_atacou=false;
                    cont++;
                    vilao_atacou=false;
                }
                c++;          
            }

            else if(cont % 2 != 0 && d<20){
                if(!vilao_atacou){
                    nome_ataque = _vilao->atacar(*_Player);
                    vilao_atacou=true;
                }
                if(nome_ataque == "Assombração") mensagem = "Johnny Cash usou Assombração! Você perdeu um turno!";
                else mensagem = _vilao->getNome() + " usou " + nome_ataque + "!";
                al_draw_textf(font15, al_map_rgb(58,15,43), (al_get_display_width(game)/2)-18*(mensagem.size()/2), 0.82*res_y_comp, 0, mensagem.c_str());
                if(d==19){
                    player_atacou=false;
                    cont++;
                    vilao_atacou=false;
                }
                d++;                
            }
        }

        else if(_Player -> isDead()){
            resetBatalha(_vilao, _vilao);
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
    //desenhando as imagens comuns a todas as batalhas
    al_clear_to_color(al_map_rgb(238,202,169));
    if(_vilao->getNome()=="Caixão do José"){
        al_draw_scaled_bitmap(jose_batalha, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }
    else if(_vilao->getNome()=="Johnny Cash"){
        al_draw_scaled_bitmap(base_fantasma, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }

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
        if(_vilao->getNome()=="Johnny Cash") al_draw_tinted_scaled_bitmap(img_vilao, al_map_rgba(255, 255, 255, 255 * PROP_ENEMY), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        else al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }
    else if(player_atacou && aux_ataque != 5 && aux_ataque != 4){
        al_rest(0.02); 
        if(b==0){
            al_draw_scaled_bitmap(img_vilao_dano, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            b++;
        }
        else if(b==1){
            if(_vilao->getNome()=="Johnny Cash") al_draw_tinted_scaled_bitmap(img_vilao, al_map_rgba(255, 255, 255, 255 * PROP_ENEMY), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            else al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            b=0;
        }
        al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0); 
    }
    else{
        al_draw_scaled_bitmap(player_batalha, 0, 0, 129, 68, 0, 0,  1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        if(_vilao->getNome()=="Johnny Cash") al_draw_tinted_scaled_bitmap(img_vilao, al_map_rgba(255, 255, 255, 255 * PROP_ENEMY), 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        else al_draw_scaled_bitmap(img_vilao, 0, 0, 240, 135, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    }

       
    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(600), RES_HEIGHT(80), 0); 
    al_draw_scaled_bitmap(caixa_de_ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    if(_vilao->getNome() != "Johnny Cash"){
        al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(1016), RES_HEIGHT(468), RES_WIDTH(610), RES_HEIGHT(60), 0);
        al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(1025), RES_HEIGHT(468), RES_WIDTH(590) * PROP_ENEMY, RES_HEIGHT(48), 0);
        al_draw_scaled_bitmap(vida_vilao, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1045), 0.47*res_y_comp, 0,nome_vilao.c_str());
    }
    al_draw_scaled_bitmap(lifebar_batalhas, 0, 0, 586, 49, RES_WIDTH(262), RES_HEIGHT(146), RES_WIDTH(577) * PROP_PLAYER, RES_HEIGHT(80), 0);
    al_draw_scaled_bitmap(vida_player, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
    nome_player=_Player->getNome();
    nome_vilao=_vilao->getNome();
    al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(280), 0.11*res_y_comp, 0,nome_player.c_str());
    al_draw_scaled_bitmap(frango, 0, 0, 16, 16, RES_WIDTH(47*CELULA), RES_HEIGHT(115), RES_WIDTH(12*ZOOM), RES_HEIGHT(12*ZOOM), 0);
    al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(810), 0.11*res_y_comp, 0,"%d", _Player->qtdItem("Comida"));;

    if(desenha_ataques){
        al_draw_scaled_bitmap(ataques, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.88*res_y_comp, 0, dano_revolver.c_str());
        if(_Player->getNivel() == 5){
            al_draw_textf(fontataques, al_map_rgb(58,15,43), RES_WIDTH(140), 0.81*res_y_comp, 0,"Munições Fantasma");
        }
        else{    
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(180), 0.80*res_y_comp, 0,"Revólver");
        }

        if(_Player->qtdItem("Comida")==0){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1558), 0.80*res_y_comp, 0,"Esgotado!");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1605), 0.80*res_y_comp, 0,"Cura");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1575), 0.88*res_y_comp, 0,"C: +5 P.V.");
        }

        if(_Player->getNivel()<2 || (_Player->getNivel()==5 && !missao_bruxa) ){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(518), 0.80*res_y_comp, 0,"???????");
        }
        else if(_Player->getNivel()==5 && missao_bruxa){
            al_draw_textf(fontataques, al_map_rgb(58,15,43), RES_WIDTH(475), 0.81*res_y_comp, 0,"Munições da Bruxa");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(535), 0.88*res_y_comp, 0,"S: (04/06)");
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
        else if(_Player->getNivel()==5){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"-----------");
        }
        else{
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(865), 0.80*res_y_comp, 0,"Shurikens");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(875), 0.88*res_y_comp, 0,"D: (03/04)");
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

        if(!player_atacou){
            switch (ev2.keyboard.keycode){
                case ALLEGRO_KEY_A:
                    if(cont%2==0 && _Player->getNivel()>=1 && _Player->getNivel()!=5){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=1;
                        nome_ataque = "Tiro de Revólver";
                        _Player->atacar<Inimigo>(_vilao, "Revólver");    
                    }
                    else if(cont%2==0 && _Player->getNivel()>=1 && _Player->getNivel()==5){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=6;
                        nome_ataque = "Munições Fanstasma";
                        _Player->atacar<Inimigo>(_vilao, "Munições Fanstasma");  
                    }
                    break;
                case ALLEGRO_KEY_S:
                    if(cont%2==0 && _Player->getNivel()>=2 && _Player->hasAtaque("Coquetel Molotov") && _Player->getNivel()!=5){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=2;
                        nome_ataque = "Coquetel Molotov";
                        _Player->atacar<Inimigo>(_vilao, "Coquetel Molotov");    
                    }
                    else if(cont%2==0 && _Player->getNivel()>=2  && _Player->getNivel()==5 && missao_bruxa){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=7;
                        nome_ataque = "Munições da Bruxa";
                        _Player->atacar<Inimigo>(_vilao, "Munições da Bruxa"); 
                    }
                    break;
                case ALLEGRO_KEY_D:
                    if(cont%2==0 && _Player->getNivel()>=3 && _Player->getNivel()!=5){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=3;
                        nome_ataque = "Shurikens";
                        _Player->atacar<Inimigo>(_vilao, "Shurikens");    
                    }
                    break;
                case ALLEGRO_KEY_F:
                    if(cont%2==0 && _Player->getNivel()>=4 && _Player->hasAtaque("Pé de Coelho") && !player_atacou){
                        player_atacou=true;
                        desenha_ataques=false;
                        aux_ataque=4;
                        nome_ataque = "Pé de Coelho";
                        _Player->atacar<Inimigo>(_vilao, "Pé de Coelho");    
                    }
                    break;
                case ALLEGRO_KEY_C:
                    if(cont % 2 == 0 && _Player->qtdItem("Comida") > 0 && _Player->getVida()<= _Player->getMaxVida() && !player_atacou){
                        player_atacou=true;
                        desenha_ataques=false;
                        nome_ataque = "Cura";
                        _Player-> curarVida(5);
                        _Player->addItem("Comida", -1);
                        aux_ataque=5;
                    }
                    break;    

            
            } // fim do switch
        }

        keys[ev2.keyboard.keycode] = false;
    }
    return true;
}

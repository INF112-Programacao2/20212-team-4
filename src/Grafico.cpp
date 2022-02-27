#include "Grafico.hpp"
#include "data.hpp"

ALLEGRO_EVENT evdialogo;

void redesenhar(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 
        0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);

    if (rel)
        al_draw_scaled_bitmap(relogio, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (chav)
        al_draw_scaled_bitmap(chave, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);

    if (poc)
        al_draw_scaled_bitmap(pocao, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (d1)
        al_draw_scaled_bitmap(dinheiro1, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (d2)
        al_draw_scaled_bitmap(dinheiro2, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (d3)
        al_draw_scaled_bitmap(dinheiro3, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (d4)
        al_draw_scaled_bitmap(dinheiro4, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);

    switch(cont){
        case 0:
            al_draw_scaled_bitmap(galinha1, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            cont++;
            break;
        case 1:
            al_draw_scaled_bitmap(galinha2, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            cont++;
            break;
        case 2:
            al_draw_scaled_bitmap(galinha3, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            cont++;
            break;
        case 3:
            al_draw_scaled_bitmap(galinha4, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            cont = 0;
            break;
    }

    al_draw_scaled_bitmap(fundo, 0, 0, 322, 73, RES_WIDTH(99*CELULA), RES_HEIGHT(15), RES_WIDTH(322), RES_HEIGHT(73), 0);
    al_draw_scaled_bitmap(lifebar, 0, 0, 322, 73, RES_WIDTH(99*CELULA), RES_HEIGHT(15), RES_WIDTH(322*((double)Player->getVida()/Player->getMaxVida())), RES_HEIGHT(73), 0);
    al_draw_scaled_bitmap(contorno, 0, 0, 322, 73, RES_WIDTH(99*CELULA), RES_HEIGHT(15), RES_WIDTH(322), RES_HEIGHT(73), 0);

    al_draw_textf(font15, al_map_rgb(60,25,97), RES_WIDTH(110*CELULA), RES_HEIGHT(105), 0,"$ %d", Player->getDinheiro());

    al_draw_textf(font15, al_map_rgb(60,25,97), RES_WIDTH(105*CELULA), RES_HEIGHT(105), 0,"%d", Player->qtdItem("Comida"));
    al_draw_scaled_bitmap(frango, 0, 0, 16, 16, RES_WIDTH(100*CELULA), RES_HEIGHT(105), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);

    if(Player->qtdItem("Relogio") != 0){
        al_draw_scaled_bitmap(relogiohud, 0, 0, 16, 16, RES_WIDTH(115*CELULA), RES_WIDTH(180), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Chave") != 0){
        al_draw_scaled_bitmap(chavehud, 0, 0, 16, 16, RES_WIDTH(110*CELULA), RES_WIDTH(180), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Espingarda") != 0){
        al_draw_scaled_bitmap(espingarda, 0, 0, 34, 16, RES_WIDTH(101*CELULA), RES_WIDTH(180), RES_WIDTH(34*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Pocao") != 0){
        al_draw_scaled_bitmap(pocaohud, 0, 0, 16, 16, RES_WIDTH(115*CELULA), RES_WIDTH(250), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }

    al_draw_scaled_bitmap(general_player, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
        RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);

    if(botao->interacaoProxima('2') && !Player->_dialogo){//caso haja uma interacao proxima e o personagem não esteja na loja
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(760), 0.85*res_y_comp, 0,"Aperte          para Interagir");
        al_draw_scaled_bitmap(botaointeracao, 0,  0, 18, 18, RES_WIDTH(920), 0.85*res_y_comp, RES_WIDTH(18*ZOOM), RES_HEIGHT(18*ZOOM), 0);
    }    
}

bool Dialogo::verificarTecla(){
    if(evdialogo.type == ALLEGRO_EVENT_KEY_DOWN){
        keys[evdialogo.keyboard.keycode] = true;

        if(this->_fluxo[posicao_atual_dialogo] == false && keys[ALLEGRO_KEY_SPACE]){
            this->posicao_atual_dialogo += this->incremento_dialogoSPACE;
            return true;
        }

        else if(this->_fluxo[posicao_atual_dialogo] == true && keys[ALLEGRO_KEY_X]){
            this->posicao_atual_dialogo += this->incremento_dialogoX;
            this->posicao_atual_incremento++;

            return true;
        }

        else if(this->_fluxo[posicao_atual_dialogo] == true && keys[ALLEGRO_KEY_Z]){
            this->posicao_atual_dialogo += this->incremento_dialogoZ;
            this->posicao_atual_incremento++;

            return true;
        }
    }

    else if (evdialogo.type == ALLEGRO_EVENT_KEY_UP) 
        keys[evdialogo.keyboard.keycode] = false;


    return false;
}

/* DIALOGOS DO JOGO */
Dialogo::Dialogo(std::string *dialogos, bool *fluxo, short int **incrementos){
    this->_dialogos = dialogos;
    this->_fluxo = fluxo;
    this->_fluxo_incremento = incrementos;

    this->posicao_atual_dialogo = 0;
    this->posicao_atual_incremento = 0;
    this->incremento_dialogoX = this->incremento_dialogoZ = this->incremento_dialogoSPACE = 1;
}

Dialogo::Dialogo(){
    this->_fluxo = new bool[3];
    this->_fluxo[0] = true;
    this->_fluxo[1] = false;
    this->_fluxo[2] = false;

    this->posicao_atual_dialogo = 0;
    this->incremento_dialogoZ = this->incremento_dialogoSPACE = 1;
    this->incremento_dialogoX = 2;
}

void ajustarCamera(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    while(true){
        al_wait_for_event(event_queue, &evdialogo);

        if(EIXO_X_PLAYER_TELA < res_x_comp/2 - 32){
            EIXO_X_PLAYER_TELA += 16*ZOOM;
            TELA_X_MAPA -= 1;
        }
        else if(EIXO_X_PLAYER_TELA > res_x_comp/2 + 32){
            EIXO_X_PLAYER_TELA -= 16*ZOOM;
            TELA_X_MAPA += 1;
        }

        else if(EIXO_Y_PLAYER_TELA < res_y_comp/4 - 32){
            EIXO_Y_PLAYER_TELA += 16*ZOOM;
            TELA_Y_MAPA -= 1;
        }
        else if(EIXO_Y_PLAYER_TELA > res_y_comp/4 + 32){
            EIXO_Y_PLAYER_TELA -= 16*ZOOM;
            TELA_Y_MAPA += 1;
        }
        
        else{
            resetCamera(10, 0);
            break;
        }

        redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
        al_flip_display();
    }
}

void Dialogo::dialogar(std::string *npc, std::string **opcoes, bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    keys[ALLEGRO_KEY_E] = false;
    Player->_dialogo = true;

    ajustarCamera(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    while(true){
        al_wait_for_event(event_queue, &evdialogo);

        if(this->_dialogos[this->posicao_atual_dialogo][0] == '*'){
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.8*res_y_comp, 0, this->_dialogos[posicao_atual_dialogo].c_str());
            
            al_flip_display();
            if(verificarTecla()) break;
        }

        else{
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            if(!this->_fluxo[this->posicao_atual_dialogo]){
                al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
                al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
                this->incremento_dialogoSPACE = 1;
            }
            else{
                al_draw_scaled_bitmap(caixa_texto, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
                this->incremento_dialogoZ = this->_fluxo_incremento[this->posicao_atual_incremento][0];
                this->incremento_dialogoX = this->_fluxo_incremento[this->posicao_atual_incremento][1];

                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.80*res_y_comp, 0, opcoes[this->posicao_atual_incremento][0].c_str());
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.905*res_y_comp, 0, opcoes[this->posicao_atual_incremento][0].c_str());                
            }

            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, npc[this->posicao_atual_dialogo].c_str());
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, this->_dialogos[this->posicao_atual_dialogo].c_str());
            al_flip_display();

            verificarTecla();
        }
    }

    Player->_dialogo = false;
}

void Dialogo::dialogar_lojista(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    keys[ALLEGRO_KEY_E] = false;
    Player->_dialogo = true;

    ajustarCamera(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    while(true){
        al_wait_for_event(event_queue, &evdialogo);

        if(this->posicao_atual_dialogo == 0){
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, "(sample text)");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.80*res_y_comp, 0, "SIM (Z)");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.905*res_y_comp, 0, "NÃO (X)");
            al_flip_display();

            verificarTecla();
        }

        else if(this->posicao_atual_dialogo == 1 && Player->getDinheiro() > 4){
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, "(sample text)");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_flip_display();

            if(verificarTecla()) break;
        }

        else if(this->posicao_atual_dialogo == 1){
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, "(sample text)");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_flip_display();

            if(verificarTecla()) break;
        }

        else{
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, "(sample text)");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_flip_display();

            if(verificarTecla()) break;
        }
    }

    Player->_dialogo = false;
}

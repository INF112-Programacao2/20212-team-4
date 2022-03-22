#include "Grafico.hpp"
#include "data.hpp"

#define PROP_PLAYER ((double) Player->getVida() / Player->getMaxVida())

ALLEGRO_EVENT evdialogo;
ALLEGRO_EVENT evmorte;
ALLEGRO_EVENT evfade;
bool buy_made; //variavel que define se o player ja fez ou nao a compra

void minimap(){
    if(keys[ALLEGRO_KEY_M]){
        al_draw_scaled_bitmap(mini_map, 0, 0, 1714, 1282, 256, 10, RES_WIDTH(1714)*0.85, RES_HEIGHT(1282)*0.85, 0);
        al_draw_scaled_bitmap(player_minimap, 0, 0, 12, 12, EIXO_X_MINIMAP, EIXO_Y_MINIMAP, RES_WIDTH(12), RES_HEIGHT(12), 0);
    }
}

void redesenhar(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 
        0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0.8);

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
    al_draw_scaled_bitmap(lifebar, 0, 0, 322, 73, RES_WIDTH(99*CELULA) + RES_WIDTH(5), RES_HEIGHT(15), RES_WIDTH(317) * PROP_PLAYER, RES_HEIGHT(73), 0);
    al_draw_scaled_bitmap(contorno, 0, 0, 322, 73, RES_WIDTH(99*CELULA), RES_HEIGHT(15), RES_WIDTH(322), RES_HEIGHT(73), 0);

    al_draw_textf(font15, al_map_rgb(60,25,97), RES_WIDTH(110*CELULA), RES_HEIGHT(105), 0,"$ %d", Player->getDinheiro());

    al_draw_textf(font15, al_map_rgb(60,25,97), RES_WIDTH(105*CELULA), RES_HEIGHT(105), 0,"%d", Player->qtdItem("Comida"));
    al_draw_scaled_bitmap(frango, 0, 0, 16, 16, RES_WIDTH(100*CELULA), RES_HEIGHT(105), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);

    if(Player->qtdItem("Estrela de Xerife") > 0){
        al_draw_scaled_bitmap(estrela, 0, 0, 32, 32, RES_WIDTH(109*CELULA), RES_HEIGHT(230), RES_WIDTH(16*6.5), RES_HEIGHT(16*6.5), 0);
    }
    if(Player->qtdItem("Relogio") != 0){
        al_draw_scaled_bitmap(relogiohud, 0, 0, 16, 16, RES_WIDTH(115*CELULA), RES_HEIGHT(180), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Chave") != 0){
        al_draw_scaled_bitmap(chavehud, 0, 0, 16, 16, RES_WIDTH(110*CELULA), RES_HEIGHT(180), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Espingarda") != 0){
        al_draw_scaled_bitmap(espingarda, 0, 0, 34, 16, RES_WIDTH(101*CELULA), RES_HEIGHT(180), RES_WIDTH(34*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }
    if(Player->qtdItem("Pocao") != 0){
        al_draw_scaled_bitmap(pocaohud, 0, 0, 16, 16, RES_WIDTH(115*CELULA), RES_HEIGHT(250), RES_WIDTH(16*ZOOM), RES_HEIGHT(16*ZOOM), 0);
    }

    al_draw_scaled_bitmap(general_player, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
        RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);

    if(i == 64){
        if(j == 16)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(64), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(4), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);

        else if(j == 17)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(128), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(4), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);

        else if(j == 18)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(192), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(4), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);
    }
    else if(i == 63){
        if(j == 16)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(64), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(68), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);

        else if(j == 17)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(128), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(68), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);

        else if(j == 18)
            al_draw_scaled_bitmap(portao, 0, 0, 80, 64, RES_WIDTH(EIXO_X_PLAYER_TELA)-RES_WIDTH(192), RES_HEIGHT(EIXO_Y_PLAYER_TELA)+RES_HEIGHT(68), RES_WIDTH(80*ZOOM), RES_HEIGHT(64*ZOOM), 0);
    }


    if(botao->interacaoProxima('2') && !Player->_dialogo){//caso haja uma interacao proxima e o personagem não esteja na loja
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.85*res_y_comp, 0,"Aperte          para Interagir");
        al_draw_scaled_bitmap(botaointeracao, 0,  0, 18, 18, RES_WIDTH(770), 0.85*res_y_comp, RES_WIDTH(18*ZOOM), RES_HEIGHT(18*ZOOM), 0);
    }
    else if(Player->getVida()<Player->getMaxVida() && Player->qtdItem("Comida")>0){
        //caso o player tenha comida no inventário e não esteja com a vida completa
        //ele recebe a seguinte mensagem:
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.85*res_y_comp, 0,"Aperte          para comer");
        al_draw_scaled_bitmap(botaocomer, 0,  0, 18, 18, RES_WIDTH(770), 0.85*res_y_comp, RES_WIDTH(18*ZOOM), RES_HEIGHT(18*ZOOM), 0);
        
    }   
}

void fadeout(){
    timer = al_create_timer(0.5);

    int alfa = 130;
    while (alfa <= 255){
        al_wait_for_event(event_queue, &evfade);

        if(evfade.type == ALLEGRO_EVENT_TIMER){
            al_clear_to_color(al_map_rgba(0, 0, 0, 0));
            al_draw_tinted_scaled_bitmap(map, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 
                0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0.8);
            al_draw_tinted_scaled_bitmap(general_player, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
                RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);

            al_flip_display();
            alfa += 15;
        }
    }

    timer = al_create_timer(1.0/FPS);
}

bool Dialogo::verificarTecla(){
    if(evdialogo.type == ALLEGRO_EVENT_KEY_DOWN){
        keys[evdialogo.keyboard.keycode] = true;

        if(this->_fluxo[posicao_atual_dialogo] == false && keys[ALLEGRO_KEY_SPACE]){
            this->posicao_atual_dialogo += this->incremento_dialogoSPACE;
            keys[evdialogo.keyboard.keycode] = false;

            return true;
        }

        else if(this->_fluxo[posicao_atual_dialogo] == true && keys[ALLEGRO_KEY_X]){
            this->posicao_atual_dialogo += this->incremento_dialogoX;
            this->posicao_atual_incremento++;
            keys[evdialogo.keyboard.keycode] = false;

            return true;
        }

        else if(this->_fluxo[posicao_atual_dialogo] == true && keys[ALLEGRO_KEY_Z]){
            this->posicao_atual_dialogo += this->incremento_dialogoZ;
            this->posicao_atual_incremento++;
            keys[evdialogo.keyboard.keycode] = false;

            return true;
        }
    }

    return false;
}

/* DIALOGOS DO JOGO */
Dialogo::Dialogo(std::string *dialogos, std::map <short int, bool> fluxo, short int **incrementos){
    this->_dialogos = dialogos;
    this->_fluxo = fluxo;
    this->_fluxo_incremento = incrementos;

    this->posicao_atual_dialogo = 0;
    this->posicao_atual_incremento = 0;
    this->incremento_dialogoX = this->incremento_dialogoZ = this->incremento_dialogoSPACE = 1;
}

Dialogo::Dialogo(){
    std::map<short int, bool> fluxo_loja = {{0, true}, {1, false}, {1, false}};

    this->_fluxo = fluxo_loja;

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

bool Dialogo::dialogar(std::string npc, std::string **opcoes, bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    bool retorno = false;
    keys[ALLEGRO_KEY_E] = false;
    Player->_dialogo = true;
    std::string fala;

    if(!BATALHA_JOSE && Player->getNivel() < 6) ajustarCamera(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    while(true){
        al_wait_for_event(event_queue, &evdialogo);
        if(Player->getNivel() < 6){
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
        }
        else if(Player->getNivel() == 6){
            al_clear_to_color(al_map_rgb(238,202,169));
            al_draw_scaled_bitmap(telaFinal, 0, 30, res_x_comp, res_y_comp, 110, 0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);
        }

        if(this->_dialogos[this->posicao_atual_dialogo][1] == '*'){
            fala = this->_dialogos[this->posicao_atual_dialogo].substr(2, this->_dialogos[this->posicao_atual_dialogo].length()-2);

            if(this->_dialogos[this->posicao_atual_dialogo][2] == '!'){
                fala = this->_dialogos[this->posicao_atual_dialogo].substr(3, this->_dialogos[this->posicao_atual_dialogo].length()-3);
                retorno = true; 
            }

            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            
            if(verificarTecla()) break;
        }

        else{
            fala = this->_dialogos[this->posicao_atual_dialogo].substr(1, this->_dialogos[this->posicao_atual_dialogo].length()-1);
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
                al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.905*res_y_comp, 0, opcoes[this->posicao_atual_incremento][1].c_str());                
            }
        }


        if(this->_dialogos[this->posicao_atual_dialogo][0] == '1'){
            al_draw_scaled_bitmap(icone_player, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, Player->getNome().c_str());
        }
        else {
            al_draw_scaled_bitmap(icone, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, npc.c_str());
        }
        al_flip_display();

        al_draw_multiline_text(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, RES_WIDTH(950), RES_HEIGHT(40), 0, fala.c_str());
        verificarTecla();

        al_flip_display();
    }

    resetTeclas();
    Player->_dialogo = false;
    return retorno;
}

/* INTERACAO DO PLAYER COM A LOJA*/
void Dialogo::dialogar_lojista(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao){
    Player->_dialogo = true; //o dialogo com o lojista esta em andamento

    ajustarCamera(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);//efeito de reposicionar a camera
    icone = al_load_bitmap("./../assets/icone-cervejeiro.bmp");

    while(true){//enquanto o player estiver interagindo com a loja
        al_wait_for_event(event_queue, &evdialogo);//capturando um evento

        if(this->posicao_atual_dialogo == 0){
            //quando o player decicide interagir com o loja, ele recebe a seguinte mensagem:
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);//todos os elementos do mapa são redesenhados
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, 
            "Olá rapaz! Bem vindo à loja! Deseja adquirir");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.85*res_y_comp, 0, 
            "comida por $5? Você pode recarregar suas");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.90*res_y_comp, 0, 
            "energias com ela.");
            buy_made=false; //ou seja, a compra ainda não foi feita
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.80*res_y_comp, 0, "SIM (Z)");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(1550), 0.905*res_y_comp, 0, "NÃO (X)");
            al_draw_scaled_bitmap(icone, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);

            al_flip_display();

            verificarTecla();//dependendo da tecla que for pressionada, a posicao_atual_dialogo muda de valor
        }

        else if(this->posicao_atual_dialogo == 1 && (Player->getDinheiro() > 4 || buy_made)){
            //caso o usuario aperte Z, possua dinheiro suficiente, ou já tenha realizado a compra
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);//todos os elementos do mapa são redesenhados
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            if(!buy_made){//se a compra ainda não foi feita
                Player->setDinheiro(Player->getDinheiro()-5); //diminui o dinheiro
                Player->addItem("Comida", 1); //aumenta a quantidade de comida
                buy_made=true; //agora a compra foi feita
            }
            //mostramos essa mensagem na tela depois que a compra for feita e enquanto o usuario
            //não apertar espaco para sair 
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, 
            "Prontinho! Foi bom fazer negócios com você!");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_draw_scaled_bitmap(icone, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);
            al_flip_display();

            if(verificarTecla()) break; //se o usuario apertar espaco, a interacao com a loja termina
        }

        else if(this->posicao_atual_dialogo == 1 && !buy_made){
            //caso o usuario aperte Z, ainda não realizou uma compra, nem possui dinheiro para tal
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);//todos os elementos do mapa são redesenhados
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

            //ele recebe a seguinte mensagem:
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, 
            "Parece que você não possui dinheiro suficiente");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.85*res_y_comp, 0, 
            "para investir! Vá buscar seu ouro rapaz, e volte ");
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.90*res_y_comp, 0, 
            "depois!");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_draw_scaled_bitmap(icone, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);
            al_flip_display();            

            if(verificarTecla()) break; //se o usuario apertar espaco, a interacao com a loja termina
        }

        else{
            //caso o usuario aperte X, ou seja, queira sair da loja
            redesenhar(rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);//todos os elementos do mapa são redesenhados
            al_draw_scaled_bitmap(caixa_texto, 0, 0, 1520, 1080, 0, 0, 1520*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);

             //ele recebe a seguinte mensagem:
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(520), 0.80*res_y_comp, 0, "Até logo!");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(355), 0.895*res_y_comp, 0, "VENDEDOR");
            al_draw_textf(font10, al_map_rgb(58,15,43), RES_WIDTH(1360), 0.91*res_y_comp, 0, "Espaço >");
            al_draw_scaled_bitmap(icone, 0, 0, 18, 18, RES_WIDTH(348), RES_HEIGHT(825), RES_WIDTH(128), RES_HEIGHT(128), 0);
            al_flip_display();

            if(verificarTecla()) break; //se o usuario apertar espaco, a interacao com a loja termina
        }
    }

    resetTeclas();
    Player->_dialogo = false; //o dialogo com o lojista termina
}

bool enterToReset(){
    if(evmorte.type == ALLEGRO_EVENT_KEY_DOWN){
        keys[evmorte.keyboard.keycode] = true;

        if(keys[ALLEGRO_KEY_ENTER]){
            reiniciar = true;
            keys[evmorte.keyboard.keycode] = false;

            return true;
        }
    }

    return false;
}

void telaMenu(bool iniciar){
    resetTeclas();
    double posicao_X = 39;
    double posicao_Y = 19;
    bool esquerda = true;

    timer = al_create_timer(1);
    while (!iniciar){
        al_wait_for_event(event_queue, &evmorte);
        if(evmorte.type == ALLEGRO_EVENT_TIMER){
            al_draw_scaled_bitmap(mapmenu, posicao_X*CELULA, posicao_Y*CELULA, res_x_comp, res_y_comp, 0, 
                0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);
            al_draw_scaled_bitmap(menu, 0, 0, 1920, 1080, 0, 0, res_x_comp, res_y_comp, 0);
            al_draw_scaled_bitmap(titulo, 0, 0, 172, 17, RES_WIDTH(res_x_comp/5), RES_HEIGHT(res_y_comp/4), RES_WIDTH(172*2*ZOOM), RES_HEIGHT(18*2*ZOOM), 0);
            
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(635), 0.91*res_y_comp, 0,"Aperte               para iniciar");
            al_draw_scaled_bitmap(botaoreiniciar, 0,  0, 34, 18, RES_WIDTH(795), 0.91*res_y_comp, RES_WIDTH(34*ZOOM), RES_HEIGHT(18*ZOOM), 0);
            
            if (esquerda){
                posicao_X+=0.5;
                if(posicao_X==56){
                    esquerda=false;
                }
            }
            else{
                if(posicao_X>39){
                    posicao_X-=0.5;
                }
                else{
                    esquerda=true;
                }
            }
        }
        al_flip_display();
        if(enterToReset()) break;
    }

    general_player = player_f1;
    timer = al_create_timer(1.0/FPS);
}

void telaGameOver(bool reiniciar){
    resetTeclas();
    
    int cont = -1;
    timer = al_create_timer(1);
    while (!reiniciar){
        al_wait_for_event(event_queue, &evmorte);

        if(evmorte.type == ALLEGRO_EVENT_TIMER){
            switch(cont){
                case -1:
                    al_draw_scaled_bitmap(game_over1, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 0:
                    al_draw_scaled_bitmap(game_over1, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 1:
                    al_draw_scaled_bitmap(game_over2, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 2:
                    al_draw_scaled_bitmap(game_over3, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 3:
                    al_draw_scaled_bitmap(game_over4, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 4:
                    al_draw_scaled_bitmap(game_over5, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 5:
                    al_draw_scaled_bitmap(game_over6, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 6:
                    al_draw_scaled_bitmap(game_over7, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 7:
                    al_draw_scaled_bitmap(game_over8, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 8:
                    al_draw_scaled_bitmap(game_over9, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 9:
                    al_draw_scaled_bitmap(game_over10, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                case 10:
                    al_draw_scaled_bitmap(game_over11, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    cont++;
                    break;
                default:
                    al_draw_scaled_bitmap(game_over12, 0, 0, 416, 304, 0, 0, res_x_comp, 
                    res_y_comp, 0);
                    al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.85*res_y_comp, 0,"Aperte               para reiniciar");
                    al_draw_scaled_bitmap(botaoreiniciar, 0,  0, 34, 18, RES_WIDTH(770), 0.85*res_y_comp, RES_WIDTH(34*ZOOM), RES_HEIGHT(18*ZOOM), 0);
                    break;
            }
        }

        al_flip_display();
        if(enterToReset()) break;
    }

    general_player = player_f1;
    timer = al_create_timer(1.0/FPS);
}
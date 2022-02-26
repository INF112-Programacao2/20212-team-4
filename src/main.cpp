#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Save.hpp"
#include <math.h>

/* GAME SAVE */
GameSave *Save = new GameSave();

/* PERSONAGENS  */
Protagonista *Player = new Protagonista(10, 3);
Inimigo *Silvio = new Inimigo("Silvio", 12, 3, 2);
Inimigo *Xerife_Espeto = new Inimigo("Xerife Espeto", 24, 4, 4);
Inimigo *Jose_do_Caixao = new Inimigo("Jose do caixao", 32, 4, 3);
Inimigo *Caixao_do_Jose = new Inimigo("Caixao do Jose", 15, 2, 1);
Inimigo *Geraldina = new Inimigo("Geraldina", 45, 4, 3);
Inimigo *Johnny_Cash = new Inimigo("Johnny Cash", 60, 4, 5);

/* ITENS */
Interacao *Chave = new Interacao("Chave", 81, 70, '5');
Interacao *Relogio = new Interacao("Relogio", 84, 32, '6');
Interacao *Pocao = new Interacao("Pocao", 1, 4, '7');
Interacao *Dinheiro1 = new Interacao("Dinheiro1", 3, 14, '8');
Interacao *Dinheiro2 = new Interacao("Dinheiro2", 78, 19, '8');
Interacao *Dinheiro3 = new Interacao("Dinheiro3", 2, 46, '8');
Interacao *Dinheiro4 = new Interacao("Dinheiro4", 68, 67, '8');
Interacao *Loja = new Interacao("Loja", 42, 45, '4'); //criando ponteiro para objeto loja do tipo interecao
Interacao *Botao_Interagir = new Interacao("Botaointeracao", 0, 0, '1');

/* MISSOES SECUNDARIAS */
MissaoSecundaria *Missao_Espingarda = new MissaoSecundaria("Espingarda", 0, 0, 'E', 10, "Andrew");
MissaoSecundaria *Missao_Chave = new MissaoSecundaria("Chave", 0, 0, 'C', 10, "Cris");
MissaoSecundaria *Missao_Relogio = new MissaoSecundaria("Relogio", 0, 0, 'R', 10, "Saul");
MissaoSecundaria *Missao_Pocao = new MissaoSecundaria("Pocao", 0, 0, 'P', 10, "Clara");

/* FUNCOES */
bool camera(char mov);
void posicao(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, ALLEGRO_BITMAP *img3, ALLEGRO_BITMAP *img4);
void redesenhar();
bool to_move();
void galinha();
void itens();
void interagir();
void hud();
void loja();

/* VARIAVEIS */
bool keys[ALLEGRO_KEY_MAX] = {0};
short int mov_cont = 0;
ALLEGRO_EVENT ev0;
ALLEGRO_EVENT ev1;
short int contGalinha = 0;
bool store=false;
short int buy;


int main(int argc, char **argv){

    /* COMECANDO A EXECUCAO DO JOGO*/
    if(inicializaJogo()){
        Save->read_save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Chave, Relogio, Pocao);
        Player->setNome("Barbara");

        /* === NÍVEL UM === */
        // Neste nível, o jogador tem a batalha contra o pistoleiro Silvio, em frente ao Saloon. Não há NPCs 
        // no mapa para passar missões.

        while(Player->getNivel()==1){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar();

            al_flip_display();
        }

        delete Silvio;
        Silvio = nullptr;

        /* === NÍVEL DOIS === */
        // Neste nível, o jogador tem a batalha contra o Xerife Espeto, no deserto. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.    

        while(Player->getNivel()==2){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar();

            al_flip_display();
        }

        delete Xerife_Espeto;
        Xerife_Espeto = nullptr;

        /* === NÍVEL TRÊS === */
        // Neste nível, o jogador tem a batalha contra Geraldina, no rancho. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.  

        while(Player->getNivel()==3){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar();

            al_flip_display();
        }

        delete Geraldina;
        Geraldina = nullptr;

        /* === NÍVEL QUATRO === */
        // Neste nível, o jogador tem a batalha contra José do Caixão e o Caixão do josé, na igreja. 
        // Estão presentes todos os NPCs no mapa para passar missões.

        while(Player->getNivel()==4){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar();

            al_flip_display();
        }

        delete Jose_do_Caixao;
        Jose_do_Caixao = nullptr;
        delete Caixao_do_Jose;
        Caixao_do_Jose = nullptr;

        /* === NÍVEL QUATRO === */
        // Neste nível, o jogador tem a batalha contra Johnny Cash, na cabana. Estão presentes 
        // todos os NPCs no mapa para passar missões.

        while(Player->getNivel()==5){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar();

            al_flip_display();
        }

        delete Johnny_Cash;
        Johnny_Cash = nullptr;

        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao);
    }

    Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao);
    if(Player != nullptr) delete Player;
    if(Silvio != nullptr) delete Silvio;
    if(Xerife_Espeto != nullptr) delete Xerife_Espeto;
    if(Geraldina != nullptr) delete Geraldina;
    if(Jose_do_Caixao != nullptr) delete Jose_do_Caixao;
    if(Caixao_do_Jose != nullptr) delete Caixao_do_Jose;
    if(Johnny_Cash != nullptr) delete Johnny_Cash;

    return 0;
}

/* FUÇÃO QUE ESTUDA O COMPORTAMENTO DA CÂMERA */
bool camera(char mov){
    // Retorna false caso o personagem não já se mover (caso esteja na borda da matriz CAMERA)
    // e true caso ele possa se mover (caso esteja no "miolo" da matriz câmera).

    if(mov == 'C'){
        // Caso esteja na borda de cima.
        if(camI == 0){
            TELA_Y_MAPA -= 1;
            i--;
            return false;
        }

        else{
            CAMERA[camI][camJ] = valueIJcam;
            camI--;
            valueIJcam = CAMERA[camI][camJ];
            CAMERA[camI][camJ] = 'P';

            return true;
        }
    }

    else if(mov == 'B'){
        // Caso esteja na borda de baixo.
        if(camI == 9){
            TELA_Y_MAPA += 1;
            i++;
            return false;
        }

        else{
            CAMERA[camI][camJ] = valueIJcam;
            camI++;
            valueIJcam = CAMERA[camI][camJ];
            CAMERA[camI][camJ] = 'P'; 

            return true;
        }
    }

    else if(mov == 'E'){
        // Caso esteja na borda da esquerda.
        if(camJ == 0){
            TELA_X_MAPA -= 1;
            j--;
            return false;
        }
        else{
            CAMERA[camI][camJ] = valueIJcam;
            camJ--;
            valueIJcam = CAMERA[camI][camJ];
            CAMERA[camI][camJ] = 'P'; 

            return true;
        }
    }

    else{
        if(camJ == 21){
            // Caso esteja na borda da direita.
            TELA_X_MAPA += 1;
            j++;
            return false;
        }

        else{
            CAMERA[camI][camJ] = valueIJcam;
            camJ++;
            valueIJcam = CAMERA[camI][camJ];
            CAMERA[camI][camJ] = 'P'; 

            return true;
        }
    }
}

/*FUNCAO QUE VERIFICA A POSIÇÃO DO PERSONAGEM ENQUANTO ANDA*/
void posicao(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, ALLEGRO_BITMAP *img3, ALLEGRO_BITMAP *img4){    
    if(mov_cont==0){
        general_player = img1;
        mov_cont++;
    }
    else if(mov_cont == 1){
        general_player = img2;
        mov_cont++;
    }
    else if(mov_cont == 3){
        general_player = img3;
        mov_cont++;       
    }
    else{
        general_player = img4;
        mov_cont = 0;
    }
}

/*FUNCAO QUE FAZ A MOVIMENTACAO DO PERSONAGEM*/
bool to_move(){
    if (ev0.type == ALLEGRO_EVENT_KEY_DOWN) {
        keys[ev0.keyboard.keycode] = true;

        if(keys[ALLEGRO_KEY_ESCAPE]) {
            return false;
        }   
    }
    else if (ev0.type == ALLEGRO_EVENT_KEY_UP) {
        keys[ev0.keyboard.keycode] = false;
        general_player = parado;
        mov_cont = 0;
    }

    if(ev0.type == ALLEGRO_EVENT_TIMER){  
        if (keys[ALLEGRO_KEY_E])
            interagir();    

        else if(keys[ALLEGRO_KEY_W]){
            if(MAPA[i][j] == '1' && camera('C')){
                i--;
                EIXO_Y_PLAYER_TELA -= 16*ZOOM;
            }
            /*SE O PERSONAGEM ENCOSTA EM UM CACTO, ELE SOFRE UM DANO */
            else if(MAPA[i][j] == '*'){   
                Player -> setVida(Player -> getVida() -0.5);
            }

            parado = player_c1;
            posicao(player_c1, player_c2, player_c3, player_c4);    
        }
        else if (keys[ALLEGRO_KEY_S]){
            if(MAPA[i+2][j] == '1' && camera('B')){
                i++;
                EIXO_Y_PLAYER_TELA += 16*ZOOM;
            }
            else if(MAPA[i+2][j] == '*'){
                Player -> setVida(Player -> getVida() -0.5);
            }
            parado = player_f1;
            posicao(player_f1, player_f2, player_f3, player_f4);
        }
        else if (keys[ALLEGRO_KEY_A]){
            if(MAPA[i+1][j-1] == '1' && camera('E')){
                j--;
                EIXO_X_PLAYER_TELA -= 16*ZOOM;
            }  
            else if(MAPA[i+1][j-1] == '*'){
                Player -> setVida(Player -> getVida() -0.5);
            }
            parado = player_e1;
            posicao(player_e1, player_e2, player_e3, player_e4);
        }
        else if (keys[ALLEGRO_KEY_D]){
            if(MAPA[i+1][j+1] == '1' && camera('D')){
                j++;
                EIXO_X_PLAYER_TELA += 16*ZOOM;
            }
            else if(MAPA[i+1][j+1] == '*'){
                Player -> setVida(Player -> getVida() -0.5);
            }
            parado = player_d1;
            posicao(player_d1, player_d2, player_d3, player_d4);
        }
        else if (keys[ALLEGRO_KEY_C] && store){
            buy=2;
        }
        else if (keys[ALLEGRO_KEY_B]&& store){
            buy=3;
        }
    }
    else if(ev0.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        return false;
    }

    return true;
}

/* FUNCAO QUE DESENHA OS ITENS COLETAVEIS */
void itens(){
    if (!Relogio->completo())
        al_draw_scaled_bitmap(relogio, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (!Chave->completo())
        al_draw_scaled_bitmap(chave, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);

    if (!Pocao->completo())
        al_draw_scaled_bitmap(pocao, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (Dinheiro1!=nullptr)
        al_draw_scaled_bitmap(dinheiro1, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (Dinheiro2!=nullptr)
        al_draw_scaled_bitmap(dinheiro2, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (Dinheiro3!=nullptr)
        al_draw_scaled_bitmap(dinheiro3, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
    if (Dinheiro4!=nullptr)
        al_draw_scaled_bitmap(dinheiro4, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    
}

/* FUNCAO QUE DESENHA AS GALINHAS */
void galinha(){
    switch(contGalinha){
        case 0:
            al_draw_scaled_bitmap(galinha1, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 1:
            al_draw_scaled_bitmap(galinha2, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 2:
            al_draw_scaled_bitmap(galinha3, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 3:
            al_draw_scaled_bitmap(galinha4, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, 
                res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha = 0;
            break;
    }
}

/* FUNCAO QUE GERENCIA A LOJA*/
void loja(){

    if(Player->getDinheiro()>=5 && buy==1){
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(300), 0.80*res_y_comp, 0,
        "Vendedor: Olá rapaz! Bem vindo à loja! Deseja adquirir comida por $5?");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(560), 0.85*res_y_comp, 0,
        "Aperte C para comprar ou B para sair da loja");

    }
    if(Player->getDinheiro()<5){
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(340), 0.80*res_y_comp, 0,
        "Oh! Parece que você não possui dinheiro suficiente para investir!");
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(540), 0.85*res_y_comp, 0,
        "Vá buscar seu ouro rapaz, e volte depois!");
        
    }
    if (buy==2){
        Player->setDinheiro(Player->getDinheiro()-5);
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(760), 0.85*res_y_comp, 0,
        "Prontinho! Foi bom fazer negócios com você!");
        buy=0;
    }
    if(buy==3)
    {
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(800), 0.85*res_y_comp, 0,
        "Até logo!");
        buy=0;
    }   
    
}

/* FUNCAO PARA COLETAR O ITEM */
void interagir(){
    if(Relogio->itemProximo('1'))
        Player->addItem(Relogio->getNome(), 1);// Adiciona um relogio no inventario

    else if(Chave->itemProximo('1'))
        Player->addItem(Chave->getNome(), 1);
    
    else if(Pocao->itemProximo('1')){
        std::cout << Pocao->getNome() << std::endl;
        Player->addItem(Pocao->getNome(), 1);
        std::cout << Pocao->getNome() << " " << Player->qtdItem("Pocao") << std::endl;
    }
    
    else if(Dinheiro1 != nullptr && Dinheiro1->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro1;
        Dinheiro1 = nullptr;
    }
    
    else if(Dinheiro2 != nullptr && Dinheiro2->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro2;
        Dinheiro2 = nullptr;
    }   
    
    else if(Dinheiro3 != nullptr && Dinheiro3->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro3;
        Dinheiro3 = nullptr;
    }
    
    else if(Dinheiro4 != nullptr && Dinheiro4->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro4;
        Dinheiro4 = nullptr;
    }

    else if(Loja->itemProximo()){
        std::cout << Loja->getNome() << std::endl;
        store=true;
        buy=1;
    }
}

/* FUNCAO QUE DESENHA O HUD */
void hud(){
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
}

void redesenhar(){
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 
        0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);

    itens();
    galinha();
    hud();

    al_draw_scaled_bitmap(general_player, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
        RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);

    if(Botao_Interagir->itemProximo() && !store){
        al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(760), 0.85*res_y_comp, 0,"Aperte          para Interagir");
        al_draw_scaled_bitmap(botaointeracao, 0,  0, 18, 18, RES_WIDTH(920), 0.85*res_y_comp, RES_WIDTH(18*ZOOM), RES_HEIGHT(18*ZOOM), 0);
    }
    else if(store){
        loja();
    }
}
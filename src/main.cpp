#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Save.hpp"
#include "data.hpp"
#include "Grafico.hpp"
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
MissaoSecundaria *Missao_Espingarda = new MissaoSecundaria(0, 0, 'E', 10);
MissaoSecundaria *Missao_Chave = new MissaoSecundaria(0, 0, 'C', 10);
MissaoSecundaria *Missao_Relogio = new MissaoSecundaria(0, 0, 'R', 10);
MissaoSecundaria *Missao_Pocao = new MissaoSecundaria( 0, 0, 'P', 10);

/* FUNCOES */
bool camera(char mov);
void posicao(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, ALLEGRO_BITMAP *img3, ALLEGRO_BITMAP *img4);
bool to_move();
void interagir();
void loja(); //funcao que gerencia a loja


short int mov_cont = 0;
ALLEGRO_EVENT ev0;
ALLEGRO_EVENT ev1;
short int contGalinha = 0;

int main(int argc, char **argv){

    /* COMECANDO A EXECUCAO DO JOGO*/
    if(inicializaJogo()){
        Save->read_save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Chave, Relogio, Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        Player->setNome("Barbara");

        /* === NÍVEL UM === */
        // Neste nível, o jogador tem a batalha contra o pistoleiro Silvio, em frente ao Saloon. Não há NPCs 
        // no mapa para passar missões.

        while(Player->getNivel()==1){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

            al_flip_display();
        }
        if(Player->getNivel() == 1) Player->nextLevel();

        delete Silvio;
        Silvio = nullptr;

        /* === NÍVEL DOIS === */
        // Neste nível, o jogador tem a batalha contra o Xerife Espeto, no deserto. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.    

        while(Player->getNivel()==2){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move()) break;   
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

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
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

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
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

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
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

            al_flip_display();
        }

        delete Johnny_Cash;
        Johnny_Cash = nullptr;
    }

    Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
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
    }

    if(ev0.type == ALLEGRO_EVENT_TIMER){  
        if (keys[ALLEGRO_KEY_E]) //se o usuario apertar E
            interagir(); //chamamos a funcao para verificar com o que ele quer interagir 

        else if(keys[ALLEGRO_KEY_W]){
            //serao desenhadas as imagens do personagem
            img1=player_c1; img2=player_c2; img3=player_c3; img4=player_c4;

            if(MAPA[i][j] == '1' && camera('C')){
                i--;
                EIXO_Y_PLAYER_TELA -= 16*ZOOM;
            }

            /*SE O PERSONAGEM ENCOSTA EM UM CACTO, ELE SOFRE UM DANO */
            else if(MAPA[i][j] == '*'){   
                Player -> setVida(Player -> getVida() - 0.25);
                //serao desenhadas as imagens do personagem levando dano
                img1= dano_costas; img3=dano_costas; 
            }

            parado = player_c1;
            posicao(img1, img2, img3, img4);    
        }
        else if (keys[ALLEGRO_KEY_S]){
            //serao desenhadas as imagens do personagem
            img1=player_f1; img2=player_f2; img3=player_f3; img4=player_f4;

            if(MAPA[i+2][j] == '1' && camera('B')){
                i++;
                EIXO_Y_PLAYER_TELA += 16*ZOOM;
            }
            else if(MAPA[i+2][j] == '*'){
                Player -> setVida(Player -> getVida() - 0.25);
                //serao desenhadas as imagens do personagem levando dano
                img1=dano_frente; img3=dano_frente; 
            }

            parado = player_f1;
            posicao(img1, img2, img3, img4);
        }
        else if (keys[ALLEGRO_KEY_A]){
            //serao desenhadas as imagens do personagem
            img1=player_e1; img2=player_e2; img3=player_e3; img4=player_e4;

            if(MAPA[i+1][j-1] == '1' && camera('E')){
                j--;
                EIXO_X_PLAYER_TELA -= 16*ZOOM;
            }  
            else if(MAPA[i+1][j-1] == '*'){
                Player -> setVida(Player -> getVida() - 0.25);
                //serao desenhadas as imagens do personagem levando dano
                img1=dano_esquerda; img3=dano_esquerda;
            }

            parado = player_e1;
            posicao(img1, img2, img3, img4);
        }
        else if (keys[ALLEGRO_KEY_D]){
            //serao desenhadas as imagens do personagem
            img1=player_d1; img2=player_d2; img3=player_d3; img4=player_d4;

            if(MAPA[i+1][j+1] == '1' && camera('D')){
                j++;
                EIXO_X_PLAYER_TELA += 16*ZOOM;
            }
            else if(MAPA[i+1][j+1] == '*'){
                Player -> setVida(Player -> getVida() - 0.25);
                //serao desenhadas as imagens do personagem levando dano
                img1=dano_direita; img3=dano_direita;
            }

            parado = player_d1;
            posicao(img1, img2, img3, img4);
        }
        else if (keys[ALLEGRO_KEY_F]){
            //se o player apertar F
            //e caso o player tenha comida no inventário e não esteja com a vida completa
            if(Player->getVida()<Player->getMaxVida() && Player->qtdItem("Comida")>0){
                Player->addItem("Comida", -1); //reduz a quantidade de comida
                Player->curarVida(1); //aumenta um ponto de vida
            }
        }
    }
    else if(ev0.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        return false;
    }

    return true;
}

/* FUNCAO QUE GERENCIA A LOJA*/
void loja(){
    Dialogo *dialogoLoja = new Dialogo();

    dialogoLoja->dialogar_lojista(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);

    delete dialogoLoja;
}   

/* FUNCAO PARA COLETAR O ITEM */
void interagir(){
    if(Relogio->itemProximo('1'))
        Player->addItem(Relogio->getNome(), 1);// Adiciona um relogio no inventario

    else if(Chave->itemProximo('1'))
        Player->addItem(Chave->getNome(), 1);
    
    else if(Pocao->itemProximo('1'))
        Player->addItem(Pocao->getNome(), 1);

    
    else if(Dinheiro1->itemProximo('1'))
        Player->setDinheiro(Player->getDinheiro()+10);
    
    else if(Dinheiro2->itemProximo('1'))
        Player->setDinheiro(Player->getDinheiro()+10);
    
    else if(Dinheiro3->itemProximo('1'))
        Player->setDinheiro(Player->getDinheiro()+10);
    
    else if(Dinheiro4->itemProximo('1'))
        Player->setDinheiro(Player->getDinheiro()+10);

    else if(Loja->interacaoProxima('y')){ //caso a interacao proxima seja a loja
        loja();
    }

    else if(Missao_Chave->missaoProxima('F')){
        if(Missao_Chave->getinicializada() == false){
            dialogoMissaoChavesPt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir, Missao_Chave);
        }

        else if(Missao_Chave->getinicializada() == true && Player->qtdItem("Chave") == 0){
            dialogoMissaoChavesExtra(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        }

        else if(Missao_Chave->getinicializada() == true && Player->qtdItem("Chave") == 1){
            dialogoMissaoChavesPt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Chave->getNome(), 1);
            Missao_Chave->pay(Player);
            Missao_Chave->finish();
            MAPA[28][54] = '1';
        }
    }

    else if(Missao_Pocao->missaoProxima('I')){
        if(Missao_Pocao->getinicializada() == false){
            dialogoMissaoPocaoPt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir, Missao_Pocao);
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 0){
            dialogoMissaoPocaoPt2Extra(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 1 && Player->getNivel() < 5){
            dialogoMissaoPocaoPt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Pocao->getNome(), 1);
            Missao_Chave->pay(Player);
            Missao_Chave->finish();
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 1 && Player->getNivel() == 5){
            dialogoMissaoPocaoPt2Level5(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Pocao->getNome(), 1);
            Missao_Chave->pay(Player);
            Missao_Chave->finish();

        }
        
    }
}

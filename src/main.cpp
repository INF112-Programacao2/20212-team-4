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
#include "Batalha.hpp"

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
Interacao *Batalha1 = new Interacao("Batalha1", 29, 40, 'S');


/* MISSOES SECUNDARIAS */
MissaoSecundaria *Missao_Espingarda = new MissaoSecundaria(0, 0, 'E', 10);
MissaoSecundaria *Missao_Chave = new MissaoSecundaria(0, 0, 'C', 10);
MissaoSecundaria *Missao_Relogio = new MissaoSecundaria(0, 0, 'R', 10);
MissaoSecundaria *Missao_Pocao = new MissaoSecundaria( 0, 0, 'P', 10);

/* DIALOGOS MISSOES */
Missao *Nivel1 = new Missao(0, 0, '3');
Missao *Nivel2 = new Missao(0, 0, 'A');
Missao *Nivel3 = new Missao(0, 0, 'J');
Missao *Nivel4 = new Missao(0, 0, 'C');
Missao *Nivel5 = new Missao(0, 0, 'F');

/* BATALHAS */
Batalha1x1 Batalha_Nivel1;


/* FUNCOES */
bool camera(char mov);
void posicao(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, ALLEGRO_BITMAP *img3, ALLEGRO_BITMAP *img4);
bool to_move();
void interagir();
void loja(); //funcao que gerencia a loja
void resetGame();


short int mov_cont = 0;
ALLEGRO_EVENT ev0;
ALLEGRO_EVENT ev1;
short int contGalinha = 0;

int main(int argc, char **argv){
    
    /* COMECANDO A EXECUCAO DO JOGO*/
    if(inicializaJogo()){
        INICIO:
        Save->read_save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Chave, Relogio, Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);

        /* === NÍVEL UM === */
        // Neste nível, o jogador tem a batalha contra o pistoleiro Silvio, em frente ao Saloon. Não há NPCs 
        // no mapa para passar missões.

        MAPA[29][40]='S'; //colocando o Silvio no mapa de colisão

        while(Player->getNivel()==1){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()) break;   
            redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            minimap();

            resetGame();
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
            }

            al_flip_display();
        }

        MAPA[29][40]='1'; //retirando o Silvio do mapa de colisão 
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
            minimap();

            resetGame();
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
            }

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
            minimap();

            resetGame();
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
            }

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
            minimap();

            resetGame();
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
            }

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
            minimap();

            resetGame();
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
            }

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
            EIXO_Y_MINIMAP -= 13.5; 
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
            EIXO_Y_MINIMAP += 13.5; 
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
            EIXO_X_MINIMAP -= 13.5; 

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
            EIXO_X_MINIMAP += 13.5; 

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
                EIXO_Y_MINIMAP -= 13.5; 
            }

            /*SE O PERSONAGEM ENCOSTA EM UM CACTO, ELE SOFRE UM DANO */
            else if(MAPA[i][j] == '*'){   
                Player -> setVida(Player -> getVida() - 0.1);
                //serao desenhadas as imagens do personagem levando dano
                img1=dano_costas; img3=dano_costas;
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
                EIXO_Y_MINIMAP += 13.5; 
            }
            else if(MAPA[i+2][j] == '*'){
                Player -> setVida(Player -> getVida() - 0.1);
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
                EIXO_X_MINIMAP -= 13.5;
            }  
            else if(MAPA[i+1][j-1] == '*'){
                Player -> setVida(Player -> getVida() - 0.1);
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
                EIXO_X_MINIMAP += 13.5;
            }
            else if(MAPA[i+1][j+1] == '*'){
                Player -> setVida(Player -> getVida() - 0.1);
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

    else if(Batalha1->batalhaProxima('S')){
       Batalha_Nivel1.batalhar();
       keys[ALLEGRO_KEY_E]=false;
    }

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
            Missao_Chave->finish();
            MAPA[28][50] = '0';
        }
    }

    else if(Missao_Pocao->missaoProxima('I')){
        if(Missao_Pocao->getinicializada() == false){
            dialogoMissaoPocaoPt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir, Missao_Pocao);
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 0){
            dialogoMissaoPocaoExtra(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 1 && Player->getNivel() < 5){
            dialogoMissaoPocaoPt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Pocao->getNome(), 1);
            Missao_Chave->finish();
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 1 && Player->getNivel() == 5){
            dialogoMissaoPocaoPt2Level5(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Pocao->getNome(), 1);
            Missao_Chave->finish();
            MAPA[13][30] = '0';
        }
    }

    else if(Missao_Espingarda->missaoProxima('H')){
        if(Missao_Espingarda->getinicializada() == false){
            dialogoMissaoEspingardaPt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir, Missao_Espingarda);
        }

        else if(Missao_Espingarda->getinicializada() == true && Player->qtdItem("Espingarda") == 1){
            dialogoMissaoEspingardaPt3(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            
            Player->subItem("Espingarda", 1);
            Missao_Espingarda->finish();
        }
        
        else if(Missao_Espingarda->getinicializada() == true && !Missao_Espingarda->completo()){
            dialogoMissaoEspingardaExtra(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        }
    }

    else if(Missao_Espingarda->missaoProxima('C')){
        if(Missao_Espingarda->getinicializada() && !Missao_Espingarda->completo() && Player->qtdItem("Espingarda") == 0){
            dialogoMissaoEspingardaPt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Player->addItem("Espingarda", 1);
        }

        else{
            dialogoMissaoEspingardaExtra2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);
        }
    }
    else if(Missao_Relogio->missaoProxima('G')){
        if(Missao_Relogio->getinicializada() == false){
            dialogoMissaoRelogioPt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir, Missao_Relogio);
        }
        else if(Missao_Relogio->getinicializada() == true && Player->qtdItem("Relogio") == 0){
            dialogoMissaoRelogioPt2Extra(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        }
        else if(Missao_Relogio->getinicializada() == true && Player->qtdItem("Relogio") == 1){
            dialogoMissaoRelogioPt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Relogio->getNome(), 1);
            Missao_Relogio->pay(Player);
            Missao_Relogio->finish();
            MAPA[39][63] = '0';
        }
    }

    else if(Player->getNivel() == 1){
        if(Nivel1->missaoProxima('3') && Nivel1->_etapa == 1){
            dialogoNivel1Pt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Nivel1->_etapa++;
            MAPA[29][40] = 'J'; // Adiciona Billy/Ambrósio na matriz
        }
        else if(Nivel1->missaoProxima('A') && Nivel1->_etapa == 2){
            dialogoNivel1Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);
        }
    }

    else if(Player->getNivel() == 2){
        if(Nivel2->missaoProxima('A') && Nivel2->_etapa == 1){

            Nivel2->_etapa++;
            MAPA[28][76] = 'J'; // Adiciona Renato na matriz
        }
        else if(Nivel2->missaoProxima('J') && Nivel2->_etapa == 2){

            MAPA[56][70] = MAPA[56][71] = MAPA[57][70] = MAPA[57][71] = 'B'; // Adiciona Xerife Espeto na matriz
        }
        else if(Nivel2->missaoProxima('B') && Nivel2->_etapa == 3){

        }
    }

    else if(Player->getNivel() == 3){
        if(Nivel3->missaoProxima('J') && Nivel3->_etapa == 1){

            Nivel2->_etapa++;
            MAPA[49][17] = MAPA[49][18] = 'C'; // Adiciona Geraldina na matriz
        }
        else if(Nivel3->missaoProxima('C') && Nivel3->_etapa == 2){

        } 
    }

    else if(Player->getNivel() == 4){
        if(Nivel4->missaoProxima('C')){

        }
    }

    else if(Player->getNivel() == 5){
        if(Nivel5->missaoProxima('E')){

        }
    }
}

void resetGame(){
    if(Player->isDead()){
        Player->setVida(Player->getMaxVida());
        telaGameOver(reiniciar);
    }
}
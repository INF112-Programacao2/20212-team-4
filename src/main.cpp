#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Save.hpp"
#include "data.hpp"
#include "Grafico.hpp"
#include <math.h>
#include "Batalha.hpp"
#include <time.h>

/* GAME SAVE */
GameSave *Save = new GameSave();

/* PERSONAGENS  */
Protagonista *Player = new Protagonista(10, 3);
Inimigo *Billy = new Inimigo("Billy", 21, 2, 3);
Inimigo *Xerife_Espeto = new Inimigo("Xerife Espeto", 40, 3, 3);
Inimigo *Jose_do_Caixao = new Inimigo("José do Caixão", 80, 3, 3);
Inimigo *Caixao_do_Jose = new Inimigo("Caixão do José", 60, 3, 3);
Inimigo *Geraldina = new Inimigo("Geraldina", 58, 3, 3);
Inimigo *Johnny_Cash = new Inimigo("Johnny Cash", 75, 4, 3);

/* ITENS */
Interacao *Chave = new Interacao("Chave", 81, 70, '5');
Interacao *Relogio = new Interacao("Relogio", 84, 32, '6');
Interacao *Pocao = new Interacao("Pocao", 1, 4, '7');
Interacao *Dinheiro1 = new Interacao("Dinheiro1", 3, 14, '8');
Interacao *Dinheiro2 = new Interacao("Dinheiro2", 78, 19, '8');
Interacao *Dinheiro3 = new Interacao("Dinheiro3", 2, 46, '8');
Interacao *Dinheiro4 = new Interacao("Dinheiro4", 68, 67, '8');
Interacao *Loja = new Interacao("Loja", 42, 45, '0'); //criando ponteiro para objeto loja do tipo interaçao
Interacao *Botao_Interagir = new Interacao("Botaointeracao", 0, 0, '1');


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

/* LISTA DE OBJETIVOS */
Objetivos *Lista = new Objetivos();

/* BATALHAS */
Batalha1x1 Batalha_Nivel1 (Billy, Player);
Batalha1x1 Batalha_Nivel2 (Xerife_Espeto, Player);
Batalha1x1 Batalha_Nivel3 (Geraldina, Player);
Batalha1x2 Batalha_Nivel4 (Jose_do_Caixao, Caixao_do_Jose, Player);
BatalhaFantasma Batalha_Nivel5 (Johnny_Cash, Player, Missao_Pocao);

/* FUNCOES */
bool camera(char mov);
void posicao(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, ALLEGRO_BITMAP *img3, ALLEGRO_BITMAP *img4);
bool to_move();
void interagir();
void loja(); //funcao que gerencia a loja
void resetGame();
void desenhaObjetivos();


short int mov_cont = 0;
ALLEGRO_EVENT ev0;
ALLEGRO_EVENT ev1;
short int contGalinha = 0;
bool brinde = false;

int main(int argc, char **argv){

    /* COMECANDO A EXECUCAO DO JOGO*/
    if(inicializaJogo()){
        srand (time(NULL));
        MENU:
        al_stop_samples();
        al_play_sample(highwayman, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
        while(true){
            al_wait_for_event(event_queue, &ev0);
            telaMenu(reiniciar);
            if(reiniciar){
                reiniciar = false;
                goto INICIO;
                break;
            }
            al_flip_display();
        }

        INICIO:
        Save->read_save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Chave, Relogio, Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);

        /* === NÍVEL UM === */
        // Neste nível, o jogador tem a batalha contra o pistoleiro Billy, em frente ao Saloon. Não há NPCs 
        // no mapa para passar missões.
        al_stop_samples();
        al_play_sample(ambient_song13, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        Player->addAtaque("Revólver", 1, 4);
        dano_revolver="A: (01/04)";

        Billy->addAtaque("Tiro de Revólver", 0, -2);
        Billy->addAtaque("Cura", 0, 1);

        al_start_timer(timer);

        Nivel1->_etapa = 1;
        ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);

        setNivel(Player, 1, Missao_Espingarda, Missao_Chave, Missao_Pocao, Missao_Relogio);
        Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
        Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
        while(Player->getNivel()==1){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()) break; 
            if(ev0.type == ALLEGRO_EVENT_TIMER){  
                resetGame();
                if(reiniciar){
                    reiniciar = false;
                    goto INICIO;
                }

                redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                    !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
                desenhaObjetivos();
                minimap();

                al_flip_display();
            }
        }

        // delete Billy;
        // Billy = nullptr;

        Player->addAtaque("Revólver", 2, 5);
        dano_revolver="A: (02/05)";
        if(!COQUETEL_MOLOTOV_USADO) Player->addAtaque("Coquetel Molotov", 10, 15);

        Xerife_Espeto->addAtaque("Tiro de Revólver", 0, -4);
        Xerife_Espeto->addAtaque("Espinhos", 0, -3);
        Xerife_Espeto->addAtaque("Cura", 0, 2);

        /* === NÍVEL DOIS === */
        // Neste nível, o jogador tem a batalha contra o Xerife Espeto, no deserto. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.

        al_stop_samples();
        al_play_sample(ambient_song24, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        Nivel2->_etapa = 1;
        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);

        setNivel(Player, 2, Missao_Espingarda, Missao_Chave, Missao_Pocao, Missao_Relogio);
        Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
        Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
        while(Player->getNivel()==2){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()) break; 
            if(ev0.type == ALLEGRO_EVENT_TIMER){  
                redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                    !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
                desenhaObjetivos();
                minimap();

                resetGame();
                if(reiniciar){
                    reiniciar = false;
                    goto INICIO;
                }

                al_flip_display();
            }
        }


        // delete Xerife_Espeto;
        // Xerife_Espeto = nullptr;
        Player->addAtaque("Revólver", 2, 6);
        dano_revolver="A: (02/06)";
        Player->addAtaque("Shurikens", 3, 4);

        Geraldina->addAtaque("Garras", 0, -7);
        Geraldina->addAtaque("Mordida", 0, -2);
        Geraldina->addAtaque("Cura", 0, 3);

        /* === NÍVEL TRÊS === */
        // Neste nível, o jogador tem a batalha contra Geraldina, no rancho. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.  
        al_stop_samples();
        al_play_sample(ambient_song13, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        Nivel3->_etapa = 1;
        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);

        setNivel(Player, 3, Missao_Espingarda, Missao_Chave, Missao_Pocao, Missao_Relogio);
        if(Player->getNivel() == 3) Player->addItem("Estrela de Xerife", 1);
        Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
        Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
        while(Player->getNivel()==3){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()){
                if(Nivel3->_etapa == 2) Player->setDinheiro(Player->getDinheiro() - 10);
                break;
            } 
            if(ev0.type == ALLEGRO_EVENT_TIMER){  
                redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                    !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
                desenhaObjetivos();
                minimap();

                resetGame();
                if(reiniciar){
                    reiniciar = false;
                    goto INICIO;
                }

                al_flip_display();
            }
        }

        // delete Geraldina;
        // Geraldina = nullptr;

        /* === NÍVEL QUATRO === */
        // Neste nível, o jogador tem a batalha contra José do Caixão e o Caixão do josé, na igreja. 
        // Estão presentes todos os NPCs no mapa para passar missões.

        al_stop_samples();
        al_play_sample(ambient_song24, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        Player->addAtaque("Revólver", 2, 7);
        dano_revolver="A: (02/07)";
        if(!PE_DE_COELHO_USADO) Player->addAtaque("Pé de Coelho", 0, 0);

        Jose_do_Caixao->addAtaque("Tiro de Revólver", 0, -5);
        Jose_do_Caixao->addAtaque("Pá", 0, -1);
        Jose_do_Caixao->addAtaque("Cura", 0, 3);

        Caixao_do_Jose->addAtaque("Mordida Fúnebre", 0, -3);
        Caixao_do_Jose->addAtaque("Pá", 0, -1);
        Caixao_do_Jose->addAtaque("Cura", 0, 60);

        Nivel4->_etapa = 1;
        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);

        setNivel(Player, 4, Missao_Espingarda, Missao_Chave, Missao_Pocao, Missao_Relogio);
        Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
        Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
        while(Player->getNivel()==4){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()) break; 
            if(ev0.type == ALLEGRO_EVENT_TIMER){  
                redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                    !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
                desenhaObjetivos();
                minimap();

                resetGame();
                if(reiniciar){
                    reiniciar = false;
                    goto INICIO;
                }

                al_flip_display();
            }
        }

        // delete Jose_do_Caixao;
        // Jose_do_Caixao = nullptr;
        // delete Caixao_do_Jose;
        // Caixao_do_Jose = nullptr;

        /* === NÍVEL CINCO === */
        // Neste nível, o jogador tem a batalha contra Johnny Cash, na cabana. Estão presentes 
        // todos os NPCs no mapa para passar missões.

        al_stop_samples();
        al_play_sample(ambient_song5, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        Player->addAtaque("Munições Fanstasma", 2, 8);
        dano_revolver="A: (02/08)";

        Johnny_Cash->addAtaque("Assombração", 0, -15);
        Johnny_Cash->addAtaque("Desafinação", 0, -3);
        Johnny_Cash->addAtaque("Tiro espectral", 0, -4);
        Johnny_Cash->addAtaque("Cura", 0, 5);

        Nivel5->_etapa = 1;
        ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);

        setNivel(Player, 5, Missao_Espingarda, Missao_Chave, Missao_Pocao, Missao_Relogio);
        Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
        Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
        Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
        while(Player->getNivel()==5){
            al_wait_for_event(event_queue, &ev0);

            if(!to_move()){
                if(brinde) Player->subItem("Comida", 5);
                break; 
            }
            if(ev0.type == ALLEGRO_EVENT_TIMER){  
                redesenhar(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                    !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
                desenhaObjetivos();
                minimap();

                resetGame();
                if(reiniciar){
                    reiniciar = false;
                    goto INICIO;
                }

                al_flip_display();
            }
        }

         /* === NÍVEL SEIS === */
         //tela e dialogos finais
         al_stop_samples();
         al_play_sample(ending_song, 0.6, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

        if(Player->getNivel() == 6){
            dialogoFinal(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);
            Final(reiniciar);
            Save->reset_save();
            if(reiniciar){
                reiniciar = false;
                goto MENU;
            }
        }

        // delete Johnny_Cash;
        // Johnny_Cash = nullptr;
    }

    Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
    if(Player != nullptr) delete Player;
    if(Billy != nullptr) delete Billy;
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
                Player->curarVida(5); //aumenta um ponto de vida
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

    if(Player->getNivel() == 5 && !brinde){
        dialogoLoja->dialogar_lojista_brinde(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
            !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
        brinde = true;
    }
    else
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
            Missao_Pocao->finish();
            MAPA[13][30] = '0';
        }

        else if(Missao_Pocao->getinicializada() == true && Player->qtdItem("Pocao") == 1 && Player->getNivel() == 5){
            dialogoMissaoPocaoPt2Level5(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4->completo()), contGalinha, Player, Botao_Interagir);
            Player->subItem(Pocao->getNome(), 1);
            Missao_Pocao->finish();
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

    else if(Missao_Espingarda->missaoProxima('C') && Nivel4->_etapa > 1){
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

    else if(Nivel5->missaoProxima('3') && (Player->getNivel() > 1 || Nivel1->_etapa > 1)){
        dialogoCesarJulio(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
            !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);
    }

    else if(Player->getNivel() == 1){
        if(Nivel1->missaoProxima('3') && Nivel1->_etapa == 1){
            dialogoNivel1Pt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Nivel1->_etapa++;
            MAPA[29][40] = 'A'; // Adiciona Billy/Ambrósio na matriz
            ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
        }
        else if(Nivel1->missaoProxima('A') && Nivel1->_etapa == 2){
            dialogoNivel1Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            al_stop_samples();
            al_play_sample(battle1_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
            fadeout();
            resetTeclas();
            Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
            if(Batalha_Nivel1.batalhar()){
                Player->nextLevel();
                ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
                Player->setVida(Player->getVida()+10);
            }
            al_stop_samples();
        }
    }

    else if(Player->getNivel() == 2){
        if(Nivel2->missaoProxima('A') && Nivel2->_etapa == 1){
            dialogoNivel2Pt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Nivel2->_etapa++;
            MAPA[28][76] = 'J'; // Adiciona Renato na matriz
            MAPA[29][40] = '0'; // Adiciona Ambrósio na matriz
            ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
        }
        else if(Nivel2->missaoProxima('J') && Nivel2->_etapa == 2){
            dialogoNivel2Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Nivel2->_etapa++;
            MAPA[56][70] = MAPA[56][71] = MAPA[57][70] = MAPA[57][71] = 'B'; // Adiciona Xerife Espeto na matriz
            MAPA[28][76] = '0'; // Remove Renato da matriz
            ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
        }
        else if(Nivel2->missaoProxima('B') && Nivel2->_etapa == 3){
            dialogoNivel2Pt3(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            al_stop_samples();
            al_play_sample(battle2_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
            fadeout();
            resetTeclas();
            Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
            if(Batalha_Nivel2.batalhar()){
                Player->nextLevel();
                ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
                Player->setVida(Player->getVida()+10);
                if(!Player->hasAtaque("Coquetel Molotov")) COQUETEL_MOLOTOV_USADO = true;
            }
            al_stop_samples();
        }
    }

    else if(Player->getNivel() == 3){
        if(Nivel3->missaoProxima('J') && Nivel3->_etapa == 1){
            dialogoNivel3Pt1(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            Player->subItem("Estrela de Xerife", 1);
            Nivel3->_etapa++;
            MAPA[49][16] = MAPA[49][17] = 'C'; // Adiciona Geraldina na matriz
            MAPA[28][76] = '0'; // Remove Renato da matriz
            ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
        }
        else if(Nivel3->missaoProxima('C') && Nivel3->_etapa == 2){
            dialogoNivel3Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            al_stop_samples();
            al_play_sample(battle3_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
            fadeout();
            resetTeclas();
            Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
            if(Batalha_Nivel3.batalhar()){
                Player->nextLevel();
                Player->setVida(Player->getVida()+10);
                if(!Player->hasAtaque("Coquetel Molotov")) COQUETEL_MOLOTOV_USADO = true;
            }
            al_stop_samples();
        } 
    }

    else if(Player->getNivel() == 4){
        if(Nivel4->missaoProxima('C') && Nivel4->_etapa == 1){
            dialogoNivel4Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            MAPA[27][88] = MAPA[28][88] = MAPA[27][89] = 'D';
            Nivel4->_etapa++;
            ajuda_cesar = atualizaCesarJulio(Player, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5);
        }
        else if(Nivel4->missaoProxima('D') && Nivel4->_etapa == 2){
            BATALHA_JOSE = true;
            dialogoNivel4Pt3(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            al_stop_samples();
            al_play_sample(battle4_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
            fadeout();
            resetTeclas();
            Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
             if(Batalha_Nivel4.batalhar()){
                Player->nextLevel();
                Player->setVida(Player->getVida()+10);
                if(!Player->hasAtaque("Coquetel Molotov")) COQUETEL_MOLOTOV_USADO = true;
                if(!Player->hasAtaque("Pé de Coelho")) PE_DE_COELHO_USADO = true;
             }
             al_stop_samples();
        }
    }

    else if(Player->getNivel() == 5){
        if(Nivel5->missaoProxima('E')){
            dialogoNivel5Pt2(!Relogio->completo(), !Chave->completo(), !Pocao->completo(), !(Dinheiro1->completo()), 
                !(Dinheiro2->completo()), !(Dinheiro3->completo()), !(Dinheiro4 != NULL), contGalinha, Player, Botao_Interagir);

            al_stop_samples();
            al_play_sample(battle5_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
            fadeout();
            resetTeclas();
            Save->save(Player, Missao_Espingarda, Missao_Chave, Missao_Relogio, Missao_Pocao, Dinheiro1, Dinheiro2, Dinheiro3, Dinheiro4);
            if(Batalha_Nivel5.batalhar()){
                Player->nextLevel();
                Player->setVida(Player->getVida()+10);
                if(!Player->hasAtaque("Coquetel Molotov")) COQUETEL_MOLOTOV_USADO = true;
                if(!Player->hasAtaque("Pé de Coelho")) PE_DE_COELHO_USADO = true;
            }
            al_stop_samples();
        }
    }
    Lista->atualizaPrincipal(Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, Player);
    Lista->atualizaSecundaria(Missao_Espingarda, Missao_Relogio, Missao_Chave, Missao_Pocao, Player);
}

void resetGame(){
    if(Player->isDead()){
        al_stop_samples();
        al_play_sample(death_song, 0.8, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

        Player->setVida(Player->getMaxVida());
        telaGameOver(reiniciar);
    }
}


void desenhaObjetivos(){
    if(keys[ALLEGRO_KEY_O]){
        int posicao = 17;
    
        al_draw_scaled_bitmap(objetivos_fundo, 0, 0, 1920, 1080, 0, 0, RES_WIDTH(1920), RES_HEIGHT(1080), 0);
        al_draw_textf(font13, al_map_rgb(58,15,43), RES_WIDTH(40), RES_HEIGHT(7*posicao), 0, "MISSÕES PRINCIPAIS");
        posicao+=5;
        al_draw_textf(font13, al_map_rgb(58,15,43), RES_WIDTH(40), RES_HEIGHT(7*posicao), 0, Lista->getPrincipal().c_str());
        posicao+=10;
        al_draw_textf(font13, al_map_rgb(58,15,43), RES_WIDTH(40), RES_HEIGHT(7*posicao), 0, "MISSÕES SECUNDÁRIAS");
        posicao+=5;
        for(int i = 0; i < Lista->getTotalSecundarias(); i++){
            al_draw_textf(font13, al_map_rgb(58,15,43), RES_WIDTH(40), RES_HEIGHT(7*posicao), 0, Lista->getSecundaria(i).c_str());
            posicao+=5;
        }  
    }
}
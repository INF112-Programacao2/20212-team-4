#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Save.hpp"
#include <math.h>

#define RES_WIDTH(i) \
    i*(res_x_comp/1920.0)

#define RES_HEIGHT(j) \
    j*(res_y_comp/1080.0)

/* PERSONAGENS  */
Protagonista *Player = new Protagonista(10, 3);
Inimigo *Silvio = new Inimigo("Silvio", 12, 3, 2);
Inimigo *Xerife_Espeto = new Inimigo("Xerife Espeto", 24, 4, 4);
Inimigo *Jose_do_Caixao = new Inimigo("Jose do caixao", 32, 4, 3);
Inimigo *Caixao_do_Jose = new Inimigo("Caixao do Jose", 15, 2, 1);
Inimigo *Geraldina = new Inimigo("Geraldina", 45, 4, 3);
Inimigo *Johnny_Cash = new Inimigo("Johnny Cash", 60, 4, 5);

/* ITENS */
Interacao *Chave = new Interacao("chave", 81, 70, '5');
Interacao *Relogio = new Interacao("relogio", 84, 32, '6');
Interacao *Pocao = new Interacao("pocao", 1, 4, '7');
Interacao *Dinheiro1 = new Interacao("dinheiro1", 3, 14, '8');
Interacao *Dinheiro2 = new Interacao("dinheiro2", 78, 19, '8');
Interacao *Dinheiro3 = new Interacao("dinheiro3", 2, 46, '8');
Interacao *Dinheiro4 = new Interacao("dinheiro4", 68, 67, '8');

/* FUNCOES */
bool camera(char mov);
void set_true(bool vetor[], int n);
void set_false(bool vetor[]);
void redesenhar(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, long long int c);
bool to_move();
void galinha();
void itens();
void interagir();

/* VARIAVEIS */
bool movimento[4] = {false};
long long int cont = 0;
ALLEGRO_EVENT ev0;
short int contGalinha = 0;

int main(int argc, char **argv){

    /* COMECANDO A EXECUCAO DO JOGO*/
    if(inicializaJogo()){
        
        if(Player->getNivel()==1){
            //variável, começa a dar zoom, começa a dar zoom, largura, altura, até onde vai, até onde vai, escala, escala, 0
            al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            al_draw_scaled_bitmap(player_f1, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);
            al_flip_display();
        }

        /* === NÍVEL UM === */
        // Neste nível, o jogador tem a batalha contra o pistoleiro Silvio, em frente ao Saloon. Não há NPCs 
        // no mapa para passar missões.

        while(Player->getNivel()==1){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move())return 0;   
            galinha();
            al_flip_display();
        }

        delete Silvio;

        /* === NÍVEL DOIS === */
        // Neste nível, o jogador tem a batalha contra o Xerife Espeto, no deserto. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.        

        while(Player->getNivel()==2){
            al_wait_for_event(event_queue, &ev0);
            galinha();
            if(!to_move())return 0;   
            al_flip_display();  
        }

        delete Xerife_Espeto;

        /* === NÍVEL TRÊS === */
        // Neste nível, o jogador tem a batalha contra Geraldina, no rancho. Estão presentes todos
        // os NPCs no mapa para passar missões, porém, ainda não é possível completar a missão da espingarda.  

        while(Player->getNivel()==3){
            al_wait_for_event(event_queue, &ev0);
            galinha();
            if(!to_move())return 0;   
            al_flip_display();
        }

        delete Geraldina;

        /* === NÍVEL QUATRO === */
        // Neste nível, o jogador tem a batalha contra José do Caixão e o Caixão do josé, na igreja. 
        // Estão presentes todos os NPCs no mapa para passar missões.

        while(Player->getNivel()==4){
            al_wait_for_event(event_queue, &ev0);
            galinha();
            if(!to_move())return 0;   
            al_flip_display();  
        }

        delete Jose_do_Caixao;
        delete Caixao_do_Jose;

        /* === NÍVEL QUATRO === */
        // Neste nível, o jogador tem a batalha contra Johnny Cash, na cabana. Estão presentes 
        // todos os NPCs no mapa para passar missões.

        while(Player->getNivel()==5){
            al_wait_for_event(event_queue, &ev0);
            galinha();
            if(!to_move())return 0;   
            al_flip_display();  
        }

        delete Johnny_Cash;

    }

    return 0;
}

/*FUNCAO QUE ATRIBUI TRUE A DIRECAO QUE O PLAYER QUER SE MOVIMENTAR*/
void set_true(bool vetor[], int n){
    if(n==0){
        vetor[0]=true;
        vetor[1]=false;
        vetor[2]=false;
        vetor[3]=false;
    }
    else if(n==1){
        vetor[0]=false;
        vetor[1]=true;
        vetor[2]=false;
        vetor[3]=false;
    }
    else if(n==2){
        vetor[0]=false;
        vetor[1]=false;
        vetor[2]=true;
        vetor[3]=false;
    }
    else if(n==3){
        vetor[0]=false;
        vetor[1]=false;
        vetor[2]=false;
        vetor[3]=true;
    }
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
        if(camI == 11){
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

/*FUNCAO QUE ATRIBUI FALSE A TODAS AS POSICOES DO VETOR*/
void set_false(bool vetor[4]){
    vetor[0]=false;
    vetor[1]=false;
    vetor[2]=false;
    vetor[3]=false;
}

/*FUNCAO QUE REDESENHA O MAPA, O PERSONAGEM E OS ITENS*/
void redesenhar(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, long long int c){
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);
    itens();
    
    if(c%2==0)
        al_draw_scaled_bitmap(img1, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
            RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);
    else 
        al_draw_scaled_bitmap(img2, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
            RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);
    
}

/*FUNCAO QUE FAZ A MOVIMENTACAO DO PERSONAGEM*/
bool to_move(){
    if(ev0.type == ALLEGRO_EVENT_TIMER){
        //if(redraw && al_is_event_queue_empty(event_queue)){}
        if(movimento[0]){//movimento para cima
            if(MAPA[i][j] == '1' && camera('C')){
                i--;
                EIXO_Y_PLAYER_TELA -= 16*ZOOM;
            }
            cont++;
            redesenhar(player_c1, player_c2, cont);
        }
        else if(movimento[1]){//movimento para esquerda
            if(MAPA[i+1][j-1] == '1' && camera('E')){
                j--;
                EIXO_X_PLAYER_TELA -= 16*ZOOM;          

            } cont++;
            redesenhar(player_e1, player_e2, cont);
        }
        else if(movimento[2]){//movimento para baixo
            if(MAPA[i+2][j] == '1' && camera('B')){
                i++;
                EIXO_Y_PLAYER_TELA += 16*ZOOM;

            } cont++;
            redesenhar(player_f1, player_f2, cont);
        }
        else if(movimento[3]){//movimento para direita
            if(MAPA[i+1][j+1] == '1' && camera('D')){
                j++;
                EIXO_X_PLAYER_TELA += 16*ZOOM;

            } cont++;
            redesenhar(player_d1, player_d2, cont);
        }

    }
    else if(ev0.type == ALLEGRO_EVENT_KEY_DOWN){
        switch (ev0.keyboard.keycode){
            case ALLEGRO_KEY_ESCAPE:{
                return false;
            }                   
            case ALLEGRO_KEY_W:{
                set_true(movimento, 0);                   
                break;
            }
            case ALLEGRO_KEY_A:{
                set_true(movimento, 1);
                break;
            }
            case ALLEGRO_KEY_S:{
                set_true(movimento, 2);
                break;
            }
            case ALLEGRO_KEY_D:{
                set_true(movimento, 3);
                break;
            }
            case ALLEGRO_KEY_E:{
                interagir();
                break;
            }
        };
    }
    else if(ev0.type == ALLEGRO_EVENT_KEY_UP){
        //faz com que obrigatoriamente o personagem pare com o pé abaixado
        if(movimento[0]) redesenhar(player_c1, player_c2, 0);
        else if(movimento[1]) redesenhar(player_e1, player_e2, 0);
        else if(movimento[2]) redesenhar(player_f1, player_f2, 0);
        else if(movimento[3]) redesenhar(player_d1, player_d2, 0);
        set_false(movimento);
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
    /*
    switch(contGalinha){
        case 0:
            al_draw_scaled_bitmap(galinha1, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 1:
            al_draw_scaled_bitmap(galinha2, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 2:
            al_draw_scaled_bitmap(galinha3, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha++;
            break;
        case 3:
            al_draw_scaled_bitmap(galinha4, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
            contGalinha = 0;
            break;
    }
    */

}

/* FUNCAO PARA COLETAR O ITEM */
void interagir(){
    if(Relogio->itemProximo('1'))
        Player->addItem(Relogio->getNome(), 1);

    else if(Chave->itemProximo('1'))
        Player->addItem(Chave->getNome(), 1);
    
    else if(Pocao->itemProximo('1'))
        Player->addItem(Pocao->getNome(), 1);
    
    else if(Dinheiro1->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro1;
        Dinheiro1 = nullptr;
    }
    
    else if(Dinheiro2->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro2;
        Dinheiro2 = nullptr;
    }   
    
    else if(Dinheiro3->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro3;
        Dinheiro3 = nullptr;
    }
    
    else if(Dinheiro4->itemProximo('1')){
        Player->setDinheiro(Player->getDinheiro()+10);
        delete Dinheiro4;
        Dinheiro4 = nullptr;
    }
}


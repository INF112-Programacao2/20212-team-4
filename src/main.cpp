#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "data.hpp"
#include <ctime>

/* PERSONAGENS  */
Protagonista Player(10, 3);
Inimigo Ambrosio("Ambrosio", 12, 3, 2);
Inimigo Xerife_Espeto("Xerife Espeto", 24, 4, 4);
Inimigo Jose_do_Caixao("Jose do caixao", 32, 4, 3);
Inimigo Caixao_do_Jose("Caixao do Jose", 15, 2, 1);
Inimigo Geraldina("Geraldina", 45, 4, 3);
Inimigo Silvio("Silvio", 60, 4, 5);

/* FUNCOES */
void set_true(bool vetor[], int n);
void set_false(bool vetor[]);
void redesenhar(int posx, int posy, ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, long long int c);
bool to_move();

/* VARIAVEIS */
bool movimento[4] = {false};
long long int cont = 0;
ALLEGRO_EVENT ev0;

int main(int argc, char **argv){

/* COMECANDO A EXECUCAO DO JOGO*/

    if(inicializaJogo()){
        //variável, começa a dar zoom, começa a dar zoom, largura, altura, até onde vai, até onde vai, escala, escala, 0
        al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);
        al_draw_scaled_bitmap(player_f1, 0, 0, res_x_player, res_y_player, EIXO_X_PLAYER+115, EIXO_Y_PLAYER+120, res_x_player*(res_x_comp/1920.0)*ZOOM, res_y_player*(res_y_comp/1080)*ZOOM , 0);
        al_flip_display();

        while(Player.getNivel()==1){
            al_wait_for_event(event_queue, &ev0);
            if(!to_move())return 0;   
        }

    }
//Destrutores das variáveis
	al_destroy_display(game);
    al_destroy_bitmap(map);
    al_destroy_bitmap(player_f1);
    al_destroy_bitmap(player_c1);
    al_destroy_bitmap(player_d1);
    al_destroy_bitmap(player_e1);
    al_destroy_bitmap(player_f2);
    al_destroy_bitmap(player_c2);
    al_destroy_bitmap(player_d2);
    al_destroy_bitmap(player_e2);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
 
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

/*FUNCAO QUE ATRIBUI FALSE A TODAS AS POSICOES DO VETOR*/
void set_false(bool vetor[]){
    vetor[0]=false;
    vetor[1]=false;
    vetor[2]=false;
    vetor[3]=false;
}

/*FUNCAO QUE REDESENHA O MAPA E O PERSONAGEM*/
void redesenhar(int posx, int posy, ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, long long int c){
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, res_x_comp*(res_x_comp/1920.0)*ZOOM, res_y_comp*(res_y_comp/1080.0)*ZOOM, 0);

    if(c%2==0)
        al_draw_scaled_bitmap(img1, 0, 0, res_x_player, res_y_player, posx+115, posy+120, res_x_player*(res_x_comp/1920.0)*ZOOM, res_y_player*(res_y_comp/1080)*ZOOM, 0);
    else 
        al_draw_scaled_bitmap(img2, 0, 0, res_x_player, res_y_player, posx+115, posy+120, res_x_player*(res_x_comp/1920.0)*ZOOM, res_y_player*(res_y_comp/1080)*ZOOM, 0);

    al_flip_display();
}

/*FUNCAO QUE FAZ A MOVIMENTACAO DO PERSONAGEM*/
bool to_move(){
    if(ev0.type == ALLEGRO_EVENT_TIMER){
        //if(redraw && al_is_event_queue_empty(event_queue)){}
        if(movimento[0]){//movimento para cima
            if(MAPA[i][j] == '1'){
                i--;
                TELA_Y_PLAYER -= ZOOM;
                EIXO_Y_PLAYER = TELA_Y_PLAYER*CELULA;

            } cont++;
            redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_c1, player_c2, cont);
        }
        else if(movimento[1]){//movimento para esquerda
            if(MAPA[i+1][j-1] == '1'){
                j--;
                TELA_X_PLAYER -= ZOOM;
                EIXO_X_PLAYER = TELA_X_PLAYER*CELULA;            

            } cont++;
            redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_e1, player_e2, cont);
        }
        else if(movimento[2]){//movimento para baixo
            if(MAPA[i+2][j] == '1'){
                i++;
                TELA_Y_PLAYER += ZOOM;
                EIXO_Y_PLAYER = TELA_Y_PLAYER*CELULA;

            } cont++;
            redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_f1, player_f2, cont);
        }
        else if(movimento[3]){//movimento para direita
            if(MAPA[i+1][j+1] == '1'){
                j++;
                TELA_X_PLAYER += ZOOM;
                EIXO_X_PLAYER = TELA_X_PLAYER*CELULA;

            } cont++;
            redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_d1, player_d2, cont);
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
        };
    }
    else if(ev0.type == ALLEGRO_EVENT_KEY_UP){
        //faz com que obrigatoriamente o personagem pare com o pé abaixado
        if(movimento[0]) redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_c1, player_c2, 0);
        else if(movimento[1]) redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_e1, player_e2, 0);
        else if(movimento[2]) redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_f1, player_f2, 0);
        else if(movimento[3]) redesenhar(EIXO_X_PLAYER, EIXO_Y_PLAYER, player_d1, player_d2, 0);
        set_false(movimento);
    }
    else if(ev0.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        return false;
    }

	

    return true;
}
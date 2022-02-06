#include "Personagens.hpp"
/* CAMPO DE BIBLIOTECAS ALLEGRO */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define ZOOM 4
#define FPS 8
#define CELULA 16
#define res_x_player 16 
#define res_y_player 32

/* VARIÁVEIS ALLEGRO */
extern ALLEGRO_DISPLAY *game; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
extern ALLEGRO_EVENT_QUEUE *event_queue; // Declarando a fila de enventos 
extern ALLEGRO_BITMAP  *map; // Variável que vai receber uma imagem
extern ALLEGRO_BITMAP *player_f1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_f2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_TIMER *timer; //Declarando o temporizador do jogo

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
extern unsigned char MAPA[][97];
extern unsigned char CAMERA[][23];
extern short int camI;
extern short int camJ;
extern short int valueIJcam;
extern short int res_x_comp;
extern short int res_y_comp;
extern short int j; //posicao do personagem na matriz
extern short int i; //posicao do personagem na matriz

// Tamanho de uma célula do mapa.
extern const short int TELA_ALT;
extern const short int TELA_LARG;
extern bool redraw;

// Posição atual do player
extern short int EIXO_X_PLAYER_TELA;
extern short int EIXO_Y_PLAYER_TELA;
extern double TELA_X_MAPA;
extern double TELA_Y_MAPA;

/**
 * @brief tenta inicializar todas as variáveis Allegro que serão utilizadas. 
 * Caso consiga, retorna true.
 * 
 */
bool inicializaJogo();

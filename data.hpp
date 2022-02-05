#include "Personagens.hpp"
/* CAMPO DE BIBLIOTECAS ALLEGRO */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/* VARIÁVEIS ALLEGRO */
extern ALLEGRO_DISPLAY *game; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
extern ALLEGRO_EVENT_QUEUE *event_queue; // Declarando a fila de enventos 
extern ALLEGRO_BITMAP  *map; // Variável que vai receber uma imagem
extern ALLEGRO_TIMER *timer; //Declarando o temporizador do jogo

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
extern unsigned char MAPA[][200];

// Tamanho de uma célula do mapa.
extern const short int TELA_ALT;
extern const short int TELA_LARG;
extern const short int x;
extern const short int y;
extern const float FPS;
extern bool redraw;

// Posição atual do player
extern short int EIXO_X_PLAYER;
extern short int EIXO_Y_PLAYER;

/**
 * @brief tenta inicializar todas as variáveis Allegro que serão utilizadas. 
 * Caso consiga, retorna true.
 * 
 */
bool inicializaJogo();

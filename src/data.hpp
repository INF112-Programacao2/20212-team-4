#ifndef DATA_HPP
#define DATA_HPP

#include "Personagens.hpp"
#include "Missoes.hpp"
/* CAMPO DE BIBLIOTECAS ALLEGRO */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define ZOOM 4
#define FPS 8
#define CELULA 16
#define res_x_player 16 
#define res_y_player 32

#define RES_WIDTH(i) \
    i*(res_x_comp/1920.0)

#define RES_HEIGHT(j) \
    j*(res_y_comp/1080.0)

/* VARIÁVEIS ALLEGRO */
extern ALLEGRO_DISPLAY *game; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
extern ALLEGRO_EVENT_QUEUE *event_queue; // Declarando a fila de enventos 
extern ALLEGRO_BITMAP *map; // Variável que vai receber uma imagem
extern ALLEGRO_BITMAP *general_player; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *parado; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_f1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_f2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_f3; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c3; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d3; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e3; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_f4; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_c4; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_d4; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *player_e4; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *img1; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *img2; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *img3; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *img4; //variavel que vai receber a imagem do personagem
extern ALLEGRO_BITMAP *dano_costas; //variavel que vai receber a imagem do personagem recebendo dano
extern ALLEGRO_BITMAP *dano_frente; //variavel que vai receber a imagem do personagem recebendo dano
extern ALLEGRO_BITMAP *dano_direita; //variavel que vai receber a imagem do personagem recebendo dano
extern ALLEGRO_BITMAP *dano_esquerda; //variavel que vai receber a imagem do personagem recebendo dano
extern ALLEGRO_TIMER *timer; //Declarando o temporizador do jogo
extern ALLEGRO_BITMAP *relogio; //variavel que vai receber a imagem do relogio
extern ALLEGRO_BITMAP *relogiohud; // variavel que vai receber a imagem do relogio do hud
extern ALLEGRO_BITMAP *chave; //variavel que vai receber a imagem da chave
extern ALLEGRO_BITMAP *chavehud; //variavel que vai receber a imagem da chave do hud
extern ALLEGRO_BITMAP *espingarda; //variavel que vai receber a imagem da espingarda do hud
extern ALLEGRO_BITMAP *pocaohud; //variavel que vai receber a imagem da pocao do hud
extern ALLEGRO_BITMAP *frango; //variavel que vai receber a imagem do frango
extern ALLEGRO_BITMAP *pocao; //variavel que vai receber a imagem da poção
extern ALLEGRO_BITMAP *dinheiro1; //variavel que vai receber a imagem do saco de dinheiro
extern ALLEGRO_BITMAP *dinheiro2; //variavel que vai receber a imagem do saco de dinheiro
extern ALLEGRO_BITMAP *dinheiro3; //variavel que vai receber a imagem do saco de dinheiro
extern ALLEGRO_BITMAP *dinheiro4; //variavel que vai receber a imagem do saco de dinheiro
extern ALLEGRO_BITMAP *galinha1; //variavel que vai receber a imagem das galinhas
extern ALLEGRO_BITMAP *galinha2; //variavel que vai receber a imagem das galinhas
extern ALLEGRO_BITMAP *galinha3; //variavel que vai receber a imagem das galinhas
extern ALLEGRO_BITMAP *galinha4; //variavel que vai receber a imagem das galinhas
extern ALLEGRO_BITMAP *galinha4; //variavel que vai receber a imagem das galinhas
extern ALLEGRO_BITMAP *botaointeracao; // variavel que vai receber a imagem do botao de interacao
extern ALLEGRO_BITMAP *botaocomer; // variavel que vai receber a imagem do botao para comer
extern ALLEGRO_BITMAP *fundo; // variavel que vai receber a imagem do fundo da barra de vida
extern ALLEGRO_BITMAP *lifebar; // variavel que vai receber a imagem da barra de vida
extern ALLEGRO_BITMAP *contorno; // variavel que vai receber a imagem do contorno da barra de vida
extern ALLEGRO_FONT *font15;  // variavel que vai receber a fonte do hud
extern ALLEGRO_FONT *font10;  // variavel que vai receber a fonte do hud
extern bool keys[ALLEGRO_KEY_MAX];
extern ALLEGRO_BITMAP *caixa_texto;
extern ALLEGRO_BITMAP *game_over1; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over2; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over3; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over4; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over5; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over6; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over7; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over8; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over9; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over10; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over11; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *game_over12; //variavel que vai receber a imagem do game over
extern ALLEGRO_BITMAP *botaoreiniciar; // variavel que vai receber o botao para reiniciar


/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
extern unsigned char MAPA[][97];
extern std::string CAMERA[10];
extern short int camI;
extern short int camJ;
extern short int valueIJcam;
extern short int res_x_comp;
extern short int res_y_comp;
extern short int j; //posicao do personagem na matriz
extern short int i; //posicao do personagem na matriz
extern bool reiniciar;

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
void resetCamera(short int x, short int y);
void resetTeclas();

void dialogoMissaoChavesPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao);
void dialogoMissaoChavesPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoChavesExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoPocaoPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao);
void dialogoMissaoPocaoPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoPocaoPt2Level5(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoPocaoExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoEspingardaPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao);
void dialogoMissaoEspingardaPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoEspingardaPt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoEspingardaExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoEspingardaExtra2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoRelogioPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao);
void dialogoMissaoRelogioPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoMissaoRelogioPt2Extra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel1Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel1Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel2Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel2Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel2Pt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel3Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel3Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel4Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel4Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);

#endif
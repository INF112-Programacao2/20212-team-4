#ifndef DATA_HPP
#define DATA_HPP

#include "Personagens.hpp"
#include "Missoes.hpp"
#include "AllegroElementsException.hpp"
/* CAMPO DE BIBLIOTECAS ALLEGRO */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define ZOOM 4
#define FPS 8
#define CELULA 16
#define res_x_player 16 
#define res_y_player 32

#define RES_WIDTH(i) \
    i*(res_x_comp/1920.0)

#define RES_HEIGHT(j) \
    j*(res_y_comp/1080.0)

extern std::string dano_revolver;

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
extern ALLEGRO_FONT *font13;  // variavel que vai receber a fonte do hud
extern bool keys[ALLEGRO_KEY_MAX]; // variavel que vai armazenar quais teclas foram apertadas
extern ALLEGRO_BITMAP *caixa_texto; // variavel que vai receber a imagem da caixa de texto
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
extern ALLEGRO_BITMAP *icone; // variavel que vai receber os icones dos dialogos
extern ALLEGRO_BITMAP *icone_player; // variavel que vai receber o icone do personagem
extern ALLEGRO_BITMAP *mini_map; // variavel que vai receber o minimapa
extern ALLEGRO_BITMAP *player_minimap; // variavel que vai receber o personagem no minimapa
extern ALLEGRO_BITMAP *portao; // variavel que vai receber o portao do rancho
extern ALLEGRO_BITMAP *botaoreiniciar;   // variavel que vai receber o botao para reiniciar
extern bool PE_DE_COELHO_USADO; // variavel que armazena se o pe de coelho foi utilizado
extern bool COQUETEL_MOLOTOV_USADO; // variavel que armazena se o coquetel molotov foi utilizado
extern ALLEGRO_BITMAP *player_batalha;   // imagem do jogador para a batalha
extern ALLEGRO_BITMAP *billy_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *espeto_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *geraldina_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *jose_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *caixao_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *fantasma_batalha;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *player_dano;   // imagem do jogador para a batalha
extern ALLEGRO_BITMAP *billy_dano;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *espeto_dano;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *geraldina_dano;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *jose_dano;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *caixao_dano;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *espeto_morto;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *geraldina_morta;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *jose_morto;   // imagem do inimigo para a batalha
extern ALLEGRO_BITMAP *caixa_de_ataques; // opcoes de ataque
extern ALLEGRO_BITMAP *ataques;          // ataques
extern ALLEGRO_BITMAP *vida_player;      // vida do protagonista   
extern ALLEGRO_BITMAP *vida_vilao;       // vida do vilao
extern ALLEGRO_BITMAP *base_fantasma;  // base do fantasma na batalha
extern ALLEGRO_BITMAP *menu;  // tela inicial
extern ALLEGRO_BITMAP *titulo;  // titulo da tela inicial
extern ALLEGRO_BITMAP *mapmenu;  // mapa da tela inicial
extern ALLEGRO_BITMAP *tela_fundo; // imagem da tela de fundo da batalha
extern ALLEGRO_FONT *font_titulo; // fonte do titulo
extern ALLEGRO_FONT *fontataques; // fonte dos ataques
extern ALLEGRO_BITMAP *caixa_nome; //imagem da caixa com o nome
extern ALLEGRO_BITMAP *estrela; // estrela do hud
extern ALLEGRO_BITMAP *lifebar_batalhas; //barra de vida das batalhas
extern ALLEGRO_SAMPLE *ambient_song13; // musica de ambientacao do niveis 1 e 3
extern ALLEGRO_SAMPLE *ambient_song24; // musica de ambientacao do niveis 2 e 4
extern ALLEGRO_SAMPLE *ambient_song5; // musica de ambientacao do nivel 5
extern ALLEGRO_SAMPLE *ending_song; // musica de ambientacao do final
extern ALLEGRO_SAMPLE *battle1_song; // musica da batalha 1
extern ALLEGRO_SAMPLE *battle2_song; // musica da batalha 2
extern ALLEGRO_SAMPLE *battle3_song; // musica da batalha 3
extern ALLEGRO_SAMPLE *battle4_song; // musica da batalha 4
extern ALLEGRO_SAMPLE *battle5_song; // musica da batalha 5
extern ALLEGRO_SAMPLE *highwayman; // musica tema do jogo
extern ALLEGRO_SAMPLE *type_sound; //indica o que deve ser tocado
extern ALLEGRO_SAMPLE *death_song; // musica de morte
extern ALLEGRO_BITMAP *carregar; //tela de carregamento
extern ALLEGRO_SAMPLE *desafinacao1; //som do ataque desafinacao
extern ALLEGRO_SAMPLE *desafinacao2; //som do ataque desafinacao
extern ALLEGRO_SAMPLE *desafinacao3; //som do ataque desafinacao
extern bool BATALHA_JOSE;
extern const char *ajuda_cesar; //indica qual dica o cesar julio irá dizer
extern ALLEGRO_BITMAP *telaFinal; //imagem da tela do final
extern ALLEGRO_BITMAP *botaosair; // variavel que vai receber o botao para sair
extern ALLEGRO_BITMAP *aperteM; // variavel que vai receber o botao para abrir o mapa
extern ALLEGRO_BITMAP *aperteO; // variavel que vai receber o botao para abrir os objetivos
extern ALLEGRO_BITMAP *img_vilao; // variavel que vai receber a imagem do vilao
extern ALLEGRO_BITMAP *img_vilao_dano; // variavel que vai receber a imagem do vilao tomando dano
extern ALLEGRO_FONT *font_faixas; //fonte das faixas
extern ALLEGRO_BITMAP *objetivos_fundo; // imagem de fundo da tela dos objetivos

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
extern double EIXO_X_MINIMAP;
extern double EIXO_Y_MINIMAP;
extern double TELA_X_MAPA;
extern double TELA_Y_MAPA;

/**
 * @brief tenta inicializar todas as variáveis Allegro que serão utilizadas. 
 * Caso consiga, retorna true.
 * 
 */
bool inicializaJogo();
void setNivel(Protagonista *Player, int nivel, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4);
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
void dialogoNivel4Pt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel5Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoNivel5Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
const char *atualizaCesarJulio(Protagonista *player, Missao *n1, Missao *n2, Missao *n3, Missao *n4, Missao *n5);
void dialogoCesarJulio(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);
void dialogoFinal(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao);

#endif
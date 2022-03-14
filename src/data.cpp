#include <iostream>
#include "data.hpp"

/* VARIÁVEIS ALLEGRO */
ALLEGRO_DISPLAY *game = NULL; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Declarando a fila de enventos 
ALLEGRO_BITMAP *map = NULL; // Variável que vai receber uma imagem
ALLEGRO_BITMAP *mini_map = NULL; // Variável que vai receber uma imagem
ALLEGRO_BITMAP *general_player = NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *parado = NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_f1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_f2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_f3= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c3= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d3= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e3= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_f4= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c4= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d4= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e4= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *img1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *img2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *img3= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *img4= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *dano_costas= NULL; //variavel que vai receber a imagem do personagem recebendo dano
ALLEGRO_BITMAP *dano_frente= NULL; //variavel que vai receber a imagem do personagem recebendo dano
ALLEGRO_BITMAP *dano_direita= NULL; //variavel que vai receber a imagem do personagem recebendo dano
ALLEGRO_BITMAP *dano_esquerda= NULL; //variavel que vai receber a imagem do personagem recebendo dano
ALLEGRO_TIMER *timer = NULL; //Declarando o temporizador do jogo
ALLEGRO_BITMAP *relogio = NULL; //variavel que vai receber a imagem do relogio
ALLEGRO_BITMAP *relogiohud = NULL; // variavel que vai receber a imagem do relogio do hud
ALLEGRO_BITMAP *chavehud = NULL; // variavel que vai receber a imagem da chave do hud
ALLEGRO_BITMAP *espingarda = NULL; // variavel que vai receber a imagem da espingarda do hud
ALLEGRO_BITMAP *pocaohud = NULL; // variavel que vai receber a imagem da pocao do hud
ALLEGRO_BITMAP *frango = NULL; // variavel que vai receber a imagem do frango do hud
ALLEGRO_BITMAP *chave = NULL; //variavel que vai receber a imagem da chave
ALLEGRO_BITMAP *pocao = NULL; //variavel que vai receber a imagem da poção
ALLEGRO_BITMAP *dinheiro1 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro2 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro3 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro4 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *galinha1 = NULL; //variavel que vai receber a imagem das galinhas
ALLEGRO_BITMAP *galinha2 = NULL; //variavel que vai receber a imagem das galinhas
ALLEGRO_BITMAP *galinha3 = NULL; //variavel que vai receber a imagem das galinhas
ALLEGRO_BITMAP *galinha4 = NULL; //variavel que vai receber a imagem das galinhas
ALLEGRO_BITMAP *botaointeracao = NULL; // variavel que vai receber a imagem do botao de interacao
ALLEGRO_BITMAP *botaocomer = NULL; // variavel que vai receber a imagem do botao para comer
ALLEGRO_BITMAP *fundo = NULL; // variavel que vai receber a imagem do fundo da barra de vida
ALLEGRO_BITMAP *lifebar = NULL; // variavel que vai receber a imagem da barra de vida
ALLEGRO_BITMAP *contorno = NULL; // variavel que vai receber a imagem do contorno da barra de vida
ALLEGRO_BITMAP *caixa_texto = NULL;
ALLEGRO_FONT *font15 = NULL; // variavel que vai receber a fonte do hud
ALLEGRO_FONT *font10 = NULL; 
ALLEGRO_FONT *font_titulo = NULL;
bool keys[ALLEGRO_KEY_MAX] = {0};
ALLEGRO_BITMAP *game_over1 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over2 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over3 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over4 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over5 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over6 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over7 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over8 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over9 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over10 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over11 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *game_over12 = NULL; //variavel que vai receber a imagem do game over
ALLEGRO_BITMAP *botaoreiniciar = NULL; // variavel que vai receber o botao para reiniciar
ALLEGRO_BITMAP *icone = NULL; // variavel que vai receber o botao para reiniciar
ALLEGRO_BITMAP *icone_player = NULL; // variavel que vai receber o botao para reiniciar
ALLEGRO_BITMAP *player_minimap = NULL;
ALLEGRO_BITMAP *portao = NULL;
ALLEGRO_BITMAP *player_batalha = NULL; // imagem do jogador para a batalha
ALLEGRO_BITMAP *billy_batalha = NULL; // imagem do inimigo para a batalha
ALLEGRO_BITMAP *fundo_batalha = NULL;  // tela de batalha
ALLEGRO_BITMAP *caixa_de_ataques = NULL; // opcoes de ataque
ALLEGRO_BITMAP *ataques = NULL;          // ataques
ALLEGRO_BITMAP *vida_player = NULL;      // vida do protagonista   
ALLEGRO_BITMAP *vida_vilao = NULL;       // vida do vilao
ALLEGRO_BITMAP *base = NULL;  // base do personagem na batalha
ALLEGRO_BITMAP *menu = NULL;  // tela inicial
ALLEGRO_BITMAP *titulo = NULL;  // titulo da tela inicial
ALLEGRO_BITMAP *mapmenu = NULL;  // mapa da tela inicial
ALLEGRO_BITMAP *tela_fundo = NULL;  // base do personagem na batalha
ALLEGRO_BITMAP *caixa_nome = NULL;

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
unsigned char MAPA[][97]=
{
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"000001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"000011111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"110011100011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111110000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111110000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000010000010000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000110000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011110110000111111111111110000000000000000000000000000000000000000000000000000000000000",
"111100000011111110000111111111111111000000000000000000000000000000000000000000000000000000000000",
"000000000011111111111111111111111111000000000000000000000000000000000000000000000000000000000000",
"100011111111110110000111111111111111000000000000000000000000000000000000000000000000000000000000",
"111111111100101110000111111111111111111111111111111111111111111111111111111111111111110000001110",
"111111111111011100000111111111111111111111111111111111111111111111111111111111111111110000001110",
"000000000000111000000111111111111111111111111111110000011111111111111111000000111111110000001110",
"000000000000000000000111111111111111110000011111000000000111111111111111000000111111110000001110",
"000000000000000000000111111111111100000000000001000000000110000011000000000000111111110000001110",
"000000000000000000001111111111111100000000000001000000000000000001000000000000111111110000001110",
"000000000000000000011111111111111100000000000001000000000000000001000000000000111111110000001110",
"111111111111111111111111111111111100000000000001000000000000000001000000000000111110000000000000",
"111111111111111111111111111111111100000000000001000000000000000001000000000000111110110000000000",
"000000000000000000000000111111111100000000000001000000000000000001000000000000111110111111110000",
"000000000000000000000000000111111100000000000001000000000000033301000000000000111110000011000000",
"000000000000000000000000000011111111100000001111111000111111133311111111111111111110000011000000",
"000000000000000000000000000011111111111101111111111111111111111111111111111111111110111111111100",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111000000",
"000000000000000000000000000011111111111111111111111111111000000000000000000000111110111111000000",
"000000000000000000000000000011110000000110000011110000000000000000000000000000111110111100000000",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000000",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000000",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000000",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000000",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111111111111111110",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111111111111111110",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000011111110001111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000011111100000001111111111111111111111111111111111111111111111111111110",
"111001111111110000000000111111111100000000111111111111111111111111111111111111111111111111111110",
"1110011111111100000000001111111111000zzzzz*11111111111111111111111111111111111111111111111111110",
"111111111111110000000000111111111110011111*11111111111111111111111111111111111111111111111111110",
"100000000000000000000000001111111111111111111111111111111111111111111111111111111111111111111110",
"100000000000000000000000001111111111111111111111111111111111**1111111111111111111111111111111110",
"101111111111111111111111101111111111111111*11111111111111111*11111111111111111111*11111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111*11111111111111111*11111111111111111111*11110",
"10111111111111111111111110111111111111111111111111111111111111111111**11111111111111111111111110",
"1011111111111111111111111011111111111**1111111111111111111111111111111111111**111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111*11111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"10111111111111111111111110111111111111111111111***11111111111111111111111*111111111111***1111110",
"1011111111111111111111111011111111111111111111111*11111111111111111011111*10111111111111*1111110",
"101111111111111111111111101111111111111111111111111111111111111111110000000111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111**1111111111111111111111111111111111111**1111111111110",
"10111111111111111111111110111111111111111111111111111111111**11111111111111111111111111111111110",
"10111111111111101110111110111111111111*1111111111111111111111111111111111111*1111111111111111110",
"1011111111111110111011111011111111111**111111111*11111111111111111111111111**1111111111111111110",
"10000000000000001110000000111111111111111111111111111111111111111111*111111111111111111*11111110",
"1111111111111111111111111111111111111111111111111111111111111111111*1111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"1111111111111111111111111111111****1111111111111111111111111111111111111111111111111111111111110",
"11111111111111111111111111111111***1111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
};

std::string CAMERA[10] = {
    "111111111111111111111",
    "100000000000000000001",
    "100000000000000000001",
    "100000000000000000001",
    "100000000000000000001",
    "1000000000000P0000001",
    "100000000000000000001",
    "100000000000000000001",
    "100000000000000000001",
    "1111111111111111111111"
};
short int camI = 4;
short int camJ = 13;
short int valueIJcam = '0';
bool reiniciar = false;

// Tamanho de uma célula do mapa.
bool redraw = true;
short int res_x_comp;//tamando do personagem em pixels
short int res_y_comp;//tamando do personagem em pixels

// Posição atual do player
short int j = 69; //posicao do personagem na matriz
short int i = 29; //posicao do personagem na matriz

short int EIXO_X_PLAYER_TELA;
short int EIXO_Y_PLAYER_TELA;
double EIXO_X_MINIMAP;
double EIXO_Y_MINIMAP;
double TELA_X_MAPA = 56;
double TELA_Y_MAPA = 23;

bool inicializaJogo() {
    if(!al_init()){
        std::cout << "Falha ao carregar Allegro" << std::endl;
        return false;
    }

    if(!al_install_keyboard()){
        std::cout << "Falha ao inicializar o teclado" << std::endl;
        return false;
    }

    timer = al_create_timer(1.0/FPS);
    if(!timer){
        std::cout << "Falha ao inicializar o temporizador" << std::endl;
        return false;
    }

    if(!al_init_image_addon()){
        std::cout <<"Falha ao iniciar al_init_image_addon!" << std::endl;
        return false;
    }

    ALLEGRO_MONITOR_INFO info;
    al_get_monitor_info(0, &info);
    res_x_comp = info.x2 - info.x1;
    res_y_comp = info.y2 - info.y1;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    game = al_create_display(res_x_comp, res_y_comp);
    if(!game){
        std::cout << "Falha ao inicializar a tela" << std::endl;
        al_destroy_timer(timer);
        
        return false;
    }

    event_queue = al_create_event_queue();
    if(!event_queue){
        std::cout << "Falha ao criar a fila de eventos" << std::endl;
        al_destroy_display(game);
        al_destroy_timer(timer);

        return false;
    }

    map= al_load_bitmap("./../assets/map1.bmp");
    if(!map){
        std::cout << "Falha ao carregar o mapa" << std::endl;
        al_destroy_display(game);
        return false;
    }

    mini_map = al_load_bitmap("./../assets/map.bmp");
    if(!mini_map){
        std::cout << "Falha ao carregar o mini mapa" << std::endl;
        al_destroy_display(game);
        return false;
    }

    player_minimap = al_load_bitmap("./../assets/player_minimap.bmp");
    if(!player_minimap){
        std::cout << "Falha ao carregar o personagem do mini mapa" << std::endl;
        al_destroy_display(game);
        return false;
    }

    al_init_font_addon();
	al_init_ttf_addon();

    
    font15 = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(75), 0);
    if(!font15)
    {
        std::cout << "Falha ao inicializar a fonte" << std::endl;
        return false;
    }

    font10 = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(50), 0);
    if(!font10)
    {
        std::cout << "Falha ao inicializar a fonte" << std::endl;
        return false;
    }

    font_titulo = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(150), 0);
    if(!font_titulo)
    {
        std::cout << "Falha ao inicializar a fonte" << std::endl;
        return false;
    }

    //atribuindo as imagens do personagem as variaveis
    player_f1=al_load_bitmap("./../assets/frente1.bmp");
    general_player = player_f1;
    parado = player_f1;
    botaocomer=al_load_bitmap("./../assets/aperteF.bmp");
    player_c1=al_load_bitmap("./../assets/costas1.bmp");
    player_d1=al_load_bitmap("./../assets/direita1.bmp");
    player_e1=al_load_bitmap("./../assets/esquerda1.bmp");
    player_f2=al_load_bitmap("./../assets/frente2.bmp");
    player_c2=al_load_bitmap("./../assets/costas2.bmp");
    player_d2=al_load_bitmap("./../assets/direita2.bmp");
    player_e2=al_load_bitmap("./../assets/esquerda2.bmp");
    player_f3=al_load_bitmap("./../assets/frente3.bmp");
    player_c3=al_load_bitmap("./../assets/costas3.bmp");
    player_d3=al_load_bitmap("./../assets/direita3.bmp");
    player_e3=al_load_bitmap("./../assets/esquerda3.bmp");
    player_f4=al_load_bitmap("./../assets/frente4.bmp");
    player_c4=al_load_bitmap("./../assets/costas4.bmp");
    player_d4=al_load_bitmap("./../assets/direita4.bmp");
    player_e4=al_load_bitmap("./../assets/esquerda4.bmp");
    dano_costas=al_load_bitmap("./../assets/dano-costas.bmp");
    dano_direita=al_load_bitmap("./../assets/dano-direita.bmp");
    dano_esquerda=al_load_bitmap("./../assets/dano-esquerda.bmp");
    dano_frente=al_load_bitmap("./../assets/dano-frente.bmp");
    caixa_de_ataques=al_load_bitmap("./../assets/batalha/caixa_ataques.bmp"); 
    ataques=al_load_bitmap("./../assets/batalha/ataques.bmp");          
    vida_player=al_load_bitmap("./../assets/batalha/vida-player.bmp");         
    vida_vilao=al_load_bitmap("./../assets/batalha/vida-vilao.bmp");
    base=al_load_bitmap("./../assets/batalha/base-pistoleiro.bmp");
    player_batalha=al_load_bitmap("./../assets/batalha/player-batalha.bmp");        
    billy_batalha=al_load_bitmap("./../assets/batalha/billy-batalha.bmp"); 

    //atribuindo as imagens das batalhas

    player_batalha = al_load_bitmap("./../assets/batalha/player-batalha.bmp"); // imagem do jogador para a batalha
    billy_batalha = al_load_bitmap("./../assets/batalha/pistoleiro.bmp"); // imagem do inimigo para a batalha
   


    al_register_event_source(event_queue, al_get_display_event_source(game));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    EIXO_X_PLAYER_TELA = 1216;
    EIXO_Y_PLAYER_TELA = 572;

    EIXO_X_MINIMAP = 1280;
    EIXO_Y_MINIMAP = 462;

    /* ATRIBUINDO AS IMAGENS DOS ITENS AS RESPECTIVAS VARIAVEIS */
    relogio = al_load_bitmap("./../assets/relogio-map.bmp");
    if(!relogio){
        std::cout << "Falha ao carregar o relogio" << std::endl;
        al_destroy_display(game);
        return false;
    }

    relogiohud = al_load_bitmap("./../assets/relogio.bmp");
    if(!relogiohud){
        std::cout << "Falha ao carregar o relogio do hud" << std::endl;
        al_destroy_display(game);
        return false;
    }

    botaointeracao = al_load_bitmap("./../assets/aperteE.bmp");
    if(!botaointeracao){
        std::cout << "Falha ao carregar a imagem de interacao" << std::endl;
        al_destroy_display(game);
        return false;
    }

    chave = al_load_bitmap("./../assets/chave-map.bmp");
    if(!chave){
        std::cout << "Falha ao carregar a chave" << std::endl;
        al_destroy_display(game);
        return false;
    }

    chavehud = al_load_bitmap("./../assets/chave.bmp");
    if(!chavehud){
        std::cout << "Falha ao carregar a chave do hud" << std::endl;
        al_destroy_display(game);
        return false;
    }

    espingarda = al_load_bitmap("./../assets/espingarda.bmp");
    if(!espingarda){
        std::cout << "Falha ao carregar a espingarda" << std::endl;
        al_destroy_display(game);
        return false;
    }


    pocao = al_load_bitmap("./../assets/pocao-map.bmp");
    if(!pocao){
        std::cout << "Falha ao carregar a pocao" << std::endl;
        al_destroy_display(game);
        return false;
    }

    pocaohud = al_load_bitmap("./../assets/pocao.bmp");
    if(!pocaohud){
        std::cout << "Falha ao carregar a pocao" << std::endl;
        al_destroy_display(game);
        return false;
    }

    dinheiro1 = al_load_bitmap("./../assets/dinheiro1-map.bmp");
    if(!dinheiro1){
        std::cout << "Falha ao carregar o saco de dinheiro 1" << std::endl;
        al_destroy_display(game);
        return false;
    }

    dinheiro2 = al_load_bitmap("./../assets/dinheiro2-map.bmp");
    if(!dinheiro2){
        std::cout << "Falha ao carregar o saco de dinheiro 2" << std::endl;
        al_destroy_display(game);
        return false;
    }

    dinheiro3 = al_load_bitmap("./../assets/dinheiro3-map.bmp");
    if(!dinheiro3){
        std::cout << "Falha ao carregar o saco de dinheiro 3" << std::endl;
        al_destroy_display(game);
        return false;
    }

    dinheiro4 = al_load_bitmap("./../assets/dinheiro4-map.bmp");
    if(!dinheiro4){
        std::cout << "Falha ao carregar o saco de dinheiro 4" << std::endl;
        al_destroy_display(game);
        return false;
    }

    icone_player = al_load_bitmap("./../assets/icone-player.bmp");
    if(!icone_player){
        std::cout << "Falha ao carregar o icone do player" << std::endl;
        al_destroy_display(game);
        return false;
    }

    galinha1 = al_load_bitmap("./../assets/galinha1.bmp");
    if(!galinha1){
        std::cout << "Falha ao carregar a imagem 1 das galinhas" << std::endl;
        al_destroy_display(game);
        return false;
    }

    galinha2 = al_load_bitmap("./../assets/galinha2.bmp");
    if(!galinha2){
        std::cout << "Falha ao carregar a imagem 2 das galinhas" << std::endl;
        al_destroy_display(game);
        return false;
    }

    galinha3 = al_load_bitmap("./../assets/galinha3.bmp");
    if(!galinha3){
        std::cout << "Falha ao carregar a imagem 3 das galinhas" << std::endl;
        al_destroy_display(game);
        return false;
    }

    galinha4 = al_load_bitmap("./../assets/galinha4.bmp");
    if(!galinha4){
        std::cout << "Falha ao carregar a imagem 4 das galinhas" << std::endl;
        al_destroy_display(game);
        return false;
    }

    fundo = al_load_bitmap("./../assets/fundo_HUD.bmp");
    if(!fundo){
        std::cout << "Falha ao carregar o fundo da barra de vida" << std::endl;
        al_destroy_display(game);
        return false;
    }

    tela_fundo = al_load_bitmap("./../assets/fundo.bmp");
    if(!tela_fundo){
        std::cout << "Falha ao carregar o fundo da tela" << std::endl;
        al_destroy_display(game);
        return false;
    }

    caixa_nome = al_load_bitmap("./../assets/escrever_nome.bmp");
    if(!caixa_nome){
        std::cout << "Falha ao carregar o fundo da caixa de nome" << std::endl;
        al_destroy_display(game);
        return false;
    }

    lifebar = al_load_bitmap("./../assets/Life_bar.bmp");
    if(!lifebar){
        std::cout << "Falha ao carregar a barra de vida" << std::endl;
        al_destroy_display(game);
        return false;
    }

    contorno = al_load_bitmap("./../assets/HUD_contorno.bmp");
    if(!contorno){
        std::cout << "Falha ao carregar o contorno da barra de vida" << std::endl;
        al_destroy_display(game);
        return false;
    }

    frango = al_load_bitmap("./../assets/frango.bmp");
    if(!frango){
        std::cout << "Falha ao carregar o frango" << std::endl;
        al_destroy_display(game);
        return false;
    }

    caixa_texto = al_load_bitmap("./../assets/caixa_texto.bmp");
    if(!caixa_texto){
        std::cout << "Falha ao carregar o caixa_texto" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over1 = al_load_bitmap("./../assets/batalha/go1.bmp");
    if(!game_over1){
        std::cout << "Falha ao carregar o game_over1" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over2 = al_load_bitmap("./../assets/batalha/go2.bmp");
    if(!game_over2){
        std::cout << "Falha ao carregar o game_over2" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over3 = al_load_bitmap("./../assets/batalha/go3.bmp");
    if(!game_over3){
        std::cout << "Falha ao carregar o game_over3" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over4 = al_load_bitmap("./../assets/batalha/go4.bmp");
    if(!game_over4){
        std::cout << "Falha ao carregar o game_over4" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over5 = al_load_bitmap("./../assets/batalha/go5.bmp");
    if(!game_over5){
        std::cout << "Falha ao carregar o game_over5" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over6 = al_load_bitmap("./../assets/batalha/go6.bmp");
    if(!game_over6){
        std::cout << "Falha ao carregar o game_over6" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over7 = al_load_bitmap("./../assets/batalha/go7.bmp");
    if(!game_over7){
        std::cout << "Falha ao carregar o game_over7" << std::endl;
        al_destroy_display(game);
        return false;
    }

    portao = al_load_bitmap("./../assets/portao.bmp");
    if(!portao){
        std::cout << "Falha ao carregar o portao" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over8 = al_load_bitmap("./../assets/batalha/go8.bmp");
    if(!game_over8){
        std::cout << "Falha ao carregar o game_over8" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over9 = al_load_bitmap("./../assets/batalha/go9.bmp");
    if(!game_over9){
        std::cout << "Falha ao carregar o game_over9" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over10 = al_load_bitmap("./../assets/batalha/go10.bmp");
    if(!game_over10){
        std::cout << "Falha ao carregar o game_over10" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over11 = al_load_bitmap("./../assets/batalha/go11.bmp");
    if(!game_over11){
        std::cout << "Falha ao carregar o game_over11" << std::endl;
        al_destroy_display(game);
        return false;
    }

    game_over12 = al_load_bitmap("./../assets/batalha/go12.bmp");
    if(!game_over12){
        std::cout << "Falha ao carregar o game_over12" << std::endl;
        al_destroy_display(game);
        return false;
    }

    botaoreiniciar = al_load_bitmap("./../assets/enter.bmp");
    if(!botaoreiniciar){
        std::cout << "Falha ao carregar o botao de reiniciar" << std::endl;
        al_destroy_display(game);
        return false;
    }

    menu = al_load_bitmap("./../assets/home.bmp");
    if(!menu){
        std::cout << "Falha ao carregar o menu" << std::endl;
        al_destroy_display(game);
        return false;
    }

    titulo = al_load_bitmap("./../assets/titulo.bmp");
    if(!titulo){
        std::cout << "Falha ao carregar o titulo" << std::endl;
        al_destroy_display(game);
        return false;
    }

    mapmenu = al_load_bitmap("./../assets/map-menu.bmp");
    if(!mapmenu){
        std::cout << "Falha ao carregar o mapa do menu" << std::endl;
        al_destroy_display(game);
        return false;
    }

    return true;
}

void resetCamera(short int x, short int y){ //Reseta a camera ao passar de nível
    for(int i = 0; i < 10; i++){
        if(i == 0 || i == 9)
            CAMERA[i] = "111111111111111111111";
        else
            CAMERA[i] = "100000000000000000001";
    }

    CAMERA[y][x] = 'P';
    camJ = x;
    camI = y;
}

void resetTeclas(){
    keys[ALLEGRO_KEY_W] = false;
    keys[ALLEGRO_KEY_A] = false;
    keys[ALLEGRO_KEY_S] = false;
    keys[ALLEGRO_KEY_E] = false;
    keys[ALLEGRO_KEY_D] = false;
    keys[ALLEGRO_KEY_X] = false;
    keys[ALLEGRO_KEY_Z] = false;
    keys[ALLEGRO_KEY_M] = false;
    keys[ALLEGRO_KEY_SPACE] = false;
    keys[ALLEGRO_KEY_ESCAPE] = false;
}

void dialogoMissaoChavesPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (0, true));
    fluxo.insert(std::pair<short int, bool> (5, true));

    std::string **opcoes = new std::string*[2];
    opcoes[0] = new std::string[2] {"FECHADA? (Z)", "OK (X)"};
    opcoes[1] = new std::string[2] {"SIM (Z)", "NÃO (X)"};

    short int **incrementos = new short int*[2];
    incrementos[0] = new short int[2] {1, 8};
    incrementos[1] = new short int[2] {1, 2};

    icone = al_load_bitmap("./../assets/icone-cris.bmp");
    std::string *falas = new std::string [9] {
        "2Com licença, parceiro, a loja está fechada até segunda ordem. Caso precise de algo, abrimos uma venda na chegada da cidade.",
        "1O que houve?",
        "2Os invasores ocuparam nosso estoque. Quando sairam, deixamos alguns moradores lá dentro para ficarem seguros.",
        "2Fechamos a entrada principal e dos fundos. Agora, preciso entrar lá para ver se precisam de algo",
        "2Só que joguei a chave dos fundos no deserto, para não acharem. Agora eu que não me lembro onde está.",
        "2Acha que pode procurar por mim?",
        "1*Nobre de sua parte salvá-los, tentarei encontrar.",
        "1*Ir para o deserto não está nos meus agora planos.",
        "1*!OK."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("CRIS", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao))
        missao->setinicializadaTrue();
}

void dialogoMissaoChavesPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (2, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"SIM (Z)", "NÃO (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 2};

    icone = al_load_bitmap("./../assets/icone-cris.bmp");
    std::string *falas = new std::string [5] {
        "2Com licença, parceiro, a loja está... Ah, é o senhor. Conseguiu as chaves?",
        "1Aqui estão, cuidem bem deles.",
        "2Tome uma recompensa por acha-las.",
        "1*Obrigado.",
        "1*!Não se preocupe com isso.",
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("CRIS", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao))
        Player->setDinheiro(Player->getDinheiro() + 10);
}

void dialogoMissaoChavesExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-cris.bmp");
    std::string *falas = new std::string [2] {
        "2Conseguiu as chaves?",
        "1*Não."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CRIS", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoPocaoPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (4, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"O QUE? (Z)", "NÃO (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 5};

    icone = al_load_bitmap("./../assets/icone-bruxa.bmp");
    std::string *falas = new std::string [10]{ 
        "2",
        "1Como você sabe meu nome?",
        "2Você é bem conhecido pela região... Eu sou apenas... observadora...",
        "2Vejo no seu futuro, ",
        "2Mas, se me fizer um favor, acho que posso lhe ajudar.",
        "1O que você quer?",
        "2Eu deixei uma poção na cabana da floresta para um velho amigo... Mas estou precisando dela de novo.",
        "2Poderia pegar para mim? Lhe darei uma recompensa Muito útil.",
        "1*Vou tentar.",
        "1*!Eu não faço negócios com bruxas."
    };

    falas[0] += (Player->getNome() + "?");
    falas[3] += (Player->getNome() + ", assombrações... maldições!");

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao)){
        missao->setinicializadaTrue();
    }
}

void dialogoMissaoPocaoPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-bruxa.bmp");
    std::string *falas = new std::string [6] {
        "2Olá, ",
        "2Encontrou o que eu pedi?",
        "1Tome.",
        "2Muito obrigada, fique com isso. Para vencer as suas assombrações.",
        "1Munições?.",
        "2*Você saberá quando usar.",
    };

    falas[0] += (Player->getNome() + ".");

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoPocaoPt2Level5(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-bruxa.bmp");
    std::string *falas = new std::string [7] {
        "2Olá, ",
        "2Encontrou o que eu pedi?",
        "1Tome.",
        "2Muito obrigada, fique com isso. Para vencer as suas assombrações.",
        "1Munição contra fantasma.",
        "2Já conhecia?.",
        "1*Um amigo me apresentou."
    };

    falas[0] += (Player->getNome() + ".");

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoPocaoExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-bruxa.bmp");
    std::string *falas = new std::string [2] {
        "2Conseguiu a Poção?",
        "1*Não."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoEspingardaPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (7, true));
    fluxo.insert(std::pair<short int, bool> (10, true));

    std::string **opcoes = new std::string*[2];
    opcoes[0] = new std::string[2] {"DETALHES? (Z)", "TE AJUDO (X)"};
    opcoes[1] = new std::string[2] {"SIM (Z)", "NÃO (X)"};

    short int **incrementos = new short int*[2];
    incrementos[0] = new short int[2] {1, 4};
    incrementos[1] = new short int[2] {1, 7};

    icone = al_load_bitmap("./../assets/icone-andrew.bmp");
    std::string *falas = new std::string [18]{ 
        "2Malditos pistoleiros! Estão levando nosso dinheiro, nossas moças e nosso Whisky!",
        "2E o pior... Sem a Sandra ao meu lado, me sinto indefeso, como se faltasse uma parte de mim...",
        "1Sandra...? É a sua esposa?",
        "2Que esposa o que, garoto! Sandra Rosa é a minha espingarda!",
        "1E o que houve com ela?",
        "2Eu e um irmão estávamos no racho dele, quando o bando dos invasores nos abordaram.",
        "2Enquanto lutávamos por nossas vidas, um deles atirou nele e tive que soltar a Sandra para carregá-lo no colo e poder salvar ele...",
        "2Desde então, não o vejo mais nenhum dos dois.",
        "1E com o quê praticavam tiro ao alvo?",
        "2Ahm... Isso não vem ao caso, garoto...", 
        "2Mas... Fiquei sabendo que você foi chamado para ajudar a cidade contra aqueles bandidos. Pode me ajudar a encontrar a Sandra?",
        "1Eu posso te ajudar.",
        "2Ótimo! Prometo lhe pagar uma boa recompensa.",
        "1E qual o nome do seu irmão?",
        "2Mario.",
        "1Que Mario?",
        "2*Mario Victor, o rancheiro da cidade.",
        "1*Eu tenho mais o que fazer!"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("ANDREW", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    missao->setinicializadaTrue();
}

void dialogoMissaoEspingardaPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (3, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"INVASORES? (Z)", "OBRIGADO (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {2, 1};


    icone = al_load_bitmap("./../assets/icone-mario.bmp");
    std::string *falas = new std::string [11] {
        "1O senhor é o... Ahm... Mario?",
        "2Sim, senhor.",
        "1Seu irmão, Andrew, me pediu para que pegasse a... Sandra... com o senhor.",
        "2Ah, claro, tome aqui.",
        "1*Obrigado!",
        "1Obrigado! E... mais uma coisa. Seu irmão falou algo de invasores pelo seu rancho quando ele perdeu a espingarda.",
        "2Invasores? Que eu me lembre, só o coiote.",
        "1Disse que estavam praticando tiro ao alvo e eles chegaram para tomar sua coisas. Que ele salvou sua vida.",
        "2Hahahaha, ele inventa cada coisa. Ele apostou a espingarda no tiro ao alvo e perdeu. Mas ela não me serve de muito.",
        "1Mas ainda assim acabou que seu rancho foi invadido. Por que não usou a espingarda pra se defender?",
        "2*Eu sou contra a violência animal."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("MARIO VICTOR", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoEspingardaPt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (3, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"INFORMAÇÃO (Z)", "DINHEIRO (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {3, 1};


    icone = al_load_bitmap("./../assets/icone-andrew.bmp");
    std::string *falas = new std::string [10] {
        "1Aqui, consegui sua espingarda de volta.",
        "2Sandra, meu amor! Prometa que nunca mais vai se afastar de mim, viu?",
        "2Então, garoto. Te prometi uma recompensa... Tome.",
        "2Mas, antes, posso lhe dar esses trocados ou... uma informação... valiosa.",
        "1Eu acho que prefiro o dinheiro mesmo.",
        "2*Tome aqui, garoto. Faça bom uso.",
        "1Informação valiosa? Conte-me mais.",
        "2Boatos que alguns sacos de dinheiro estão espalhados pela região. Eu mesmo vi um! Mas sentia que alguém estava me seguindo.",
        "1Vou averiguar melhor, obrigado!",
        "2*!Tome aqui uma moeda, de qualquer forma. Pela Sandra."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("ANDREW", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao))
        Player->setDinheiro(Player->getDinheiro() + 10);
    else
        Player->setDinheiro(Player->getDinheiro() + 1);
}

void dialogoMissaoEspingardaExtra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-andrew.bmp");
    std::string *falas = new std::string {
        "2*Ah... Sandra... Que saudade d'ocê...",
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("ANDREW", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoEspingardaExtra2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-mario.bmp");
    std::string *falas = new std::string[2] {
        "2Aoba",
        "1*Opa"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("MARIO VICTOR", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoRelogioPt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao, MissaoSecundaria *missao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (7, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"OK (Z)", "NÃO (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 2};


    icone = al_load_bitmap("./../assets/icone-saul.bmp");
    std::string *falas = new std::string [10]{ 
        "2Ei! Você! Garoto!",
        "1Sim?",
        "2Você é o rapaz que foi chamado para dar uma lição nesses bandidos, não é?",
        "1Sim, precisa de algo?",
        "2Sabe, meu avô era um comerciante rico da cidade, um homem avarento. Levou tudo o que tinha para o túmulo.",
        "2Quando a cidade foi invadida, eu fui atrás do túmulo dele pra ver se havia algo de valor para vender e fugir daqui.",
        "2Consegui um relógio de ouro que carregava, mas os bandidos me encontraram. Tentei fugir, mas acabei deixando ele cair.",
        "2Caso esbarre nele, pode trazê-lo pra mim? Por favor, que seja o mais rápido possível!",
        "1*Vou ver o que posso fazer.",
        "1*!Eu tenho mais o que fazer."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("SAUL", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao)){
        missao->setinicializadaTrue();
    }
}

void dialogoMissaoRelogioPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-saul.bmp");
    std::string *falas = new std::string [4] {
        "1Encontrei o seu relógio. Agora você pode sair daqui.",
        "2Muito obrigado! Mesmo!",
        "2Para ti! Você merece isso! Muito obrigado! Agora... tenho que ir!",
        "2*Ah! E mais uma coisa. Cuidado com as redondezas, dizem que tem uma BRUXA morando por aí, próximo ao rio."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("SAUL", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoRelogioPt2Extra(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-saul.bmp");
    std::string *falas = new std::string [2] {
        "2Encontrou o Relógio?",
        "1*Não."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("SAUL", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}
void dialogoNivel1Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-cesar.bmp");
    std::string *falas = new std::string[12] {
        "2",
        "1Eu mesmo.",
        "2Prazer, César. O xerife me pediu para ser seu guia aqui na cidade durante o serviço.",
        "1E você fica aí à vista enquanto a cidade é invadida?",
        "2Ora, eu sou só uma iguana.",
        "1...",
        "2Então, o seu amigo xerife pediu para que você verificasse o saloon.",
        "1Primeiro que eu não exatamente que ele é meu amigo. Segundo, o que tem no saloon?",
        "2O saloon foi invadido por um dos pistoleiros, tomou o lugar do cervejeiro. Foi o primeiro golpe.",
        "2Os outros, não sabemos onde estão exatamente, devem estar escondidos.",
        "2Vencer ele talvez deixe alguns moradores mais livres para sair de casa.",
        "1*Vou ver o que posso fazer."
    };

    falas[0] += Player->getNome() + "! " + Player->getNome() + "!";

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CÉSAR JÚLIO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel1Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-billy.bmp");
    std::string *falas = new std::string[8] {
        "2Você! Vai pra casa! Estamos fazendo revista no estoque do saloon.",
        "1Eu não moro aqui.",
        "2Ah... Forasteiro... Lamento informar, mas a cidade está interditada.",
        "1Lamento informar, mas preciso que você se retire.",
        "2Isso é um convite para um duelo?",
        "1Estamos na frente de um saloon... É meio dia... Não é o que Hollywood te ensinou?",
        "2O que é Hollywood?",
        "1*Nada não."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("BILLY", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel2Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-cervejeiro.bmp");
    std::string *falas = new std::string[7] {
        "2Muito obrigado por salvar o meu saloon, eu te devo uma bebida. De graça! Por minha conta!",
        "1Não precisa se preocupar.",
        "2Mas tome isso, um coquetel Molotov! Ele é poderoso, mas use com responsabilidade, só tenho este",
        "1Obrigado.",
        "2Devo uma pro banqueiro também. Ele que pediu para que o xerife te chamasse.",
        "2Aliás, você deveria falar com ele a qualquer momento.",
        "1*Pode deixar"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("AMBRÓSIO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel2Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-cervejeiro.bmp");
    std::string *falas = new std::string[9] {
        "1Olá?",
        "2Você deve ser o ",
        "1As vezes.",
        "2É um prazer conhece-lo, mas terei que ser breve."
        "2Um dos invasores roubou a estrela do xerife e está passando por ele pela região.",
        "1E você sabe onde ele está?",
        "2Me informaram que ele foi encontrado soltando alguns bandidos pelo deserto.",
        "1Vou dar uma passada lá.",
        "2*Quando terminar de resolver, não esqueça de passar aqui para trazer o crachá."
    };

    falas[1] += Player->getNome() + ".";

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("AMBRÓSIO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel2Pt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (3, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"XERIFE? (Z)", "MENTIRA (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 8};


    icone = al_load_bitmap("./../assets/icone-xerife.bmp");
    std::string *falas = new std::string[12] {
        "2Oi, garoto! Eu estava indo agora mesmo resolver a invasão ao rancho.",
        "1Invasão ao rancho?",
        "2Ah, achei que morava por aqui. Não é nada, não. Nada a que se preocupe!"
        "1Então, o senhor é o xerife da cidade?",
        "2Isso mesmo. Agora, circulando, cidadão.",
        "1Calma, senhor! Como assim invasão?",
        "2Parece que um coiote invadiu o rancho. Deve ter cansado de procurar coelhos rápidos e foi atrás de galinhas.",
        "2Pode deixar que vou lidar com isso, tá. De novo, nada que o garoto precise se preocupar.",
        "1Eu acho que devo me preocupar, sim, e nós dois sabemos que você não e xerife nada.",
        "2*Droga!",
        "1Nós dois sabemos que você não é xerife de nada.",
        "2*Droga!"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("XERIFE ESPETO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel3Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-renato.bmp");
    std::string *falas = new std::string[9] {
        "1Aqui, a estrela do xerife.",
        "2Ótimo!",
        "2Aproveite e fique com essas estrelas falsas.",
        "1Pra que isso?"
        "2Você pode usar para atingir seus inimigos.",
        "1Ah, tipo uma shuriken ninja? Obrigado!",
        "2Seja lá o que isso for, sim.",
        "1Outra coisa, o cacto falou algo sobre uma invasão de um coiote a um rancho.",
        "2*Deve ser mais um deles, por que não vai lá ver?"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("RENATO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel3Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-geraldina.bmp");
    std::string *falas = new std::string[6] {
        "2Auuuuuu!!!",
        "1Ei, você! Deixa as galinhas em paz!",
        "2Auuuuuuuuuu!!!",
        "1Acho que não falamos a mesma língua."
        "2Na verdade, falamos, sim, mas assim fica mais dramático.",
        "2*E é na nossa língua que eu vou te mandar pra fora daqui.",
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("GERALDINA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel4Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-geraldina.bmp");
    std::string *falas = new std::string[9] {
        "1Onde tá o seu líder? Eu já perdi a paciência com o grupo de vocês.",
        "2Eu não sei.",
        "1Fala logo, lobinha. Eu não quero precisar duelar com você de novo.",
        "2Eu não sei!"
        "1Alguma coisa eu sei que você sabe.",
        "2O máximo que eu sei é que você pode ter mais informações com o coveiro.",
        "1Qual o nome do coveiro?",
        "2José...",
        "2*José do caixão."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("GERALDINA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel4Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-mario.bmp");
    std::string *falas = new std::string[4] {
        "2Pode deixar que eu cuido dela agora. Faz tempo que eu não faço um churrasco",
        "2Isso aqui estava com ela, um pé de coelho. Pode te trazer sorte. Imagino que um garoto não tenha o tiro tão preciso ainda",
        "1Ah, obrigado.",
        "2*É... Eu que agradeço"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("MÁRIO VICTOR", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}
void dialogoNivel4Pt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-coveiro.bmp");
    std::string *falas = new std::string[5] {
        "2Funerária Viçosa: Seu destino é aqui! O que precisa, cavalheiro?",
        "1Imagino que seja o tal José do Caixão.",
        "2Eu mesmo.",
        "1Blá blá blá, eu to aqui pra acabar com vocês, pipipi popopo, pega o revólver e vamos.",
        "2*Pessoal do roteiro  tá numa preguiça danada, hein."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("JOSÉ DO CAIXÃO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel5Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (2, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"JOHNNY? (Z)", "ONDE? (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 9};


    icone = al_load_bitmap("./../assets/icone-coveiro.bmp");
    std::string *falas = new std::string[15] {
        "1A coiote disse que você sabe quem começou isso tudo aqui.",
        "1É o fim da linha, parceiro. Quem é o líder disso tudo?",
        "2O nome dele é Johnny.",
        "1Quem diabos é Johnny?"
        "2Cash...",
        "1Não, pera, o cantor?",
        "2Sua alma estava há dias me assombrando, dizendo que queria voltar para este mundo.",
        "1E por que permitiu isso? Sua gangue aterrorizou toda a cidade, matou pessoas!",
        "2O meu caixãozinho... Ele estava tão triste... Há tempos não enterrava ninguém!",
        "1...",
        "2Eu fiz isso por ele! Só por ele...",
        "1E onde ele está?",
        "2Na cabana mal assombrada da floresta... Ele comandou isso tudo por lá.",
        "2Mas antes de ir... Tome isso... São munições especiais, contra fantasmas.",
        "1*Obrigado, José"
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("JOSÉ DO CAIXÃO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel5Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-fantasma.bmp");
    std::string *falas = new std::string[8] {
        "1Então, é você que tá orquestrando isso tudo.",
        "2E, se não fosse por você, meu plano estaria funcionando perfeitamente.",
        "1Agradeço o reconhecimento.",
        "1Mas qual o seu problema? Do nada sua alma resolve voltar pro mundo pra por terror numa vila?"
        "2Assim que eu atingi o outro lado, tentei encontrar um lugar pra descansar meu espírito, se eu conseguisse.",
        "2Mas eu nasci para ser um fora da lei e prometi que eu voltaria.",
        "2Não importava se como um forasteiro ou uma simples gota de chuva, mas eu voltaria pra esse mundo.",
        "1*Você vai voltar pra prisão de Folsom, Johnny."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("JOHNNY CASH", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

#include <iostream>
#include "data.hpp"

/* VARIÁVEIS ALLEGRO */
ALLEGRO_DISPLAY *game = NULL; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Declarando a fila de enventos 
ALLEGRO_BITMAP  *map = NULL; // Variável que vai receber uma imagem
ALLEGRO_BITMAP *player_f1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e1= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_f2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_c2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_d2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_BITMAP *player_e2= NULL; //variavel que vai receber a imagem do personagem
ALLEGRO_TIMER *timer = NULL; //Declarando o temporizador do jogo
ALLEGRO_BITMAP *relogio = NULL; //variavel que vai receber a imagem do relogio
ALLEGRO_BITMAP *chave = NULL; //variavel que vai receber a imagem da chave
ALLEGRO_BITMAP *pocao = NULL; //variavel que vai receber a imagem da poção
ALLEGRO_BITMAP *dinheiro1 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro2 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro3 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro
ALLEGRO_BITMAP *dinheiro4 = NULL; //variavel que vai receber a imagem dos sacos de dinheiro

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
unsigned char MAPA[][97]=
{
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"100001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"110011111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
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
"0000000000000000000000000000111111111000000011111111000111111333111111111111J1111111000011000000",
"0000000000000000000000000000111111111111A1111111111111111111111111111111111111111110111111111100",
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
"111001111111110000000000111111111100000444111111111111111111111111111111111111111111111111111110",
"111001111111110000000000111111111100000444011111111111111111111111111111111111111111111111111110",
"111111111111110000000000111111111110011111011111111111111111111111111111111111111111111111111110",
"100000000000000000000000001111111111111111111111111111111111111111111111111111111111111111111110",
"100000000000000000000000001111111111111111111111111111111111001111111111111111111111111111111110",
"101111111111111111111111101111111111111111011111111111111111011111111111111111111011111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111011111111111111111011111111111111111111011110",
"101111111111111111111111101111111111111111111111111111111111111111110011111111111111111111111110",
"101111111111111111111111101111111111100111111111111111111111111111111111111100111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111011111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111110001111111111111111111111111011111111110001111110",
"101111111111111111111111101111111111111111111111101111111111111111101111101011111111111101111110",
"101111111111111111111111101111111111111111111111111111111111111111110000000111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111110",
"101111111111111111111111101111111111111111001111111111111111111111111111111111111001111111111110",
"101111111111111111111111101111111111111111111111111111111110011111111111111111111111111111111110",
"101111111111111111111111101111111111110111111111111111111111111111111111111101111111111111111110",
"101111111111111211101111101111111111100111111111011111111111111111111111111001111111111111111110",
"100000000000000011100000001111111111111111111111111111111111111111110111111111111111111011111110",
"111111111111111111111111111111111111111111111111111111111111111111101111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111100001111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111110001111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110",
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
};

unsigned char CAMERA[][23] = {
    "1111111111111111111111",
    "1000000000000000000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "10000000000000P0000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "1000000000000000000001",
    "1111111111111111111111"
};
short int camI = 7;
short int camJ = 14;
short int valueIJcam = '0';

// Tamanho de uma célula do mapa.
bool redraw = true;
short int res_x_comp;//tamando do personagem em pixels
short int res_y_comp;//tamando do personagem em pixels

// Posição atual do player
short int j = 69; //posicao do personagem na matriz
short int i = 29; //posicao do personagem na matriz

short int EIXO_X_PLAYER_TELA;
short int EIXO_Y_PLAYER_TELA;
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

    map= al_load_bitmap("./../assets/map.bmp");
    if(!map){
        std::cout << "Falha ao carregar o mapa" << std::endl;
        al_destroy_display(game);
        return false;
    }

    //atribuindo as imagens do personagem as variaveis
    player_f1=al_load_bitmap("./../assets/frente1.bmp");
    player_c1=al_load_bitmap("./../assets/costas1.bmp");
    player_d1=al_load_bitmap("./../assets/direita1.bmp");
    player_e1=al_load_bitmap("./../assets/esquerda1.bmp");
    player_f2=al_load_bitmap("./../assets/frente2.bmp");
    player_c2=al_load_bitmap("./../assets/costas2.bmp");
    player_d2=al_load_bitmap("./../assets/direita2.bmp");
    player_e2=al_load_bitmap("./../assets/esquerda2.bmp");

    al_register_event_source(event_queue, al_get_display_event_source(game));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    EIXO_X_PLAYER_TELA = 1216;
    EIXO_Y_PLAYER_TELA = 572;


    /* ATRIBUINDO AS IMAGENS DOS ITENS AS RESPECTIVAS VARIAVEIS */
    relogio = al_load_bitmap("./../assets/relogio-map.bmp");
    if(!relogio){
        std::cout << "Falha ao carregar o relogio" << std::endl;
        al_destroy_display(game);
        return false;
    }

    chave = al_load_bitmap("./../assets/chave-map.bmp");
    if(!chave){
        std::cout << "Falha ao carregar a chave" << std::endl;
        al_destroy_display(game);
        return false;
    }

    pocao = al_load_bitmap("./../assets/pocao-map.bmp");
    if(!pocao){
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

    return true;
}

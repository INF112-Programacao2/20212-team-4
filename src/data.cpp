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

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.
unsigned char MAPA[][200]=
{"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"100001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"100001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"110011110011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111110000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111110000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000010000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011000110000000000000000000000000000000000000000000000000000000000000000000000000000000",
"111100000011110110000111111111111110000000000000000000000000000000000000000000000000000000000000",
"111300000011111110000111111111111111000000000000000000000000000000000000000000000000000000000000",
"000000000011111111111111111111111111000000000000000000000000000000000000000000000000000000000000",
"100011111111110110000111111111111111000000000000000000000000000000000000000000000000000000000000",
"111111111100101110000111111111111111111111111111111111111111111111111111111111111111110000001111",
"111111111111011100000111111111111111111111111111111111111111111111111111111111111111110000001111",
"000000000000111000000111111111111111111111111111110000011111111111111111000000311111110000001111",
"000000000000000000000111111111111100000000000001000000000111111111111111000000111111110000001111",
"000000000000000000000111111111111100000000000001000000000000000001000000000000111111110000001111",
"000000000000000000001111111111111100000000000001000000000000000001000000000000111111110000001111",
"000000000000000000011111111111111100000000000001000000000000000001000000000000111111110000001111",
"111111111111111111111111111111111100000000000001000000000000000001000000000000111110000000000001",
"111111111111111111111111111111111100000000000001000000000000000001000000000000111110110000000001",
"000000000000000000000000111111111100000020000001000000000000000001000000000000111110111111000001",
"000000000000000000000000000111111100000000000001000080000000000001000000000000111110000041000001",
"000000000000000000000000000011111111100000001111000000000000000001111111111111111110000011000001",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111110111111111101",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111000001",
"000000000000000000000000000011111111111111111111111111111000000000000000000000111110111111000001",
"000000000000000000000000000011110000000110000011110000000000000000000000000000111110611100000001",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000001",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000001",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000001",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111110000000000001",
"000000000000000000000000000011110000000100000000000000000000000000000000000000111111111111111111",
"00000000000000000000000000001111000000010000G000000000000000000000000000000000111111111111111111",
"000000000000000000000000000011111111111111111111111100011110001D11000111100011111111111111111111",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111111",
"000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111111",
"000000000000000000000000000011111110001111111111111111111111111111111111111111111111111111111111",
"000000000000000000000000000011111100000111111111111111111111111111111111111111111111111111111111",
"111001111111110000000000111111111100000000111111111111111111111111111111111111111111111111111111",
"111001111111110000000000111111111100000000011111111111111111111111111111111111111111111111111111",
"113111111111110000000000111111111110011111011111111111111111111111111111111111111111111111111111",
"100000000000000000000000001111111111111111111111111111111111111111111111111111111111111111111111",
"1000000000000000F0000000001111111111111111111111111111111111001111111111111111111111111111111111",
"1011111111111E111111111A101111111111111111011111111111111111011111111111111111111011111111111111",
"1011111E1111111111111111101111111111111111111111111111111111111111111111111111111111111111111111",
"1011111111111111111E1111101111111111111111111111111011111111111111111011111111111111111111011111",
"107111111111111111111111101111111111111111111111111111111111111111110011111111111111111111111111",
"101111111911111111111111101111111111100111111111111111111111111111111111111100111111111111111111",
"101111111111111711111111101111111111111111111111111111111111111111111111111111111111111111111111",
"10111E111111111111111911101111111111111111111111111111111011111111111111111111111111111111111111",
"1011111111111111111111111011111111111111111111111111111111111111111111B1111111111111111111111111",
"10111111111A111111111111101111111111111111111110001111111111111111111111101111111111110001111111",
"101111111111111111111111101111111111111111111111101111111111111111101111101011111111111101111111",
"101111711111111111E11111101111111111111111111111111111111111111111110000000111111111111111111111",
"101111111111911111111111101111111111111111111111111111111111111111111111111111111111111111111111",
"101911111111111111111111101111111111111111111111111111111111111111111111111111111111111111111111",
"101111111111111111111A11101111111111111111001111111111111111111111111111111111111001111111111111",
"10111111E111111111111111101111111111111111111111111111111110011111111111111111111111111111111111",
"101111111111171555551111101111111111110111111111111111111111111111111111111101111111111111111111",
"1011A1111111111511151111101111111111100111111111011111111111111111111111111001111111111111111111",
"100000000000000511150000001111111111111111111111111111111111111111110111111111111111111011111111",
"111111111111111111111111111111111111111111111111111111111111111111103111111111111111111111111111",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
"111111111111111111111111111111100001111111111111111111111111111111111111111111111111111111111111",
"111111111111111111111111111111110001111111111111111111111111111111111111111111111C11111111111111",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"};

// Tamanho de uma célula do mapa.
const short int x = 16;
const short int y = 16;
const float FPS = 10;
bool redraw = true;
int res_x_player=16;//tamando do personagem em pixels
int res_y_player=32;//tamando do personagem em pixels
int res_x_comp;
int res_y_comp;

// Posição atual do player
short int EIXO_X_PLAYER = 60*x;
short int EIXO_Y_PLAYER = 29*y;
short int j=60; //posicao do personagem na matriz
short int i=29; //posicao do personagem na matriz

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

    map= al_load_bitmap("map.bmp");
    if(!map){
        std::cout << "Falha ao carregar o mapa" << std::endl;
        al_destroy_display(game);
        return false;
    }

    //atribuindo as imagens do personagem as variaveis
    player_f1=al_load_bitmap("frente1.bmp");
    player_c1=al_load_bitmap("costas1.bmp");
    player_d1=al_load_bitmap("direita1.bmp");
    player_e1=al_load_bitmap("esquerda1.bmp");
    player_f2=al_load_bitmap("frente2.bmp");
    player_c2=al_load_bitmap("costas2.bmp");
    player_d2=al_load_bitmap("direita2.bmp");
    player_e2=al_load_bitmap("esquerda2.bmp");

    al_register_event_source(event_queue, al_get_display_event_source(game));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    return true;
}

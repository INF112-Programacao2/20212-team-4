#include <iostream>
#include "data.hpp"

/* VARIÁVEIS ALLEGRO */
ALLEGRO_DISPLAY *game = NULL; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Declarando a fila de enventos 
ALLEGRO_BITMAP  *map = NULL; // Variável que vai receber uma imagem
ALLEGRO_TIMER *timer = NULL; //Declarando o temporizador do jogo

/* VARIÁVEIS DE MOVIMENTAÇÃO */
// Matriz do mapa.


// Tamanho de uma célula do mapa.
const short int TELA_ALT = 1080;
const short int TELA_LARG = 1920;
const short int x = 16;
const short int y = 16;
const float FPS = 10;

// Posição atual do player
short int EIXO_X_PLAYER = 48*x;
short int EIXO_Y_PLAYER = 37*y;

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

    game = al_create_display(TELA_ALT, TELA_LARG);
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

    al_register_event_source(event_queue, al_get_display_event_source(game));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    return true;
}

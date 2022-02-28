#include <iostream>
#include "data.hpp"

/* VARIÁVEIS ALLEGRO */
ALLEGRO_DISPLAY *game = NULL; // ALLEGRO_DISPLAY é um tipo de variável que guarda uma janela a ser desenhada
ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Declarando a fila de enventos 
ALLEGRO_BITMAP *map = NULL; // Variável que vai receber uma imagem
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
bool keys[ALLEGRO_KEY_MAX] = {0};

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
"0000000000000000000000000000111111111000000011111111000111111333111111111111J1111110000011000000",
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
"111001111111110000000000111111111100000000111111111111111111111111111111111111111111111111111110",
"111001111111110000000000111111111100000zzz*11111111111111111111111111111111111111111111111111110",
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
"10111111111111111111111110111111111111*1111111111111111111111111111111111111*1111111111111111110",
"1011111111111112111011111011111111111**111111111*11111111111111111111111111**1111111111111111110",
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
    "1111111111111111111111",
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
short int camI = 5;
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

    return true;
}

void resetCamera(short int x, short int y){ //Reseta a camera ao passar de nível
    for(int i = 0; i < 10; i++){
        if(i == 0 || i == 9)
            CAMERA[i] = "1111111111111111111111";
        else
            CAMERA[i] = "1000000000000000000001";
    }

    CAMERA[y][x] = 'P';
    camJ = x;
    camI = y;
}

void inicializaMissaoEscopetaPt1(std::string *dialogo, bool *fluxo, short int **incremento, std::string *nomes, std::string **opcoes){
    dialogo = new std::string[17];
    nomes = new std::string[17];
    fluxo = new bool[17];
    incremento = new short int*[2];

    incremento[0] = new short int[2];
    incremento[0][0] = 1;
    incremento[0][1] = 9;

    incremento[1] = new short int[2];
    incremento[1][0] = 1;
    incremento[1][1] = 5;

    nomes[0] = "ANDREW";
    fluxo[0] = false;
    dialogo[0] = "Malditos pistoleiros! Estão levando nosso dinheiro, nossas moças e nosso Whisky!";
    nomes[1] = "ANDREW";
    fluxo[1] = false;
    dialogo[1] = "E o pior... Sem a Sandra ao meu lado, me sinto indefeso, como se faltasse uma parte de mim...";
    nomes[2] = "-";
    fluxo[2] = false;
    dialogo[2] = "Sandra...? É a sua esposa?";
    nomes[3] = "ANDREW";
    fluxo[3] = false;
    dialogo[3] = "Que esposa o que, garoto! Sandra Rosa é a minha espingarda!";
    nomes[4] = "-";
    fluxo[4] = false;
    dialogo[4] = "E o que houve com ela?";
    nomes[5] = "ANDREW";
    fluxo[5] = false;
    dialogo[5] = "Eu e um irmão estávamos praticando tiro ao alvo no racho dele, quando o bando de invasores nos abordaram.";
    nomes[6] = "ANDREW";
    fluxo[6] = false;
    dialogo[6] = "Enquanto lutávamos por nossas vidas, um deles atirou nele e tive que soltar a Sandra para carregá-lo no colo e poder salvar ele...";
    nomes[7] = "ANDREW";
    fluxo[7] = false;
    dialogo[7] = "Desde então, não os vejo mais. ";
    nomes[8] = "ANDREW";
    fluxo[8] = true;
    dialogo[8] = "Fiquei sabendo que você foi chamado para ajudar a cidade contra aqueles bandidos. Pode me ajudar a encontrar a Sandra?";
    nomes[9] = "-";
    fluxo[9] = false;
    dialogo[9] = "Claro.";
    nomes[10] = "ANDREW";
    fluxo[10] = false;
    dialogo[10] = "Ótimo! Prometo lhe pagar uma boa recompensa.";
    nomes[11] = "-";
    fluxo[11] = false;
    dialogo[11] = "Aliás, qual o nome de seu irmão?";
    nomes[12] = "ANDREW";
    fluxo[12] = true;
    dialogo[12] = "Mario";
    nomes[13] = "-";
    fluxo[13] = false;
    dialogo[13] = "Que Mario?";
    nomes[14] = "ANDREW";
    fluxo[14] = false;
    dialogo[14] = "Mario Victor, o rancheiro da cidade.";
    nomes[15] = "-";
    fluxo[15] = false;
    dialogo[15] = "*Vou falar com ele";
    nomes[16] = "-";
    fluxo[16] = false;
    dialogo[16] = "*Eu tenho mais o que fazer!";

    opcoes = new std::string*[2];
    opcoes[0] = new std::string[2];
    opcoes[0][0] = "SIM (Z)";
    opcoes[0][1] = "NÃO (X)";

    opcoes[1] = new std::string[2];
    opcoes[1][0] = "OK (Z)";
    opcoes[1][1] = "MARIO? (X)";
}

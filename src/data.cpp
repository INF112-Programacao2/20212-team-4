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
ALLEGRO_BITMAP *lifebar = NULL;
ALLEGRO_BITMAP *lifebar_batalhas = NULL; // variavel que vai receber a imagem da barra de vida
ALLEGRO_BITMAP *contorno = NULL; // variavel que vai receber a imagem do contorno da barra de vida
ALLEGRO_BITMAP *caixa_texto = NULL;
ALLEGRO_FONT *font15 = NULL; // variavel que vai receber a fonte do hud
ALLEGRO_FONT *font10 = NULL; 
ALLEGRO_FONT *font_faixas = NULL; 
ALLEGRO_FONT *font13 = NULL; 
ALLEGRO_FONT *font_titulo = NULL;
ALLEGRO_FONT *fontataques = NULL;
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
bool PE_DE_COELHO_USADO = false;
bool COQUETEL_MOLOTOV_USADO = false;
ALLEGRO_BITMAP *player_batalha = NULL; // imagem do jogador para a batalha
ALLEGRO_BITMAP *billy_batalha = NULL; // imagem do inimigo para a batalha
ALLEGRO_BITMAP *espeto_batalha= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *geraldina_batalha= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *jose_batalha= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *caixao_batalha= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *fantasma_batalha= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *player_dano= NULL;   // imagem do jogador para a batalha
ALLEGRO_BITMAP *billy_dano= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *espeto_dano= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *geraldina_dano= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *jose_dano= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *caixao_dano= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *espeto_morto= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *geraldina_morta= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *jose_morto= NULL;   // imagem do inimigo para a batalha
ALLEGRO_BITMAP *caixa_de_ataques = NULL; // opcoes de ataque
ALLEGRO_BITMAP *ataques = NULL;          // ataques
ALLEGRO_BITMAP *vida_player = NULL;      // vida do protagonista   
ALLEGRO_BITMAP *vida_vilao = NULL;       // vida do vilao
ALLEGRO_BITMAP *base_fantasma = NULL;  // base do fantasma na batalha
ALLEGRO_BITMAP *menu = NULL;  // tela inicial
ALLEGRO_BITMAP *titulo = NULL;  // titulo da tela inicial
ALLEGRO_BITMAP *mapmenu = NULL;  // mapa da tela inicial
ALLEGRO_BITMAP *tela_fundo = NULL;  // base do personagem na batalha
ALLEGRO_BITMAP *caixa_nome = NULL;
ALLEGRO_BITMAP *estrela = NULL;
ALLEGRO_SAMPLE *ambient_song13 = NULL;
ALLEGRO_SAMPLE *ambient_song24 = NULL;
ALLEGRO_SAMPLE *ambient_song5 = NULL;
ALLEGRO_SAMPLE *battle1_song = NULL;
ALLEGRO_SAMPLE *battle2_song = NULL;
ALLEGRO_SAMPLE *battle3_song = NULL;
ALLEGRO_SAMPLE *battle4_song = NULL;
ALLEGRO_SAMPLE *battle5_song = NULL;
ALLEGRO_SAMPLE *ending_song = NULL;
ALLEGRO_SAMPLE *highwayman = NULL;
ALLEGRO_SAMPLE *type_sound = NULL;
ALLEGRO_SAMPLE *death_song = NULL;
ALLEGRO_SAMPLE *desafinacao1 = NULL;
ALLEGRO_SAMPLE *desafinacao2 = NULL;
ALLEGRO_SAMPLE *desafinacao3 = NULL;
ALLEGRO_BITMAP *carregar = NULL; //variavel que vai receber a imagem do game over
bool BATALHA_JOSE = false;
const char *ajuda_cesar = NULL;
ALLEGRO_BITMAP *telaFinal = NULL;
ALLEGRO_BITMAP *botaosair = NULL;
ALLEGRO_BITMAP *aperteM = NULL; // variavel que vai receber o botao para abrir o mapa
ALLEGRO_BITMAP *aperteO = NULL; // variavel que vai receber o botao para abrir os objetivos
ALLEGRO_BITMAP *img_vilao= NULL;
ALLEGRO_BITMAP *img_vilao_dano= NULL;
ALLEGRO_BITMAP *objetivos_fundo = NULL;

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
"111001111111110000000000111111111100000000*11111111111111111111111111111111111111111111111111110",
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
std::string dano_revolver="";

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

/* FUNÇÃO QUE INICIALIZA TODOS OS ELEMENTOS DO JOGO */
bool inicializaJogo() {
    if(!al_init()){
        throw InitNotDone();
        return false;
    }

    if(!al_install_keyboard()){
        throw InitNotDone();
        return false;
    }

    timer = al_create_timer(1.0/FPS);
    if(!timer){
        throw TimerNotCreated();
        return false;
    }

    if(!al_init_image_addon()){
        throw InitNotDone();
        return false;
    }

    ALLEGRO_MONITOR_INFO info;
    al_get_monitor_info(0, &info);
    res_x_comp = info.x2 - info.x1;
    res_y_comp = info.y2 - info.y1;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    game = al_create_display(res_x_comp, res_y_comp);
    if(!game){
        throw DisplayNotCreated(timer);
        return false;
    }

    event_queue = al_create_event_queue();
    if(!event_queue){
        throw EventQeueNotCreated(game, timer);

        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar-moldura.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_init_font_addon();
	al_init_ttf_addon();
    al_init_acodec_addon();

    font_titulo = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(150), 0);
    if(!font_titulo)
    {
        throw InitNotDone();
        return false;
    }

    font10 = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(50), 0);
    if(!font10)
    {
        throw InitNotDone();
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);    
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");
    al_flip_display();

    map= al_load_bitmap("./../assets/map1.bmp");
    if(!map){
        throw BitmapNotFound(game, timer);
        return false;
    }

    mini_map = al_load_bitmap("./../assets/map.bmp");
    if(!mini_map){
        throw BitmapNotFound(game, timer);
        return false;
    }

    player_minimap = al_load_bitmap("./../assets/player_minimap.bmp");
    if(!player_minimap){
        throw BitmapNotFound(game, timer);
        return false;
    }

    telaFinal= al_load_bitmap("./../assets/final.bmp");
    if(!telaFinal){
        throw BitmapNotFound(game, timer);
        return false;
    }
    
    font15 = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(75), 0);
    if(!font15)
    {
        throw InitNotDone();
        return false;
    }

    font_faixas = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(40), 0);
    if(!font_faixas)
    {
        throw InitNotDone();
        return false;
    }

    font13 = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(65), 0);
    if(!font13)
    {
        throw InitNotDone();
        return false;
    }

    fontataques = al_load_font("./../assets/alterebro-pixel-font.ttf", RES_HEIGHT(50), 0);
    if(!fontataques)
    {
        throw InitNotDone();
        return false;
    }

    if(!al_install_audio()){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    al_reserve_samples(7);

    ambient_song13 = al_load_sample("./../assets/musicas/ambient_impares.ogg");
    if(!ambient_song13){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar1.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");   
    al_flip_display();

    ambient_song24 = al_load_sample("./../assets/musicas/ambient_pares.ogg");
    if(!ambient_song24){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    ambient_song5 = al_load_sample("./../assets/musicas/ambient5.ogg");
    if(!ambient_song5){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    ending_song = al_load_sample("./../assets/musicas/hwm.ogg");
    if(!ending_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar2.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);  
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");  
    al_flip_display();

    battle1_song = al_load_sample("./../assets/musicas/tgtbtu.ogg");
    if(!battle1_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar3.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");    
    al_flip_display();

    battle2_song = al_load_sample("./../assets/musicas/venom.ogg");
    if(!battle2_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar4.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);  
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");  
    al_flip_display();

    battle3_song = al_load_sample("./../assets/musicas/hunter.ogg");
    if(!battle3_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar5.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);  
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");  
    al_flip_display();

    battle4_song = al_load_sample("./../assets/musicas/kyrie.ogg");
    if(!battle4_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar6.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);   
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece."); 
    al_flip_display();

    battle5_song = al_load_sample("./../assets/musicas/grits.ogg");
    if(!battle5_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar7.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);  
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");  
    al_flip_display();

    type_sound = al_load_sample("./../assets/musicas/type.ogg");
    if(!type_sound){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    death_song = al_load_sample("./../assets/musicas/death.ogg");
    if(!death_song){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar8.bmp");
    if(!carregar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);    
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece.");
    al_flip_display();

    highwayman = al_load_sample("./../assets/musicas/hwm_instr.ogg");
    if(!highwayman){
        al_destroy_display(game);
        al_destroy_timer(timer);
        return false;
    }

    carregar = al_load_bitmap("./../assets/carregar9.bmp");
    if(!carregar){
        return false;
    }

    desafinacao1 = al_load_sample("./../assets/musicas/desafinacao1.ogg");
    if(!desafinacao1){
        return false;
    }

    desafinacao2 = al_load_sample("./../assets/musicas/desafinacao2.ogg");
    if(!desafinacao2){
        return false;
    }

    desafinacao3 = al_load_sample("./../assets/musicas/desafinacao3.ogg");
    if(!desafinacao3){
        return false;
    }

    al_clear_to_color(al_map_rgb(238,202,169));
    al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(300), 0,"CARREGANDO...");
    al_draw_scaled_bitmap(carregar, 0, 0, 753, 232, RES_WIDTH(600), RES_HEIGHT(400), RES_WIDTH(753), RES_HEIGHT(232), 0);   
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(470), RES_HEIGHT(970), 0, "Dica: O progresso das missões secundárias será sempre salvo, porém falhar em um"); 
    al_draw_textf(font10, al_map_rgb(60,25,97), RES_WIDTH(520), RES_HEIGHT(1000), 0, "nível ou fechar o jogo antes de concluí-lo fará com que ele recomece."); 
    al_flip_display();
    al_rest(5);

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
    base_fantasma=al_load_bitmap("./../assets/batalha/base-fantasma.bmp");
    player_batalha=al_load_bitmap("./../assets/batalha/player-batalha.bmp");        
    billy_batalha=al_load_bitmap("./../assets/batalha/pistoleiro-batalha.bmp"); 
    espeto_batalha=al_load_bitmap("./../assets/batalha/xerife-batalha.bmp"); 
    geraldina_batalha=al_load_bitmap("./../assets/batalha/coiote-batalha.bmp"); 
    jose_batalha=al_load_bitmap("./../assets/batalha/coveiro-batalha.bmp");
    caixao_batalha=al_load_bitmap("./../assets/batalha/caixao-batalha.bmp");
    fantasma_batalha=al_load_bitmap("./../assets/batalha/fantasma-batalha.bmp");
    player_dano=al_load_bitmap("./../assets/batalha/player-dano.bmp");
    billy_dano=al_load_bitmap("./../assets/batalha/pistoleiro-dano.bmp");
    espeto_dano=al_load_bitmap("./../assets/batalha/xerife-dano.bmp");
    geraldina_dano=al_load_bitmap("./../assets/batalha/coiote-dano.bmp");
    jose_dano=al_load_bitmap("./../assets/batalha/coveiro-dano.bmp");
    caixao_dano=al_load_bitmap("./../assets/batalha/caixao-dano.bmp");
    espeto_morto=al_load_bitmap("./../assets/batalha/xerife-morto.bmp");
    geraldina_morta=al_load_bitmap("./../assets/batalha/coiote-morta.bmp"); 
    jose_morto=al_load_bitmap("./../assets/batalha/coveiro-morto.bmp");
    


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
        throw BitmapNotFound(game, timer);
        return false;
    }

    relogiohud = al_load_bitmap("./../assets/relogio.bmp");
    if(!relogiohud){
        throw BitmapNotFound(game, timer);
        return false;
    }

    botaointeracao = al_load_bitmap("./../assets/aperteE.bmp");
    if(!botaointeracao){
        throw BitmapNotFound(game, timer);
        return false;
    }

    chave = al_load_bitmap("./../assets/chave-map.bmp");
    if(!chave){
        throw BitmapNotFound(game, timer);
        return false;
    }

    chavehud = al_load_bitmap("./../assets/chave.bmp");
    if(!chavehud){
        throw BitmapNotFound(game, timer);
        return false;
    }

    espingarda = al_load_bitmap("./../assets/espingarda.bmp");
    if(!espingarda){
        throw BitmapNotFound(game, timer);
        return false;
    }


    pocao = al_load_bitmap("./../assets/pocao-map.bmp");
    if(!pocao){
        throw BitmapNotFound(game, timer);
        return false;
    }

    pocaohud = al_load_bitmap("./../assets/pocao.bmp");
    if(!pocaohud){
        throw BitmapNotFound(game, timer);
        return false;
    }

    dinheiro1 = al_load_bitmap("./../assets/dinheiro1-map.bmp");
    if(!dinheiro1){
        throw BitmapNotFound(game, timer);
        return false;
    }

    dinheiro2 = al_load_bitmap("./../assets/dinheiro2-map.bmp");
    if(!dinheiro2){
        throw BitmapNotFound(game, timer);
        return false;
    }

    dinheiro3 = al_load_bitmap("./../assets/dinheiro3-map.bmp");
    if(!dinheiro3){
        throw BitmapNotFound(game, timer);
        return false;
    }

    dinheiro4 = al_load_bitmap("./../assets/dinheiro4-map.bmp");
    if(!dinheiro4){
        throw BitmapNotFound(game, timer);
        return false;
    }

    icone_player = al_load_bitmap("./../assets/icone-player.bmp");
    if(!icone_player){
        throw BitmapNotFound(game, timer);
        return false;
    }

    galinha1 = al_load_bitmap("./../assets/galinha1.bmp");
    if(!galinha1){
        throw BitmapNotFound(game, timer);
        return false;
    }

    galinha2 = al_load_bitmap("./../assets/galinha2.bmp");
    if(!galinha2){
        throw BitmapNotFound(game, timer);
        return false;
    }

    galinha3 = al_load_bitmap("./../assets/galinha3.bmp");
    if(!galinha3){
        throw BitmapNotFound(game, timer);
        return false;
    }

    galinha4 = al_load_bitmap("./../assets/galinha4.bmp");
    if(!galinha4){
        throw BitmapNotFound(game, timer);
        return false;
    }

    fundo = al_load_bitmap("./../assets/fundo_HUD.bmp");
    if(!fundo){
        throw BitmapNotFound(game, timer);
        return false;
    }

    tela_fundo = al_load_bitmap("./../assets/fundo.bmp");
    if(!tela_fundo){
        throw BitmapNotFound(game, timer);
        return false;
    }

    caixa_nome = al_load_bitmap("./../assets/escrever_nome.bmp");
    if(!caixa_nome){
        throw BitmapNotFound(game, timer);
        return false;
    }

    lifebar = al_load_bitmap("./../assets/Life_bar.bmp");
    if(!lifebar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    lifebar_batalhas = al_load_bitmap("./../assets/batalha/lifebarbat.bmp");
    if(!lifebar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    contorno = al_load_bitmap("./../assets/HUD_contorno.bmp");
    if(!contorno){
        throw BitmapNotFound(game, timer);
        return false;
    }

    frango = al_load_bitmap("./../assets/frango.bmp");
    if(!frango){
        throw BitmapNotFound(game, timer);
        return false;
    }

    caixa_texto = al_load_bitmap("./../assets/caixa_texto.bmp");
    if(!caixa_texto){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over1 = al_load_bitmap("./../assets/batalha/go1.bmp");
    if(!game_over1){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over2 = al_load_bitmap("./../assets/batalha/go2.bmp");
    if(!game_over2){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over3 = al_load_bitmap("./../assets/batalha/go3.bmp");
    if(!game_over3){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over4 = al_load_bitmap("./../assets/batalha/go4.bmp");
    if(!game_over4){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over5 = al_load_bitmap("./../assets/batalha/go5.bmp");
    if(!game_over5){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over6 = al_load_bitmap("./../assets/batalha/go6.bmp");
    if(!game_over6){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over7 = al_load_bitmap("./../assets/batalha/go7.bmp");
    if(!game_over7){
        throw BitmapNotFound(game, timer);
        return false;
    }

    portao = al_load_bitmap("./../assets/portao.bmp");
    if(!portao){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over8 = al_load_bitmap("./../assets/batalha/go8.bmp");
    if(!game_over8){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over9 = al_load_bitmap("./../assets/batalha/go9.bmp");
    if(!game_over9){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over10 = al_load_bitmap("./../assets/batalha/go10.bmp");
    if(!game_over10){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over11 = al_load_bitmap("./../assets/batalha/go11.bmp");
    if(!game_over11){
        throw BitmapNotFound(game, timer);
        return false;
    }

    game_over12 = al_load_bitmap("./../assets/batalha/go12.bmp");
    if(!game_over12){
        throw BitmapNotFound(game, timer);
        return false;
    }

    botaoreiniciar = al_load_bitmap("./../assets/enter.bmp");
    if(!botaoreiniciar){
        throw BitmapNotFound(game, timer);
        return false;
    }

    menu = al_load_bitmap("./../assets/home.bmp");
    if(!menu){
        throw BitmapNotFound(game, timer);
        return false;
    }

    titulo = al_load_bitmap("./../assets/titulo.bmp");
    if(!titulo){
        throw BitmapNotFound(game, timer);
        return false;
    }

    mapmenu = al_load_bitmap("./../assets/map-menu.bmp");
    if(!mapmenu){
        throw BitmapNotFound(game, timer);
        return false;
    }

    estrela = al_load_bitmap("./../assets/estrela.bmp");
    if(!estrela){
        throw BitmapNotFound(game, timer);
        return false;
    }

    botaosair = al_load_bitmap("./../assets/esc.bmp");
    if(!botaosair){
        throw BitmapNotFound(game, timer);
        return false;
    }

    aperteM = al_load_bitmap("./../assets/aperteM.bmp");
    if(!aperteM){
        throw BitmapNotFound(game, timer);
        return false;
    }

    aperteO = al_load_bitmap("./../assets/aperteO.bmp");
    if(!aperteO){
        throw BitmapNotFound(game, timer);
        return false;
    }

    objetivos_fundo = al_load_bitmap("./../assets/objetivos-fundo.bmp");
    if(!objetivos_fundo){
        throw BitmapNotFound(game, timer);
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

void setNivel(Protagonista *Player, int nivel, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4){
    resetTeclas();

    if(Player->getNivel() == 1){
        EIXO_X_PLAYER_TELA = 1216;
        EIXO_Y_PLAYER_TELA = 572;

        j = 69;
        i = 29;

        TELA_X_MAPA = 56;
        TELA_Y_MAPA = 23;

        resetCamera(13, 5);
        
        MAPA[28][63] = MAPA[28][63] = MAPA[68][64] = '3';
        MAPA[29][40] = '0'; // Adiciona colisão no Billy.
        Player->setVida(10);  
        Player->setMaxVida(10);  
        if(Player->qtdItem("Comida") < 1) Player->addItem("Comida", 1);

    }

    // Define as posições iniciais pra cada nível.
    else if(Player->getNivel() == 2){
        i = 30;
        j = 40;
        TELA_X_MAPA = 35;
        TELA_Y_MAPA = 24;

        EIXO_X_PLAYER_TELA = 704;
        EIXO_Y_PLAYER_TELA = 572;

        EIXO_X_MINIMAP = 890;
        EIXO_Y_MINIMAP = 478;

        Player->setMaxVida(20);     

        resetCamera(5, 5);

        // Adiciona personagens secundários na matriz
        MAPA[56][70] = MAPA[56][71] = MAPA[57][70] = MAPA[57][71] = '0'; 
        MAPA[28][76] = '1';
        MAPA[29][40] = 'A';
        MAPA[28][76] = '0'; // Adiciona colisao do Renato da matriz

        map= al_load_bitmap("./../assets/map2.bmp");

        if(!Sec2->completo()) MAPA[28][50] = 'F';
        else MAPA[28][50] = '0';

        if(!Sec3->completo()) MAPA[13][30] = 'I';
        else MAPA[13][30] = '0';

        if(!Sec4->completo()) MAPA[39][63] = 'G';
        else MAPA[39][63] = '0';

        if(!Sec1->completo()) MAPA[39][44] = MAPA[39][43] = 'H';
        else MAPA[39][44] = MAPA[39][43] = '0';

        MAPA[45][39] = MAPA[45][40] = 'z';
    }

    else if(Player->getNivel() == 3){
        i = 56;
        j = 69;

        Player->setMaxVida(30);   

        TELA_X_MAPA = 60;
        TELA_Y_MAPA = 50;

        EIXO_X_PLAYER_TELA = 960;
        EIXO_Y_PLAYER_TELA = 572;   

        EIXO_X_MINIMAP = 1280;
        EIXO_Y_MINIMAP = 826.5; 

        resetCamera(10, 5); 

        MAPA[28][76] = '0';
        MAPA[49][16] = MAPA[49][17] = '0'; // Adiciona colisão em Mario / Geraldina
        MAPA[29][40] = '0'; // Remove Ambrósio da matriz
        MAPA[56][70] = MAPA[56][71] = MAPA[57][70] = MAPA[57][71] = '1'; // Remove xerife espeto da matriz
        map= al_load_bitmap("./../assets/map3.bmp");
        MAPA[28][76] = 'J';

        if(!Sec2->completo()) MAPA[28][50] = 'F';
        else MAPA[28][50] = '0';

        if(!Sec3->completo()) MAPA[13][30] = 'I';
        else MAPA[13][30] = '0';

        if(!Sec4->completo()) MAPA[39][63] = 'G';
        else MAPA[39][63] = '0';

        if(!Sec1->completo()) MAPA[39][44] = MAPA[39][43] = 'H';
        else MAPA[39][44] = MAPA[39][43] = '0';

        MAPA[45][39] = MAPA[45][40] = 'z';
    }

    else if(Player->getNivel() == 4){
        i = 48;
        j = 19;

        Player->setMaxVida(40);  

        TELA_X_MAPA = 11;
        TELA_Y_MAPA = 45;

        EIXO_X_PLAYER_TELA = 896;
        EIXO_Y_PLAYER_TELA = 380; 

        EIXO_X_MINIMAP = 605;
        EIXO_Y_MINIMAP = 718.5;    

        resetCamera(11, 2); 

        MAPA[49][16] = MAPA[49][17] = 'C';
        MAPA[27][88] = MAPA[28][88] = MAPA[27][89] = '0';
        MAPA[28][76] = '0'; // Adiciona colisao do Renato da matriz
        map= al_load_bitmap("./../assets/map4.bmp");

        if(!Sec2->completo()) MAPA[28][50] = 'F';
        else MAPA[28][50] = '0';

        if(!Sec3->completo()) MAPA[13][30] = 'I';
        else MAPA[13][30] = '0';

        if(!Sec4->completo()) MAPA[39][63] = 'G';
        else MAPA[39][63] = '0';

        if(!Sec1->completo()) MAPA[39][44] = MAPA[39][43] = 'H';
        else MAPA[39][44] = MAPA[39][43] = '0';

        MAPA[45][39] = MAPA[45][40] = 'z';
    }

    else if(Player->getNivel() == 5){
        i = 29;
        j = 86;

        Player->setMaxVida(50);  

        TELA_X_MAPA = 72;
        TELA_Y_MAPA = 23;

        EIXO_X_PLAYER_TELA = 1280;
        EIXO_Y_PLAYER_TELA = 572;  

        EIXO_X_MINIMAP = 1509.5;
        EIXO_Y_MINIMAP = 462; 

        resetCamera(15, 5); 

        MAPA[49][16] = MAPA[49][17] = 'C';
        MAPA[27][88] = MAPA[28][88] = MAPA[27][89] = '1'; // Remove José do Caixão da matriz
        MAPA[16][7] = MAPA[16][8] = MAPA[17][7] = MAPA[17][8] = MAPA[17][9] = 'E'; // Adiciona Johnny Cash na matriz
        map= al_load_bitmap("./../assets/map5.bmp");

        if(!Sec2->completo()) MAPA[28][50] = 'F';
        else MAPA[28][50] = '0';

        if(!Sec3->completo()) MAPA[13][30] = 'I';
        else MAPA[13][30] = '0';

        if(!Sec4->completo()) MAPA[39][63] = 'G';
        else MAPA[39][63] = '0';

        if(!Sec1->completo()) MAPA[39][44] = MAPA[39][43] = 'H';
        else MAPA[39][44] = MAPA[39][43] = '0';

        MAPA[45][39] = MAPA[45][40] = 'z';
    }   

    general_player = player_f1;
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
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

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

    falas[0] += (player_nome + "?");
    falas[3] += (player_nome + ", assombrações... maldições!");

    Dialogo dialogo(falas, fluxo, incrementos);
    if(!dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao)){
        missao->setinicializadaTrue();
    }
}

void dialogoMissaoPocaoPt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

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

    falas[0] += (player_nome+ ".");

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoMissaoPocaoPt2Level5(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

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

    falas[0] += player_nome + ".";

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
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

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
        "1Primeiro que ele não é exatamente meu amigo. Segundo, o que tem no saloon?",
        "2O saloon foi invadido por um dos pistoleiros, tomou o lugar do cervejeiro. Foi o primeiro golpe.",
        "2Os outros, não sabemos onde estão exatamente, devem estar escondidos.",
        "2Vencer ele talvez deixe alguns moradores mais livres para sair de casa.",
        "1*Vou ver o que posso fazer."
    };

    falas[0] += player_nome + "! " + player_nome + "!";

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
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-renato.bmp");
    std::string *falas = new std::string[9] {
        "1Olá?",
        "2Você deve ser o ",
        "1As vezes.",
        "2É um prazer conhece-lo, mas terei que ser breve.",
        "2Um dos invasores roubou a estrela do xerife e está passando por ele pela região.",
        "1E você sabe onde ele está?",
        "2Me informaram que ele foi encontrado soltando alguns bandidos pelo deserto.",
        "1Vou dar uma passada lá.",
        "2*Quando terminar de resolver, não esqueça de passar aqui para trazer o crachá."
    };

    falas[1] += player_nome + ".";

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("RENATO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel2Pt3(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    fluxo.insert(std::pair<short int, bool> (2, true));

    std::string **opcoes = new std::string*;
    opcoes[0] = new std::string[2] {"XERIFE? (Z)", "MENTIRA (X)"};

    short int **incrementos = new short int*;
    incrementos[0] = new short int[2] {1, 8};


    icone = al_load_bitmap("./../assets/icone-xerife.bmp");
    std::string *falas = new std::string[12] {
        "2Oi, garoto! Eu estava indo agora mesmo resolver a invasão ao rancho.",
        "1Invasão ao rancho?",
        "2Ah, achei que morava por aqui. Não é nada, não. Nada a que se preocupe!",
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
    dialogo.dialogar("ESPETO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel3Pt1(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-renato.bmp");
    std::string *falas = new std::string[13] {
        "1Aqui, a estrela do xerife.",
        "2Ótimo!",
        "2Aproveite e fique com essas estrelas falsas.",
        "1Pra que isso?",
        "2Você pode usar para atingir seus inimigos.",
        "1Ah, tipo uma shuriken ninja? Obrigado!",
        "2Seja lá o que isso for, sim.",
        "1Outra coisa, o cacto falou algo sobre uma invasão de um coiote a um rancho.",
        "2Deve ser mais um deles, por que não vai lá ver?",
        "1É o meu trabalho, não é?",
        "2Aproveitei e fique com isso, uma recompensa pelo bom trabalho.",
        "1O senhor tá sendo muito generoso por esta vila.",
        "2*Uma contribuição da cidade! Algum morador vai ter uma surpresa no extrato..."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("RENATO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
    Player->setDinheiro(Player->getDinheiro() + 10);
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
        "1Acho que não falamos a mesma língua.",
        "2Na verdade, falamos, sim, mas assim fica mais dramático.",
        "2*E é na nossa língua que eu vou te mandar pra fora daqui.",
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("GERALDINA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoNivel4Pt2(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;


    icone = al_load_bitmap("./../assets/icone-mario.bmp");
    std::string *falas = new std::string[7] {
        "2Pode deixar que eu cuido dela agora. Faz tempo que eu não faço um churrasco",
        "2Isso aqui estava com ela, um pé de coelho. Pode te trazer sorte.",
        "2Imagino que um garoto não tenha o tiro tão preciso ainda",
        "1Ah, obrigado.",
        "2É... Eu que agradeço.",
        "2Lhe daria mais, garoto, mas alguém me tomou umas 10 moedas e o banco diz que não tem nada o que possa fazer.",
        "1*..."
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
        "2*Pessoal do roteiro tava numa preguiça danada, hein."
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
        "1Mas qual o seu problema? Do nada sua alma resolve voltar pro mundo pra por terror numa vila?",
        "2Assim que eu atingi o outro lado, tentei encontrar um lugar pra descansar meu espírito, se eu conseguisse.",
        "2Mas eu nasci para ser um fora da lei e prometi que eu voltaria.",
        "2Não importava se como um forasteiro ou uma simples gota de chuva, mas eu voltaria pra esse mundo.",
        "1*Você vai voltar pra prisão de Folsom, Johnny."
    };

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("JOHNNY CASH", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

const char *atualizaCesarJulio(Protagonista *player, Missao *n1, Missao *n2, Missao *n3, Missao *n4, Missao *n5){
    if(player->getNivel() == 1){
        if(n1->_etapa == 2) return "2*O que tá esperando pra ir derrotar o pistoleiro?";
    }
    else if(player->getNivel() == 2){
        if(n2->_etapa == 1) return "2*O cervejeiro está feliz por recuperar o saloon, você deveria falar com ele.";
        else if(n2->_etapa == 2) return "2*Ouvi o Ambrósio falar pra você ir até o bancário... Ele só fala gritando... Por que não vai lá?";
        else if(n2->_etapa == 3) return "2*Hmm, um bandido roubou o cargo de xerife... Que trama fantástica da equipe de roteiro! Vai lá derrotar ele!";
    }
    else if(player->getNivel() == 3){
        if(n3->_etapa == 1) return "2*O bancário está esperando a estrela... Lembra? Você tinha que prestar mais atenção nos diálogos.";
        else if(n3->_etapa == 2) return "2*O rancho é seguindo a trilha à esquerda na saída da cidade. Tem um invasor esperando pra ser derrotado.";
    }
    else if(player->getNivel() == 4){
        if(n4->_etapa == 1) return "2*O rancheiro deve estar todo bobo que você recuperou o rancho dele. Por que não fala com ele?";
        else if(n4->_etapa == 2) return "2*Estava caminhando pelo rancho... Parece que o coveiro tá metido nisso... Mostra pra ele quem manda aqui!";
    }
    else if(player->getNivel() == 5){
        return "2*Quando for derrotar o Johnny Cash, pede um autógrafo pra mim?";
    }

    return "";
}

void dialogoCesarJulio(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;

    icone = al_load_bitmap("./../assets/icone-cesar.bmp");
    std::string *falas = new std::string[1] {
        ""
    };
    falas[0] += ajuda_cesar;

    Dialogo dialogo(falas, fluxo, incrementos);
    dialogo.dialogar("CESAR JÚLIO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);
}

void dialogoFinal(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int cont, Protagonista *Player, Interacao *botao){
    std::string player_nome = Player->getNome();
    for(int i = 1; i < player_nome.length(); i++)
        player_nome[i] += 32; 

    std::map<short int, bool> fluxo;
    std::string **opcoes;
    short int **incrementos;
    std::string *falas;
    Dialogo *dialogo;


    icone = al_load_bitmap("./../assets/icone-mario.bmp");
    falas = new std::string [3] {
        "1Bom, acho que esse foi o último.",
        "1Qualquer um que ousar atacar a cidade de novo irá pensar duas vezes ao se lembrar de ",
        "2*Obrigado por salvar minhas galinhas. Fico te devendo uma galinhada."
    };

    falas[1] += player_nome + ".";

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("MÁRIO VICTOR", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-andrew.bmp");
    falas = new std::string [1] {
        "2*Até que você é bom de mira, acho que a Sandra Rosa ia gostar de competir com você."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("ANDREW", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-saul.bmp");
    falas = new std::string [4] {
        "2Acho que agora que você derrotou todos os malvados não vou mais precisar sair da cidade.",
        "2Vou usar o dinheiro do relógio pra comprar uma carroça nova!",
        "1Agora que o perigo acabou você já pode parar de se esconder atrás do chapéu.",
        "2*Hehe... só por precaução... vai que ainda sobrou um deles né."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("SAUL", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-cris.bmp");
    falas = new std::string [1] {
        "2*Esses arruaceiros deixaram tudo uma bagunça! Eu vou ter que arrumar todo o armazém de novo!!!!!"
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("CRIS", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-bruxa.bmp");
    falas = new std::string [2] {
        "2Suas ações demandam recompensas, e o universo está preparando elas pra você.",
        "2*Uma delas era um cristal de proteção que eu mesma lhe daria, mas acho que deixei ele cair por aqui...."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("CLARA", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-coveiro.bmp");
    falas = new std::string [2] {
        "2Bem, acho que depois de tudo isso eu tenho trabalho suficiente pro Caixão do José ficar entretido.",
        "2*Mas prometo não colocar pessoas em risco de novo. Pelo menos não as pessoas da cidade."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("JOSÉ DO CAIXÃO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-cesar.bmp");
    falas = new std::string [3] {
        "2Obrigado ",
        "2Como podemos te agradecer?",
        "1*Uma bebida cairia bem."
    };

    falas[0] += player_nome + ".";

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("CÉSAR JÚLIO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-cervejeiro.bmp");
    falas = new std::string [1] {
        "2*Uma rodada de bebida grátis para o "
    };

    falas[0] += player_nome + "!";

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("CERVEJEIRO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-comerciante.bmp");
    falas = new std::string [1] {
        "2*Eu acho que todos merecem uma bebida depois desse susto. Eu pago."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("VENDEDOR", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;

    icone = al_load_bitmap("./../assets/icone-cervejeiro.bmp");
    falas = new std::string [2] {
        "2Uma rodada de bebida para todos da cidade!",
        "1* Hehe."
    };

    dialogo = new Dialogo(falas, fluxo, incrementos);
    dialogo->dialogar("CERVEJEIRO", opcoes, rel, chav, poc, d1, d2, d3, d4, cont, Player, botao);

    delete[] falas;
    delete dialogo;


}
#include "Save.hpp"
#include <fstream>

void GameSave::save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4){
    std::ofstream data;

    data.open("./../assets/game_save.txt");

    // Salva nome do jogador.
    data << Player->getNome() << "\n";

    // Salva nível e dados do player.
    data << Player->getNivel() << "\n";
    data << Player->getVida() << " " << Player->getMaxVida() << "\n";
    data << Player->getDinheiro() << " " << Player->qtdItem("Comida") << "\n";
    data << Player->qtdItem("Espingarda") << " " << Player->qtdItem("Chave") << " " << Player->qtdItem("Relogio") << "\n";

    //Salva missões secundárias.
    data << (int)Sec1->completo() << "\n";
    data << (int)Sec2->completo() << "\n";
    data << (int)Sec3->completo() << "\n";
    data << (int)Sec4->completo() << "\n";

    data.close();
}

void GameSave::read_save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4){
    bool mission_passed;
    short int value;
    std::string nome;
    std::ifstream data;

    data.open("./../assets/game_save.txt");

    // Lê nome do jogador.
    getline(data, nome);
    Player->setNome(nome);

    // Lê nível e dados do player.
    data >> value;
    Player->setNivel(value);
    data >> value;
    Player->setVida(value);
    data >> value;
    Player->setMaxVida(value);
    data >> value;
    Player->setDinheiro(value);
    data >> value;
    Player->addItem("Comida", value);
    data >> value;
    Player->addItem("Espingarda", value);
    data >> value;
    Player->addItem("Chave", value);
    data >> value;
    Player->addItem("Relogio", value);

    // Lê missões recundárias
    data >> mission_passed;
    if(mission_passed == true) Sec1->finish();
    data >> mission_passed;
    if(mission_passed == true) Sec2->finish();
    data >> mission_passed;
    if(mission_passed == true) Sec3->finish();
    data >> mission_passed;
    if(mission_passed == true) Sec4->finish();

    data.close();

    // Define as posições iniciais pra cada nível.
    if(Player->getNivel()==2){
        j = 48;
        TELA_X_MAPA = 35;

        resetCamera(15, 7);
    }

    else if(Player->getNivel()==3){
        i = 56;
        j = 69;

        TELA_X_MAPA = 60;
        TELA_Y_MAPA = 50;

        EIXO_X_PLAYER_TELA = 958;
        EIXO_Y_PLAYER_TELA = 572;    

        resetCamera(11, 7); 
    }

    else if(Player->getNivel()==4){
        i = 48;
        j = 19;

        TELA_X_MAPA = 10;
        TELA_Y_MAPA = 45;

        EIXO_X_PLAYER_TELA = 958;
        EIXO_Y_PLAYER_TELA = 380;    

        resetCamera(12, 4);  
    }

    else if(Player->getNivel()==5){
        i = 29;
        j = 86;

        TELA_X_MAPA = 72;
        TELA_Y_MAPA = 23;

        EIXO_X_PLAYER_TELA = 1280;
        EIXO_Y_PLAYER_TELA = 572;  

        resetCamera(16, 7); 
    }

    //variável, começa a dar zoom, começa a dar zoom, largura, altura, até onde vai, até onde vai, escala, escala, 0
    al_draw_scaled_bitmap(map, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 0, 0, 
        RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);
    al_draw_scaled_bitmap(player_f1, 0, 0, res_x_player, res_y_player, RES_WIDTH(EIXO_X_PLAYER_TELA), 
        RES_HEIGHT(EIXO_Y_PLAYER_TELA), RES_WIDTH(res_x_player*ZOOM), RES_HEIGHT(res_y_player*ZOOM), 0);

    if (!Sec3->completo())
        al_draw_scaled_bitmap(relogio, TELA_X_MAPA*CELULA, TELA_Y_MAPA*CELULA, res_x_comp, res_y_comp, 
            0, 0, RES_WIDTH(res_x_comp*ZOOM), RES_HEIGHT(res_y_comp*ZOOM), 0);

    al_flip_display();
}


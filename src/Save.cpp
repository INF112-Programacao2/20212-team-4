#include "Save.hpp"
#include <fstream>

void GameSave::save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4, 
    Interacao *d1, Interacao *d2, Interacao *d3, Interacao *d4){
    std::ofstream data;

    data.open("./../assets/game_save.txt");

    // Salva nome do jogador.
    data << Player->getNome() << "\n";

    // Salva nível e dados do player.
    data << Player->getNivel() << "\n";
    data << Player->getVida() << " " << Player->getMaxVida() << "\n";
    data << Player->getDinheiro() << " " << Player->qtdItem("Comida") << "\n";
    data << Player->qtdItem("Espingarda") << " " << Player->qtdItem("Chave") << " " << Player->qtdItem("Relogio") << " " << Player->qtdItem("Pocao") << "\n";
    data << d1->completo() << " " << d2->completo() << " " << d3->completo() << " " << d4->completo() << "\n";

    //Salva missões secundárias.
    data << (int)Sec1->completo() << " " << (int)Sec1->getinicializada() << "\n";
    data << (int)Sec2->completo() << " " << (int)Sec2->getinicializada() << "\n";
    data << (int)Sec3->completo() << " " << (int)Sec3->getinicializada() << "\n";
    data << (int)Sec4->completo() << " " << (int)Sec4->getinicializada() << "\n";

    data.close();
}

void GameSave::read_save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4, Interacao *Int1, 
        Interacao *Int2, Interacao *Int3, Interacao *d1, Interacao *d2, Interacao *d3, Interacao *d4){

    short int value;
    std::string nome;
    std::ifstream data;

    data.open("./../assets/game_save.txt");

    // Lê nome do jogador.
    getline(data, nome);

    if(nome == "(escolher)")
        Player->escolherNome();
    else
        Player->setNome(nome);

    // Lê nível e dados do player.
    data >> value;
    Player->setNivel(1);

    for(int i = 1; i < value; i++)
        Player->nextLevel();

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
    if(value == 1) Int1->removeItem('1');
    data >> value;
    Player->addItem("Relogio", value);
    if(value == 1) Int2->removeItem('1');
    data >> value;
    Player->addItem("Pocao", value);

    data >> value;
    if(value == 1) d1->removeItem('1');
    data >> value;
    if(value == 1) d2->removeItem('1');
    data >> value;
    if(value == 1) d3->removeItem('1');
    data >> value;
    if(value == 1) d4->removeItem('1');

    // Lê missões recundárias
    data >> value;
    if(value == 1){
        Sec1->finish();
        MAPA[38][44] = '1';
    }
    data >> value;
    if(value == 1) Sec1->setinicializadaTrue();

    data >> value;
    if(value == 1){
        Sec2->finish();
        MAPA[28][54] = '1';
    }
    data >> value;
    if(value == 1) Sec2->setinicializadaTrue();

    data >> value;
    if(value == 1) {
        Sec3->finish();
        MAPA[39][65] = '1';
    }
    data >> value;
    if(value == 1) Sec3->setinicializadaTrue();

    data >> value;
    if(value == 1) {
        Sec4->finish();
        MAPA[13][31] = '1';
    }
    data >> value;
    if(value == 1) Sec4->setinicializadaTrue();


    data.close();
}
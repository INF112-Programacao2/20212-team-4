#include "Save.hpp"
#include <fstream>

GameSave::GameSave(){
    //this->_missoes = new MissaoSecundaria[4];
}

GameSave::~GameSave(){
    //delete[] this->_missoes;
}

void GameSave::save(Protagonista *Player /*, MissaoSecundaria &Sec1, MissaoSecundaria &Sec2, MissaoSecundaria &Sec3*/){
    std::ofstream data;

    // Salva nome do jogador.
    data << Player->getNome() << "\n";

    // Salva nível e dados do player.
    data << Player->getNivel() << "\n";
    data << Player->getVida() << " " << Player->getMaxVida() << "\n";
    data << Player->getDinheiro() << " " << Player->qtdItem("Comida");
    data << Player->qtdItem("Espingarda") << " " << Player->qtdItem("Chave") << " " << Player->qtdItem("Relogio");

    //Salva missões secundárias.
    // data << (int)Sec1.finalizada() << "\n";
    // data << (int)Sec2.finalizada() << "\n";
    // data << (int)Sec3.finalizada() << "\n";
}

void GameSave::read_save(){
    bool mission_passed;
    short int value;
    std::string nome;
    std::ifstream data;

    // Lê nome do jogador.
    getline(data, nome);
    this->_player->setNome(nome);

    // Lê nível e dados do player.
    data >> value;
    for(int i = 0; i < value-1; i++)
        this->_player->nextLevel(0);

    data >> value;
    this->_player->setVida(value);
    data >> value;
    this->_player->setMaxVida(value);
    data >> value;
    this->_player->setDinheiro(value);
    data >> value;
    this->_player->addItem("Comida", value);
    data >> value;
    this->_player->addItem("Espingarda", value);
    data >> value;
    this->_player->addItem("Chave", value);
    data >> value;
    this->_player->addItem("Relogio", value);

    // Lê missões recundárias
    // data >> mission_passed;
    // if(mission_passed == true) this->_missoes[0]->finish();
    // data >> mission_passed;
    // if(mission_passed == true) this->_missoes[1]->finish();
    // data >> mission_passed;
    // if(mission_passed == true) this->_missoes[2]->finish();
    // data >> mission_passed;
    // if(mission_passed == true) this->_missoes[3]->finish();
}

void GameSave::check_point(Protagonista *Player /*, MissaoSecundaria &Sec1, MissaoSecundaria &Sec2, MissaoSecundaria &Sec3*/){
    Player = this->_player;
    // if(this->_missoes[0] == true) Sec1->finish();
    // if(this->_missoes[1] == true) Sec2->finish();
    // if(this->_missoes[2] == true) Sec3->finish();
    // if(this->_missoes[3] == true) Sec4->finish();
}

#include "Save.hpp"
#include <fstream>

void GameSave::save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3){
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

    data.close();
}

void GameSave::read_save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3){
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
    for(int i = 0; i < value-1; i++)
        Player->nextLevel(0);

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
    if(mission_passed == true) Sec1->finish();
    data >> mission_passed;
    if(mission_passed == true) Sec1->finish();
    data >> mission_passed;
    if(mission_passed == true) Sec1->finish();

    data.close();
}


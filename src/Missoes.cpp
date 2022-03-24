#include "Missoes.hpp"

Missao::Missao(short int X, short int Y, unsigned char valor):
    Interacao("missao", X, Y, valor), inicializada(false) {
    this->_etapa = 1;
}

bool Missao::getinicializada(){
    return inicializada;
}

void Missao::setinicializadaTrue(){
    inicializada = true;
}

MissaoSecundaria::MissaoSecundaria(short int X, short int Y, unsigned char valor, short int recompensa):
    Missao(X, Y, valor), _itemColetado(false), _recompensa(recompensa) {}

void MissaoSecundaria::get(){
    this->_itemColetado = true;
}

bool MissaoSecundaria::got(){
    return this->_itemColetado;
}

void MissaoSecundaria::finish(){
    this->_completo = true;
}

void MissaoSecundaria::pay(Protagonista *Player){
    Player->setDinheiro(Player->getDinheiro() + this->_recompensa);
}

void Objetivos::atualizaPrincipal(Missao *Nivel1, Missao *Nivel2, Missao *Nivel3, Missao *Nivel4, Missao *Nivel5, Protagonista *Player){
    if(Player->getNivel() == 1){
        if(Nivel1->_etapa == 1){
            _principal = "Fale com o César Julio";
        }
        if(Nivel1->_etapa == 2){
            _principal = "Vá para o Saloon";
        }
    }
    if(Player->getNivel() == 2){
        if(Nivel2->_etapa == 1){
            _principal = "Fale com o Ambrósio";
        }
        if(Nivel2->_etapa == 2){
            _principal = "Fale com o Renato";
        }
        if(Nivel2->_etapa == 3){
            _principal = "Vá para o Deserto";
        }
    }
    if(Player->getNivel() == 3){
        if(Nivel3->_etapa == 1){
            _principal = "Fale com o Renato";
        }
        if(Nivel3->_etapa == 2){
            _principal = "Vá para o Rancho";
        }
    }
    if(Player->getNivel() == 4){
        if(Nivel4->_etapa == 1){
            _principal = "Fale com Mario Victor";
        }
        if(Nivel4->_etapa == 2){
            _principal = "Vá para o cemitério";
        }
    }
    if(Player->getNivel() == 5){
        _principal = "Vá para a floresta";
    }
}

void Objetivos::atualizaSecundaria(MissaoSecundaria *espingarda, MissaoSecundaria *relogio, MissaoSecundaria *chave, MissaoSecundaria *pocao, Protagonista *Player){
    if(espingarda->getinicializada()){
        std::vector<std::string>::iterator it_etapa1 = _secundarias.begin();
        for (; it_etapa1 != _secundarias.end(); it_etapa1++)
            if(*it_etapa1 ==  "Fale com Mario Victor")
                break;

        std::vector<std::string>::iterator it_etapa2 = _secundarias.begin();
        for (; it_etapa2 != _secundarias.end(); it_etapa2++)
            if(*it_etapa2 ==  "Volte ao Andrew")
                break;

        if(espingarda->completo() && it_etapa2 != _secundarias.end()){
            _secundarias.erase(it_etapa2);
        }
        else if(!espingarda->completo() && Player->qtdItem("Espingarda") == 0 && it_etapa1 == _secundarias.end()){
            _secundarias.push_back("Fale com Mario Victor");
        }
        else if(!espingarda->completo() && Player->qtdItem("Espingarda") > 0 && it_etapa1 != _secundarias.end()){
            _secundarias.erase(it_etapa1);
            _secundarias.push_back("Volte ao Andrew");
        }
    }

    if(relogio->getinicializada()){
        std::vector<std::string>::iterator it_etapa1 = _secundarias.begin();
        for (; it_etapa1 != _secundarias.end(); it_etapa1++)
            if(*it_etapa1 ==  "Pegue o relógio")
                break;

        std::vector<std::string>::iterator it_etapa2 = _secundarias.begin();
        for (; it_etapa2 != _secundarias.end(); it_etapa2++)
            if(*it_etapa2 ==  "Volte ao Saul")
                break;

        if(relogio->completo() && it_etapa2 != _secundarias.end()){
            _secundarias.erase(it_etapa2);
        }
        else if(!relogio->completo() && Player->qtdItem("Relogio") == 0 && it_etapa1 == _secundarias.end()){
            _secundarias.push_back("Pegue o relógio");
        }
        else if(!relogio->completo() && Player->qtdItem("Relogio") > 0 && it_etapa1 != _secundarias.end()){
            _secundarias.erase(it_etapa1);
            _secundarias.push_back("Volte ao Saul");
        }
    }

    if(chave->getinicializada()){
        std::vector<std::string>::iterator it_etapa1 = _secundarias.begin();
        for (; it_etapa1 != _secundarias.end(); it_etapa1++)
            if(*it_etapa1 ==  "Pegue a chave")
                break;

        std::vector<std::string>::iterator it_etapa2 = _secundarias.begin();
        for (; it_etapa2 != _secundarias.end(); it_etapa2++)
            if(*it_etapa2 ==  "Volte ao Cris")
                break;

        if(chave->completo() && it_etapa2 != _secundarias.end()){
            _secundarias.erase(it_etapa2);
        }
        else if(!chave->completo() && Player->qtdItem("Chave") == 0 && it_etapa1 == _secundarias.end()){
            _secundarias.push_back("Pegue a chave");
        }
        else if(!chave->completo() && Player->qtdItem("Chave") > 0 && it_etapa1 != _secundarias.end()){
            _secundarias.erase(it_etapa1);
            _secundarias.push_back("Volte ao Cris");
        }
    }
    
    if(pocao->getinicializada()){
        std::vector<std::string>::iterator it_etapa1 = _secundarias.begin();
        for (; it_etapa1 != _secundarias.end(); it_etapa1++)
            if(*it_etapa1 ==  "Pegue a poção")
                break;

        std::vector<std::string>::iterator it_etapa2 = _secundarias.begin();
        for (; it_etapa2 != _secundarias.end(); it_etapa2++)
            if(*it_etapa2 ==  "Volte à Clara")
                break;

        if(pocao->completo() && it_etapa2 != _secundarias.end()){
            _secundarias.erase(it_etapa2);
        }
        else if(!pocao->completo() && Player->qtdItem("Pocao") == 0 && it_etapa1 == _secundarias.end()){
            _secundarias.push_back("Pegue a poção");
        }
        else if(!pocao->completo() && Player->qtdItem("Pocao") > 0 && it_etapa1 != _secundarias.end()){
            _secundarias.erase(it_etapa1);
            _secundarias.push_back("Volte à Clara");
        }
    }
}

std::string Objetivos::getPrincipal(){
    return this->_principal;
}

std::string Objetivos::getSecundaria(int n){
    return this->_secundarias[n];
}

int Objetivos::getTotalSecundarias(){
    return this->_secundarias.size();
}


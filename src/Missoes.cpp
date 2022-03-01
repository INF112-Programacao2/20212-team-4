#include "Missoes.hpp"

Missao::Missao(short int X, short int Y, unsigned char valor):
    Interacao("missao", X, Y, valor) {}

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
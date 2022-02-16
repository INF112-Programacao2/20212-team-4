#include <iostream>
#include <string>
#include "interacao.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "data.hpp"
#include <cmath>

/* FUNCOES DA CLASSE INTERACAO */
Interacao::Interacao(std::string nome, short int X, short int Y, unsigned char valor){
    _nome = nome;
    _x = X;
    _y = Y;
    _valor = valor;
    MAPA[_y][_x] = valor;
}

MissaoSecundaria::MissaoSecundaria(std::string nome, short int X, short int Y, unsigned char valor, short int recompensa, std::string npc):
    Interacao(nome,  X, Y, valor), _recompensa(recompensa),  _nomeNPC(npc), _coletado(false) {}


std::string Interacao::getNome(){
    return _nome;
}

short int Interacao::getPosicaoX(){
    return _x;
}

short int Interacao::getPosicaoY(){
    return _y;
}

char Interacao::getValor(){
    return _valor;
}

void Interacao::removeItem(unsigned char novoValor){
    _completo = true;
    MAPA[getPosicaoY()][getPosicaoX()] = novoValor; //remove o item da matriz, deixando a posicao livre para o personagem andar
}

bool Interacao::completo(){
    return _completo;
}

/* FUNCAO QUE VERIFICA SE O ITEM ESTA PROXIMO AO JOGADOR */
bool Interacao::itemProximo(unsigned char novoValor){
    if(MAPA[_y][_x] != '1' && sqrt(pow(((i+1) - this->_y), 2) + pow((j - this->_x), 2)) <= 1){
        removeItem(novoValor);
        return true;        
    }

    return false;
}

bool Interacao::itemProximo(){
    if((int)MAPA[i+2][j] > 50) return true;
    if((int)MAPA[i+1][j-1] > 50) return true;
    if((int)MAPA[i+1][j+1] > 50) return true;
    if((int)MAPA[i][j] > 50) return true;

    return false;
}

void MissaoSecundaria::get(){
    this->_coletado = true;
}

bool MissaoSecundaria::got(){
    return this->_coletado;
}

void MissaoSecundaria::finish(){
    this->_completo = true;
}



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

std::string Interacao::getNome(){
    return _nome;
}

short int Interacao::getPosicaoX(){
    return _x;
}

short int Interacao::getPosicaoY(){
    return _y;
}

void Interacao::setPosicaoX(short int x){
    this->_x = x;
}

void Interacao::setPosicaoY(short int y){
    this->_y = y;
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

bool Interacao::interacaoProxima(unsigned char c){
    if((int)MAPA[i+2][j] > (int)c) return true;
    else if((int)MAPA[i+1][j-1] > (int)c) return true;
    else if((int)MAPA[i+1][j+1] > (int)c) return true;
    else if((int)MAPA[i][j] > (int)c) return true;

    return false;
}

bool Interacao::missaoProxima(unsigned char c){
    if(MAPA[i+2][j] == c) return true;
    else if(MAPA[i+1][j-1] == c) return true;
    else if(MAPA[i+1][j+1] == c) return true;
    else if(MAPA[i][j] == c) return true;

    return false;
}



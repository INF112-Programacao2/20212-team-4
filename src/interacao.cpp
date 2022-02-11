#include <iostream>
#include <string>
#include "interacao.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "data.hpp"

/* FUNCOES DA CLASSE INTERACAO */
Interacao::Interacao(std::string nome, short int X, short int Y, unsigned char valor){
    _nome = nome;
    _x = X;
    _y = Y;
    _valor = valor;
    MAPA[_x][_y] = valor;
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

char Interacao::getValor(){
    return _valor;
}




/* FUNCOES DA CLASSE ITEM */
Item::Item(std::string nome, short int X, short int Y, char valor):
    Interacao(nome,X,Y, valor), _coletado(false) {}

void Item::removeItem(){
    _coletado = true;
    MAPA[getPosicaoX()][getPosicaoY()] = 1; //remove o item da matriz, deixando a posicao livre para o personagem andar
}

bool Item::Coletado(){
    return _coletado;
}


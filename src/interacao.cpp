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

char Interacao::getValor(){
    return _valor;
}

void Interacao::removeItem(unsigned char novoValor){
    _completo = true;
    MAPA[getPosicaoX()][getPosicaoY()] = novoValor; //remove o item da matriz, deixando a posicao livre para o personagem andar
}

bool Interacao::completo(){
    return _completo;
}

/* FUNCAO QUE VERIFICA SE O ITEM ESTA PROXIMO AO JOGADOR */
bool Interacao::itemProximo(unsigned char novoValor){
    if(i >= _y){
        if(pow((_x -j),2) == 1 ^ pow((_y - i),2) == 1){
            removeItem(novoValor);
            return true;
        }
        else
            return false;
    }
    else{
        std::cout << _y << " " << _x << "\n";
        std::cout << i << " " << j << "\n";
        if((_y == (i + 2)  && _x == j) || (pow((_x -j),2) + pow((_y - i),2) == 2)){
            removeItem(novoValor);
            std::cout << "OI\n" << std::endl;
            return true;
        }
        else 
            return false;
    }
}







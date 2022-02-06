#include <string>
#include "interacao.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Interacao::Interacao(std::string nome, short int X, short int Y){
    _nome = nome;
    _x = X;
    _y = Y;
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

char Interacao::setValor(char valor){
    _valor = valor;
}
char Interacao::getValor(){
    return _valor;
}



void Item::desenhaItem(){
    MAPA[_x][_y] = al_draw_bitmap(_imgItem);
}

void Item::Item(ALLEGRO_BITMAP img){
    _imgItem = al_load_bitmap(img);
}

void Item::removeItem(){
    MAPA[_x][_y] = 1;
}

void Item::coletaItem(){
    _coletado = true;
    void removeItem();
}
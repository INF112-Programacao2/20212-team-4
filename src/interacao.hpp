#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
/*
std::string COLETAVEIS[] = 
{"5", "Chave", "6", "Relogio", "7", "Poção", "8", "Dinheiro"};*/

/* CLASSE QUE DEFINE ATRIBUTOS BASICOS DE ELEMENTOS INTERATIVOS */
class Interacao {
    private:
    std::string _nome;  
    short int _x, _y; //coordenadas da matriz na qual o elemento está
    unsigned char _valor;  //valor na matriz correspondente ao elemento

    public:
    Interacao(std::string nome, short int X, short int Y, unsigned char valor); //construtor
    std::string getNome();
    short int getPosicaoX();
    short int getPosicaoY();
    char getValor();
};

/* ---------------------------- */

/* CLASSE QUE DEFINE OS ATRIBUTOS DOS ITENS COLETAVEIS */
class Item: public Interacao{  //classe filha de interação, herda os atributos
    private:
    bool _coletado;  //variavel que indica se o item esta no mapa ou foi coletado


    public:
    Item(std::string nome, short int X, short int Y, char valor);
    void removeItem(); 
    bool Coletado();
};

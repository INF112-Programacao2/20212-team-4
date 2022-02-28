#ifndef INTERACAO_HPP
#define INTERACAO_HPP

#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/* CLASSE QUE DEFINE ATRIBUTOS BASICOS DE ELEMENTOS INTERATIVOS */
class Interacao {
    protected:
        std::string _nome;  
        short int _x, _y; //coordenadas da matriz na qual o elemento está
        unsigned char _valor;  //valor na matriz correspondente ao elemento
        bool _completo; //variavel que indica se a interação foi concluída

    public:
        Interacao(std::string nome, short int X, short int Y, unsigned char valor); //construtor
        std::string getNome();
        short int getPosicaoX();
        short int getPosicaoY();
        char getValor();
        bool completo();
        void removeItem(unsigned char novoValor);
        bool itemProximo(unsigned char novoValor);
        bool interacaoProxima(unsigned char c);
};

class MissaoSecundaria : public Interacao{
    private:
        short int _recompensa;
        std::string _nomeNPC;
        bool _coletado;
    
    public:
        MissaoSecundaria(std::string nome, short int X, short int Y, unsigned char valor, short int recompensa, std::string npc);
        void get();
        void finish();
        bool got();
};

#endif
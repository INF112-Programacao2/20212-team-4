#ifndef MISSOES_HPP
#define MISSOES_HPP

#include "Grafico.hpp"
#include "interacao.hpp"

class Missao : public Interacao{
    protected:
        Dialogo _dialogo_missao;
        bool inicializada;

    public:
        Missao(short int X, short int Y, unsigned char valor);
        void setDialogo(Dialogo *falas);
        void setinicializada();
        bool getinicializada();
};

class MissaoSecundaria : public Missao{
    private:
        short int _recompensa;
        bool _itemColetado;
    
    public:
        MissaoSecundaria(short int X, short int Y, unsigned char valor, short int recompensa);
        void get();
        void finish();
        bool got();
        void pay(Protagonista *Player);
};

#endif
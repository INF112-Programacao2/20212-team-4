#ifndef MISSOES_HPP
#define MISSOES_HPP

#include "Grafico.hpp"
#include "interacao.hpp"

class Missao : public Interacao{
    protected:
        Dialogo _dialogo_missao;

    public:
        Missao(short int X, short int Y, unsigned char valor);
        void setDialogo(Dialogo *falas);
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
};

#endif
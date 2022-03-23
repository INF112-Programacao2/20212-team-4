#ifndef MISSOES_HPP
#define MISSOES_HPP

#include "Grafico.hpp"
#include "interacao.hpp"
#include <string>
#include <vector>


class Missao : public Interacao{
    protected:
        Dialogo _dialogo_missao;
        bool inicializada;

    public:
        Missao(short int X, short int Y, unsigned char valor);
        void setinicializadaTrue();
        bool getinicializada();
        short int _etapa;
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

class Objetivos{
    private:
        std::string _principal;
        std::vector<std::string> _secundarias;
    public:
        std::string getPrincipal();
        std::string getSecundaria(int n);
        int getTotalSecundarias();
        void atualizaPrincipal(Missao *Nivel1, Missao *Nivel2, Missao *Nivel3, Missao *Nivel4, Missao *Nivel5, Protagonista *Player);
        void atualizaSecundaria(MissaoSecundaria *espingarda, MissaoSecundaria *relogio, MissaoSecundaria *chave, MissaoSecundaria *pocao, Protagonista *Player);
};

#endif

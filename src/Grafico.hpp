#ifndef DIALOGO_HPP
#define DIALOGO_HPP

#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "interacao.hpp"
#include "Personagens.hpp"

class Dialogo{
    private:
        std::map <short int, bool> _fluxo;
        short int **_fluxo_incremento;
        std::string *_dialogos;
        short int posicao_atual_dialogo;
        short int posicao_atual_incremento;
        short int incremento_dialogoX, incremento_dialogoZ, incremento_dialogoSPACE;

        bool verificarTecla();

    public:
        Dialogo();
        Dialogo(std::string *dialogos, std::map <short int, bool> fluxo, short int **incrementos);
        bool dialogar(std::string npc, std::string **opcoes, bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao);
        void dialogar_lojista(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao);
}; 

bool enterToReset();
void redesenhar(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao);
void ajustarCamera(bool rel, bool chav, bool poc, bool d1, bool d2, bool d3, bool d4, short int &cont, Protagonista *Player, Interacao *botao);
void telaGameOver(bool reiniciar);

#endif
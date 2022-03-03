#ifndef SAVE_HPP
#define SAVE_HPP

#include "data.hpp"
#include "interacao.hpp"

class GameSave{
    public:
        void save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4, Interacao *d1, Interacao *d2, Interacao *d3, Interacao *d4);
        void read_save(Protagonista *Player, MissaoSecundaria *Sec1, MissaoSecundaria *Sec2, MissaoSecundaria *Sec3, MissaoSecundaria *Sec4, Interacao *Int1, 
            Interacao *Int2, Interacao *Int3, Interacao *d1, Interacao *d2, Interacao *d3, Interacao *d4);
};

#endif
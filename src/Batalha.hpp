#ifndef INF112_BATALHA
#define INF112_BATALHA

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class IBatalha {
public:
    virtual bool batalhar() = 0;
    
};

class Batalha1x1 : public IBatalha {
public:
    Inimigo *_vilao;
    Protagonista *_Player;
    Batalha1x1(Inimigo *vilao, Protagonista *player);
    virtual bool batalhar();
    
};

class Batalha1x2 : public IBatalha{
public:
    Inimigo *_vilao;
    Inimigo *_caixao;
    Inimigo *_jose;
    Protagonista *_Player;
    Batalha1x2(Inimigo *vilao, Inimigo *caixao, Protagonista *player);
    virtual bool batalhar();

};

class BatalhaFantasma : public IBatalha{
public:
    Inimigo *_vilao;
    Protagonista *_Player;
    MissaoSecundaria *_Bruxa;
    BatalhaFantasma (Inimigo *vilao, Protagonista *player, MissaoSecundaria *bruxa);
    virtual bool batalhar();
};

void desenhar(Protagonista *_Player, Inimigo *_vilao);
bool verificaTeclaBatalha(Protagonista *_Player, Inimigo *_vilao);

#endif


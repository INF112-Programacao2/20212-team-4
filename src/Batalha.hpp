#ifndef INF112_BATALHA
#define INF112_BATALHA

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class IBatalha {
public:
    virtual void batalhar() = 0;
    
};

class Batalha1x1 : public IBatalha {
private:
    Inimigo *_vilao;
    Protagonista *_Player;
public:
    Batalha1x1(Inimigo *vilao, Protagonista *player);
    virtual void batalhar();
    void desenhar1x1();
};

class Batalha1x2 : public IBatalha{
public:
    virtual void batalhar();

};

class BatalhaFantasma : public IBatalha{
    public:
        virtual void batalhar();
};


//bool VerificaTeclaBatalha();
#endif


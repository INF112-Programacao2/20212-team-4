#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Interacao {
    private:
    std::string _nome;
    short int _x, _y;
    char _valor;

    public:
    Interacao(std::string nome, short int X, short int Y);
    std::string getNome();
    short int getPosicaoX();
    short int getPosicaoY();
    char getValor();
    char setValor(char valor);
}



class Item: public Interacao{
    private:
    ALLEGRO_BITMAP = _imgItem;
    bool _coletado = false;
    public:
    Item();
    void desenhaItem();
    void coletaItem();
    void removeItem();
}

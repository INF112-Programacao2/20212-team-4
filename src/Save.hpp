#include "Personagens.hpp"

class GameSave{
    private:
        Protagonista *_player;
        //MissaoSecundaria *_missoes; 

    public:
        GameSave();
        ~GameSave();
        void save(Protagonista *Player /*, MissaoSecundaria &Sec1, MissaoSecundaria &Sec2, MissaoSecundaria &Sec3 */);
        void read_save();
        void check_point(Protagonista *Player /*, MissaoSecundaria &Sec1, MissaoSecundaria &Sec2, MissaoSecundaria &Sec3 */);
};
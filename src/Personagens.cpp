#include "Personagens.hpp"
#include <iostream>
#include <cstdlib>
#include "data.hpp"

ALLEGRO_EVENT evnome;

/** Getters dos atributos de um personagem qualquer.
*/
std::string Personagem::getNome(){
    return this->_nome;
}

short int Personagem::getVida(){
    return this->_vida;
}

short int Personagem::getMaxVida(){
    return this->_maxVida;
}

/** Setters dos atributos de um personagem qualquer.
*/
void Personagem::setNome(std::string nome){
    this->_nome = nome; 
}

void Personagem::setVida(int vida){
    this->_vida = vida;
}

void Personagem::setMaxVida(int vida){
    this->_maxVida = vida;
}

/** Getters dos atributos do protagonista.
*/
short int Protagonista::getDinheiro(){
    return this->_dinheiro;
}

short int Protagonista::getNivel(){
    return this->_nivel;
}

/** Setters dos atributos do protagonista.
*/
void Protagonista::setDinheiro(short int valor){
    this->_dinheiro = valor;
}

/* Métodos construtor do protagonista e dos inimigos
**/
Protagonista::Protagonista(short int vida, short int dinheiro){
    this->_vida = vida;
    this->_maxVida = vida;
    this->_dinheiro = dinheiro;
    this->_nivel = 1;
    this->_sortudo = false;
    this->_dialogo = false;
    this->_assombrado = false;
}

Inimigo::Inimigo(std::string nome, short int vida, short int total_ataques, short int total_curas){
    this->_nome = nome;
    this->_vida = this->_maxVida = vida;
    this->_total_ataques = total_ataques;
    this->_curas_usadas = 0;
    this->_total_curas = total_curas;
}

/* Outros métodos importantes para o funcionamento do jogo
**/
void Personagem::subAtaque(std::string ataque){
    std::map <std::string, short int*>::iterator it = this->_ataques.find(ataque);

    if(it != this->_ataques.end()){ // Caso encontre o ataque em questão, adiciona dano.
        this->_ataques.erase(it);
    }

}

void Personagem::addAtaque(std::string ataque, short int min, short int max){
    std::map <std::string, short int*>::iterator it = this->_ataques.find(ataque);

    if(it != this->_ataques.end()){ // Caso encontre o ataque em questão, adiciona dano.
        it->second[0] = min;
        it->second[0] = max;
    }
    else{ // se não, insere
        short int *dano = new short int[2];
        dano[0] = min;
        dano[1] = max;
        this->_ataques.insert(std::pair<std::string, short int*>(ataque, dano));
    }
}

bool Personagem::hasAtaque(std::string ataque){
    std::map <std::string, short int*>::iterator it = this->_ataques.find(ataque);

    if(it != this->_ataques.end()) // Caso encontre o ataque em questão, adiciona dano.
        return true;

    else // se não, insere
        return false;
}

bool Personagem::isDead(){
    if(this->_vida <= 0)
        return true;
    else
        return false;
}

void Protagonista::nextLevel(){
    this->_nivel++;
}

void Protagonista::setNivel(short int nivel){
    this->_nivel = nivel;
}

void Personagem::curarVida(short int cura){
    this->_vida += cura;
}

void Protagonista::comer(){
    this->curarVida(10);
    this->subItem("Comida", 1);
}

std::string Inimigo::atacar(Protagonista &alvo){
    std::map <std::string, short int*>::iterator it;
    std::string nome;
    
    RANDOM:
        // Gera um valor pseudo-aleatório que irá definir qual será o ataque do inimigo.
        it = this->_ataques.begin();
        short int attack = rand()%this->_total_ataques, i;

        for(int i = 0; i < attack; i++)
            it++;

        /*
        * Caso o segundo valor do std::map seja negativo (dano), o player será atacado.
        *
        * Caso o segundo valor do std::map seja positivo (cura) e o inimigo não está com a vida cheia, 
        * ele cura a vida.
        * 
        * Se não, busca um novo valor pseudo-aleatório.
        * 
        */
        if(it->second[1] < 0){
            alvo.setVida(alvo.getVida() + it->second[1]);
            if(alvo.getVida() < 0) alvo.setVida(0);
        }
        else if(it->second[1] > 0 && this->_vida != this->_maxVida){
            this->curarVida(it->second[1]);
            this->_curas_usadas++;

            if(this->_curas_usadas == this->_total_curas && hasAtaque("Cura")){
                this->subAtaque("Cura");
                this->_total_ataques--;
            }
        }
        else
            goto RANDOM;

    return it->first;
}

void Protagonista::addItem(std::string item, short int qtd){
    std::map<std::string, short int>::iterator it = this->_inventario.find(item);

    if(it != this->_inventario.end())
        it->second += qtd;
    else
        this->_inventario.insert(std::pair<std::string, short int> (item, qtd));
}

void Protagonista::subItem(std::string item, short int qtd){
    std::map<std::string, short int>::iterator it = this->_inventario.find(item);

    if(it != this->_inventario.end())
        it->second -= qtd;
}

short int Protagonista::qtdItem(std::string item){
    std::map<std::string, short int>::iterator it = this->_inventario.find(item);

    if(it != this->_inventario.end())
        return it->second;
    else return 0;
}

void Protagonista::escolherNome(){
    this->_nome = "";

    while(true){
        al_wait_for_event(event_queue, &evnome);

        al_draw_scaled_bitmap(tela_fundo, 0, 0, 1920, 1080, 0, 0, 1920*(res_x_comp/1920.0), 1080*(res_y_comp/1080.0), 0);
        al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(620), RES_HEIGHT(200), 0,"ESCOLHA SEU NOME");
        al_draw_scaled_bitmap(player_f1, 0, 0, res_x_player, res_y_player, RES_WIDTH(880), RES_HEIGHT(400), RES_WIDTH(res_x_player*7), RES_HEIGHT(res_y_player*7), 0);

        al_draw_scaled_bitmap(caixa_nome, 0, 0, 322, 73, RES_WIDTH(650), RES_HEIGHT(710), 322*(res_x_comp/1920.0)*2, 73*(res_y_comp/1080.0)*2, 0);
        al_draw_textf(font_titulo, al_map_rgb(60,25,97), RES_WIDTH(720), RES_HEIGHT(700), 0, "%s", this->_nome.c_str());

        if(this->_nome != ""){
            al_draw_textf(font15, al_map_rgb(58,15,43), RES_WIDTH(610), 0.85*res_y_comp, 0,"Aperte               para continuar");
            al_draw_scaled_bitmap(botaoreiniciar, 0,  0, 34, 18, RES_WIDTH(770), 0.85*res_y_comp, RES_WIDTH(34*ZOOM), RES_HEIGHT(18*ZOOM), 0);
        }

        if(verificarTeclaNome()) break;
        al_flip_display();
    }
}

bool Protagonista::verificarTeclaNome(){
    if(evnome.type == ALLEGRO_EVENT_KEY_DOWN){
        keys[evnome.keyboard.keycode] = true;
        al_play_sample(type_sound, 0.8, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

        if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_A]){
            this->_nome += "A";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_B]){
            this->_nome += "B";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_C]){
            this->_nome += "C";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_D]){
            this->_nome += "D";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_E]){
            this->_nome += "E";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_F]){
            this->_nome += "F";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_G]){
            this->_nome += "G";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_H]){
            this->_nome += "H";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_I]){
            this->_nome += "I";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_J]){
            this->_nome += "J";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_K]){
            this->_nome += "K";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_L]){
            this->_nome += "L";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_M]){
            this->_nome += "M";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_N]){
            this->_nome += "N";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_O]){
            this->_nome += "O";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_P]){
            this->_nome += "P";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_Q]){
            this->_nome += "Q";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_R]){
            this->_nome += "R";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_S]){
            this->_nome += "S";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_T]){
            this->_nome += "T";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_U]){
            this->_nome += "U";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_V]){
            this->_nome += "V";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_W]){
            this->_nome += "W";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_X]){
            this->_nome += "X";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_Y]){
            this->_nome += "Y";
        }
        else if(this->_nome.length() < 11 && keys[ALLEGRO_KEY_Z]){
            this->_nome += "Z";
        }
        else if(keys[ALLEGRO_KEY_BACKSPACE] && this->_nome.length() > 0){
            this->_nome = this->_nome.substr(0, this->_nome.length()-1);
        }
        else if(this->_nome.length() > 0 && keys[ALLEGRO_KEY_ENTER]){
            return true;
        }

        keys[evnome.keyboard.keycode] = false;
    }

    return false;
}
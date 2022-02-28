#include "Personagens.hpp"
#include <iostream>
#include <cstdlib>
#include "data.hpp"

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
}

Inimigo::Inimigo(std::string nome, short int vida, short int total_ataques, short int cura){
    this->_nome = nome;
    this->_vida = this->_maxVida = vida;
    this->_total_ataques = total_ataques;
    this->_cura = cura;
}

/* Outros métodos importantes para o funcionamento do jogo
**/
void Personagem::addAtaque(std::string ataque, short int dano){
    std::map <std::string, short int>::iterator it = this->_ataques.find(ataque);

    if(it != this->_ataques.end()) // Caso encontre o ataque em questão, adiciona dano.
        it->second = dano;
     else // se não, insere
        this->_ataques.insert(std::pair<std::string, short int>(ataque, dano));
}

bool Personagem::isDead(){
    if(this->_vida <= 0)
        return true;
    else
        return false;
}

template<class ENEMY_OR_PLAYER>
void Personagem::atacar(ENEMY_OR_PLAYER &alvo, short int dano){
    // Altera a vida do personagem para a nova, subtraída pelo dano.
    alvo.setVida(alvo.getVida()+dano); // O dano é sempre um valor negativo.
}

void Protagonista::nextLevel(){
    this->_nivel++;

    // Define as posições iniciais pra cada nível.
    if(this->_nivel == 2){
        i = 29;
        j = 48;
        TELA_X_MAPA = 35;

        this->_maxVida += 10;
        this->_vida += 10;        

        resetCamera(15, 5);
    }

    else if(this->_nivel == 3){
        i = 56;
        j = 69;

        this->_maxVida += 10;
        this->_vida += 10;  

        TELA_X_MAPA = 60;
        TELA_Y_MAPA = 50;

        EIXO_X_PLAYER_TELA = 958;
        EIXO_Y_PLAYER_TELA = 572;    

        resetCamera(11, 5); 
    }

    else if(this->_nivel == 4){
        i = 48;
        j = 19;

        this->_maxVida += 10;
        this->_vida += 10;  

        TELA_X_MAPA = 10;
        TELA_Y_MAPA = 45;

        EIXO_X_PLAYER_TELA = 958;
        EIXO_Y_PLAYER_TELA = 380;    

        resetCamera(12, 2);  
    }

    else if(this->_nivel == 5){
        i = 29;
        j = 86;

        this->_maxVida += 10;
        this->_vida += 10;  

        TELA_X_MAPA = 72;
        TELA_Y_MAPA = 23;

        EIXO_X_PLAYER_TELA = 1280;
        EIXO_Y_PLAYER_TELA = 572;  

        resetCamera(16, 5); 
    }    
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

void Inimigo::atacar(Protagonista &alvo){
    std::map <std::string, short int>::iterator it;
    
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
        if(it->second < 0)
            alvo.setVida(alvo.getVida()+it->second);
        else if(it->second > 0 && this->_vida != this->_maxVida)
            this->curarVida(this->_cura);
        else
            goto RANDOM;
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

void Protagonista::entregar(/*MissaoSecundaria &missao*/){
    // if(this->qtdItem(missao.getNome()) == 1){
    //     this->subItem(missao.getNome(), 1);
        // missao.pay(*this);
        // missao.get();
    // }
}

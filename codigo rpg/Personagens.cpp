#include "Personagens.hpp"
#include <iostream>
#include <cstdlib>

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

template <class ENEMY_OR_PLAYER>
void Personagem::atacar(ENEMY_OR_PLAYER &alvo, short int dano){
    // Altera a vida do personagem para a nova, subtraída pelo dano.
    alvo.setVida(alvo.getVida()+dano); // O dano é sempre um valor negativo.
}

void Protagonista::nextLevel(int addVida){
    this->_nivel++;
    this->_maxVida += addVida;
    this->_vida += addVida;
}

void Personagem::curarVida(short int cura){
    this->_vida += cura;
}

void Inimigo::randomAtaqueInimigo(Protagonista &player){
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
            this->atacar(player, it->second);
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

short int Protagonista::qtdItem(std::string item){
    std::map<std::string, short int>::iterator it = this->_inventario.find(item);

    if(it != this->_inventario.end())
        return it->second;
    else return 0;
}

void Protagonista::pegarItem(std::string objeto){
    if(this->qtdItem(objeto) == 0)
        this->addItem(objeto, 1);
}

bool Protagonista::entregar(std::string objeto, short int recompensa){
    if(this->qtdItem(objeto) == 1){
        addItem(objeto, -2); // Altera para -1 para que não seja mais possível pegar outro.
        this->_dinheiro += recompensa;

        return true;
    }

    return false;
}
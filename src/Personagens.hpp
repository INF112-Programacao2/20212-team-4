#ifndef PERSONAGENS_HPP
#define PERSONAGENS_HPP

#include <string>
#include <map>

/* CLASSE QUE DEFINE ATRIBUTOR DE UM PERSONAGEM QUALQUER */
/**
 * @class Personagem
 *
 * @brief Esta classe define os atributos e métodos padrão para um personagem qualquer, seja inimigo ou player.
 * 
 */
class Personagem{
    protected:
        std::string _nome;
        short int _maxVida;
        short int _vida;
        std::map <std::string, short int> _ataques;

    public:
        /** Getters dos atributos de um personagem qualquer.
        */
        short int getMaxVida();
        short int getVida();
        std::string getNome();

        /** Setters dos atributos de um personagem qualquer.
        */
        void setNome(std::string nome);
        void setVida(int vida);
        void setMaxVida(int vida);

        // Outros métodos importantes para o funcionamento do jogo
        /**
         * @brief Adiciona um ataque ao std::map que representa a lista de ataques de um
         * inimigo ou player.
         * 
         * @param ataque nome do ataque.
         * @param dano dano que o ataque dá, SEMPRE NEGATIVO.
         */
        void addAtaque(std::string ataque, short int dano);

        /**
         * @brief Verifica se um personagem, inimigo ou protagonista morreu.
         * 
         */
        bool isDead();

        /**
         * @brief Reduzir a vida do alvo, seja ele inimigo ou player.
         * 
         * @param ENEMY_OR_PLAYER a classe que será atacada: protagonista ou inimigo.
         * @param alvo quem será atacado.
         * @param dano dano que o ataque dá, SEMPRE NEGATIVO.
         */
        template<class ENEMY_OR_PLAYER>
        void atacar(ENEMY_OR_PLAYER &alvo, short int dano);

        /**
         * @brief Ao invés de atacar, em um turno, o inimigo ou player pode acrescentar um
         * valor à sua vida atual.
         * 
         * @param cura o quanto de vida que será curada.
         */
        void curarVida(short int cura);
};

// Classes que herdam atributos de Personagem.
/* CLASSE QUE DEFINE ATRIBUTOS DO PROTAGONISTA */
/**
 * @class Protagonista
 *
 * @brief Esta classe define os atributos e métodos utilizados apenas pelo protagonista.
 * 
 */
class Protagonista : public Personagem{
    private:
        short int _dinheiro;
        short int _nivel;
        std::map<std::string, short int> _inventario;

    public:
        bool _dialogo;

        // Método Construtor.
        Protagonista(short int vida, short int dinheiro);

        /** Setters dos atributos do protagonista.
        */
        void setDinheiro(short int valor);

        /** Getters dos atributos do protagonista.
        */
        short int getDinheiro();
        short int getNivel();
        void setNivel(short int nivel);

        /**
         * @brief Passa o protagonista de nível, acrescentando em +1 o atributo _nivel.
         * 
         */
        void nextLevel();

        /**
         * @brief Adiciona uma unidade de um ítem ao inventário.
         * 
         * @param item o nome do ítem que se deseja adicionar.
         * @param qtd a quantidade do ítem que se deseja reduzir.
         */
        void addItem(std::string item, short int qtd);

        /**
         * @brief Reduz um ítem do inventário em qtd unidades.
         * 
         * @param item o nome do ítem que se deseja adicionar.
         * @param qtd a quantidade do ítem que se deseja reduzir.
         */
        void subItem(std::string item, short int qtd);

        /**
         * @brief Retorna a quantidade de um ítem no inventário. Caso não haja, 
         * retorna zero.
         * 
         * @param item o nome do ítem que se deseja adicionar.
         * 
         */
        short int qtdItem(std::string item);

        /**
         * @brief Entrega um objeto para um NPC.
         * 
         * @details Ao verificar se o ítem está no inventário, retorna true dizendo que é
         * possível entregar ou false, se não. Acrescenta ao protagonista a recompensa e informa
         * a quantidade como -1. Isto é, não há no inventário e também não é mais possível pegá-lo
         * no mapa.
         * 
         * @param objeto o nome do ítem que se deseja adicionar.
         * @param recompensa valor da recompensa.
         */
        void entregar(/*MissaoSecundaria &missao*/);

        /**
        * @brief Consome alimento para curar a vida do protagonista
        *
        */
        void comer();

        /**
         * @brief Retorna se está dialogando.
         * 
         */
        bool dialogando();
};

/* CLASSE QUE DEFINE ATRIBUTOS DOS INIMIGOS */
/**
 * @class Protagonista
 *
 * @brief Esta classe define os atributos e métodos utilizados apenas pelos inimigos.
 * 
 */
class Inimigo : public Personagem{
    private:
        short int _cura;
        short int _total_ataques;
        
    public:
        /*Método Construtor
        **/
        Inimigo(std::string nome, short int vida, short int total_ataques, short int cura);

        /**
         * @brief Gera um valor pseudo-aleatório, que irá definir qual ataque será realizado por um inimigo.
         * 
         * @param player o personagem que irá ser alvo do dano.
         */
        void atacar(Protagonista &alvo);
};

#endif
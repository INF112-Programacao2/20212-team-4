#include <iostream>
#include "data.hpp"

/* PERSONAGENS  */
Protagonista Player(10, 3);
Inimigo Ambrosio("Ambrosio", 12, 3, 2);
Inimigo Xerife_Espeto("Xerife Espeto", 24, 4, 4);
Inimigo Jose_do_Caixao("Jose do caixao", 32, 4, 3);
Inimigo Caixao_do_Jose("Caixao do Jose", 15, 2, 1);
Inimigo Geraldina("Geraldina", 45, 4, 3);
Inimigo Silvio("Silvio", 60, 4, 5);

int main(int argc, char **argv){
    if(inicializaJogo() == true){
        
    }

    return 0;
}

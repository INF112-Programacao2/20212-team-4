#include "Personagens.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <math.h>

/* FUNÇÃO PARA IDENTIFICAR SE O ITEM ESTA PROXIMO */
bool itemProximo(short int Xitem, short int Yitem){
    if(Yitem >= i){
        if(pow((Xitem-j),2) == 1 ^ pow((Yitem - i),2) == 1){
            return true;
        }
    }
    else{
        if((Yitem == (i + 2)  && Xitem == j) || (pow((Xitem-j),2) + pow((Yitem - i),2) == 2)){
            return true;
        }
    }
}

/* FUNCAO PARA DESENHAR OS ITENS */
void desenhaItem(){
    
}

void adicionaItem(Interacao item){
    if(ev0.type == ALLEGRO_EVENT_KEY_DOWN){
        if(ev0.keyboard.keycode==ALLEGRO_KEY_SPACE){
            Player.addItem(item.getNome());
        }
    }
}
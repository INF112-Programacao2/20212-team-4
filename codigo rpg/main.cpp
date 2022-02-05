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
        while(1){
            ALLEGRO_EVENT ev0;
            al_wait_for_event(event_queue, &ev0);
            if(ev0.type == ALLEGRO_EVENT_TIMER){
                if(redraw && al_is_event_queue_empty(event_queue)){
                    al_draw_scaled_bitmap(map, 58*x, 22*y, res_x_comp, res_y_comp, 0, 0, res_x_comp*(res_x_comp/1920.0)*5, res_y_comp*(res_y_comp/1080.0)*5, 0);
                    al_flip_display();
                }
            }
            if(ev0.type == ALLEGRO_EVENT_KEY_DOWN){
                switch (ev0.keyboard.keycode){
                    case ALLEGRO_KEY_ESCAPE:
                        return 0;
                };
            }
            if(ev0.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                return 0;
        }
    }

    return 0;
}


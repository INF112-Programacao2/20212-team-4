#include "AllegroElementsException.hpp"

BitmapNotFound::BitmapNotFound(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer){
    this->_display = display;
    this->_timer = timer;
}

DisplayNotCreated::DisplayNotCreated(ALLEGRO_TIMER *timer){
    this->_timer = timer;
}

EventQeueNotCreated::EventQeueNotCreated(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer){
    this->_display = display;
    this->_timer = timer;
}

const char *BitmapNotFound::what() const noexcept{
    al_destroy_display(this->_display);
    al_destroy_timer(this->_timer);
    return "Nao foi possivel abrir o jogo devido a falta de um bitmap\n";
}

const char *InitNotDone::what() const noexcept{
    return "Nao foi possivel abrir o jogo, pois um elemento do Allegro nao pode ser inicializado\n";
}

const char *TimerNotCreated::what() const noexcept{
    return "Nao foi possivel abrir o jogo, pois o Allegro nao pode ser inicializado\n";
}

const char *DisplayNotCreated::what() const noexcept{
    al_destroy_timer(this->_timer);
    return "Nao foi possivel abrir o jogo, pois o display nao pode ser inicializado\n";
}

const char *EventQeueNotCreated::what() const noexcept{
    al_destroy_display(this->_display);
    al_destroy_timer(this->_timer);
    return "Nao foi possivel abrir o jogo, pois a fila de eventos nao pode ser inicializado\n";
}

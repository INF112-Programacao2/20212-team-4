#ifndef FILENOTFOUND_HPP
#define FILENOTFOUND_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

class BitmapNotFound : public std::exception{
    private:
        ALLEGRO_DISPLAY *_display;
        ALLEGRO_TIMER *_timer;

    public:
        BitmapNotFound(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer);
        virtual const char* what() const noexcept override;
};

class InitNotDone : public std::exception{
    public:
        virtual const char* what() const noexcept override;
};

class TimerNotCreated : public std::exception{
    public:
        virtual const char* what() const noexcept override;
};

class DisplayNotCreated : public std::exception{
    private:
        ALLEGRO_TIMER *_timer;

    public:
        DisplayNotCreated(ALLEGRO_TIMER *timer);
        virtual const char* what() const noexcept override;
};

class EventQeueNotCreated : public std::exception{
    private:
        ALLEGRO_DISPLAY *_display;
        ALLEGRO_TIMER *_timer;

    public:
        EventQeueNotCreated(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer);
        virtual const char* what() const noexcept override;
};

#endif
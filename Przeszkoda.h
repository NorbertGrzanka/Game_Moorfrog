
#ifndef SNAKE_PRZESZKODA_H
#define SNAKE_PRZESZKODA_H

#include "Prostokat.h"
#include "zaba.h"
class Przeszkoda: public Prostokat {

public:
    Przeszkoda(  sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar,string nazwa_tekstury);

    bool kolizja(zaba zabka);

    void set_predkosc(double predkosc_);

};


#endif //SNAKE_PRZESZKODA_H

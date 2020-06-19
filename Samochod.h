//
// Created by Norbi on 27.05.2020.
//

#ifndef SNAKE_SAMOCHOD_H
#define SNAKE_SAMOCHOD_H


#include "Przeszkoda.h"
class Samochod: public Przeszkoda {

public:

    Samochod(  sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar);

};




#endif //SNAKE_SAMOCHOD_H

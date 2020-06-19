#ifndef FROGGER_ZABA_H
#define FROGGER_ZABA_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using  namespace std;

class zaba {
    double predkosc;
    sf::Texture tekstura[7];
    sf::RectangleShape prostokat;
    sf::RenderWindow & okno;
public:
    sf::RectangleShape get_prostokat();

    zaba(sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar);

    void ruch();

    void lewo();

    void prawo();

    void gora();


};

#endif //FROGGER_ZABA_H

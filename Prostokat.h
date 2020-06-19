
#ifndef FROGGER_PROSTOKAT_H
#define FROGGER_PROSTOKAT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using  namespace std;

class Prostokat {
protected:
    double predkosc;
    sf::Texture tekstura;
    sf::RectangleShape prostokat;
    sf::RenderWindow & okno;
public:
    sf::Vector2f getPosition(); //klasa matka przeszkody
    sf::Vector2f setPosition(double x,double y);
    sf::Vector2f getRozmiar();

    Prostokat(  sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar,string nazwa_tekstury);

    void ruch();

    void rysuj();


};


#endif

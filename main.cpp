#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "plansza.h"


int main()
{
    sf::RenderWindow okno( sf::VideoMode( 800, 800 ), "Frog" );
    okno.setFramerateLimit(21);
    Plansza *p = nullptr;
    sf::Texture textura;
    sf::Sprite tlo;
    sf::Texture pepe;
    sf::Sprite pepe1;
    textura.loadFromFile("menu1.png");
    tlo.setTexture(textura);

    bool wybor =true;

    while( okno.isOpen() ) {

        sf::Event event;

        while (okno.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                okno.close();

        }
        okno.clear();
        if (wybor) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                p=new Plansza(800,800,okno);
                wybor = false;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                return 0;
            }
            okno.draw(tlo);

        } else {
            if (p->rysowanie_planszy())

            {
                wybor=true;
                delete(p);
            }

        }

        okno.display();

    }
    return 0;
}

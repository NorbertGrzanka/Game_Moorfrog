#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "plansza.h"
#include "Prostokat.cpp"


Plansza::Plansza(float szerokosc, float wysokosc, sf::RenderWindow &okno) :okno(okno),szerokosc(szerokosc),wysokosc(wysokosc)
{
font.loadFromFile("arial.ttf");
text.setFont(font);
text.setFillColor(sf::Color::Black);
text.setOutlineColor(sf::Color::Green);
text.setOutlineThickness(2);
text.setCharacterSize(30);
text.setPosition(0,okno.getSize().y-50);
szybkosc=2;
punkty=0;
textura.loadFromFile("woda.png");
tlo.setTexture(textura);
zab= new zaba(okno,sf::Vector2f({float(szerokosc/2),float(wysokosc-50)}),sf::Vector2f({50,49}));
przeskody.resize(ILOSC_RZEDOW);
for(int i=0; i<ILOSC_RZEDOW; i++)
{
for(int j=0; j<ILOSC_PRESZKOD; j++)
{
float wymiar=(rand()%100+80.0);

if(i%2==0) {    przeskody[i].push_back(new Kloda(okno, sf::Vector2f({float(szerokosc * j / 6.0), float(100 * i)}),
        sf::Vector2f({wymiar, 50})));

przeskody[i][j]->set_predkosc(-szybkosc);

}
else {
przeskody[i].push_back(new Samochod(okno,sf::Vector2f({float(szerokosc*j/6.0),float(100*i)}),sf::Vector2f({wymiar,50})));
przeskody[i][j]->set_predkosc(szybkosc);
}
}
}
}

bool Plansza::rysowanie_planszy()
{
    okno.draw(tlo);
    for(int i=0; i<ILOSC_RZEDOW; i++) {
        for (int j = 0; j < ILOSC_PRESZKOD; j++) {
            if(i%2==0)
                przeskody[i][j]->set_predkosc(-szybkosc);
            else
                przeskody[i][j]->set_predkosc(szybkosc);
            przeskody[i][j]->rysuj();
            przeskody[i][j]->ruch();
            zmienpozycja();
            if(  przeskody[i][j]->kolizja(*zab))
                return true;

        }
    }
    zab->ruch(); //sterowanie zaby

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        zab->lewo();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        zab->prawo();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        zab->gora();
    text.setString(to_string(punkty));
    spr_punktu();
    okno.draw(text);
    return false;
}
bool Plansza::spr_punktu()

{
    if(zab->get_prostokat().getPosition().y<0) {

        punkty += 10;
        szybkosc++;
        delete(zab);
        zab= new zaba(okno,sf::Vector2f({float(szerokosc/2),float(wysokosc-50)}),sf::Vector2f({50,49}));
    }

    return false;
}
void Plansza::zmienpozycja()
{
    for(int i=0; i<ILOSC_RZEDOW; i++) {
        for (int j = 0; j < ILOSC_PRESZKOD; j++) {
            if (     przeskody[i][j]->getPosition().x+przeskody[i][j]->getRozmiar().x<=0 )
            {
                przeskody[i][j]->setPosition(szerokosc-5,przeskody[i][j]->getPosition().y);
            }
        }
    }

    for(int i=0; i<ILOSC_RZEDOW; i++) {
        for (int j = 0; j < ILOSC_PRESZKOD; j++) {
            if (     przeskody[i][j]->getPosition().x>=szerokosc )
            {
                przeskody[i][j]->setPosition(-przeskody[i][j]->getRozmiar().x+5,przeskody[i][j]->getPosition().y);
            }
        }
    }
}
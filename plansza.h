
#ifndef FROGGER_PLANSZA_H
#define FROGGER_PLANSZA_H

#include <vector>
#include "Przeszkoda.h"
#include "Kloda.h"
#include "Samochod.h"
#include "zaba.h"
#define  ILOSC_RZEDOW 6
#define  ILOSC_PRESZKOD 6
class Plansza {
    int punkty;
    sf::Font font;
    sf::Text text;
std::vector< vector<Przeszkoda*> > przeskody ;
sf::Texture textura;
sf::Sprite tlo;
    sf::RenderWindow & okno;
    double szerokosc;
    double wysokosc;
    double szybkosc;
    zaba *zab;



public:

    Plansza(float szerokosc, float wysokosc,sf::RenderWindow & okno );   //dodawanie tla, czcionki i ich wlasciwosci, ustawiamy zabe oraz przeszkody

    bool rysowanie_planszy(); // przewijanie przeszkod

    bool spr_punktu(); // liczenie punktów, sprawdza czy zaba wyszla za gorna czesc ekrany, jesli tak to dodaje 10 pkt i generuje nowa zabe

    void zmienpozycja(); // zmiana pozycji przeszkoda, czyli przewiajnie przeszkod



};


#endif //FROGGER_PLANSZA_H

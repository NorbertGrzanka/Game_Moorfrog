
#include "Przeszkoda.h"

Przeszkoda::Przeszkoda(  sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar,string nazwa_tekstury):Prostokat(  okno,  pozycja,  rozmiar, nazwa_tekstury)
{}


bool Przeszkoda::kolizja(zaba zabka)

    {
        if(prostokat.getPosition().x<=zabka.get_prostokat().getPosition().x &&
           prostokat.getPosition().x + prostokat.getSize().x>=zabka.get_prostokat().getPosition().x &&
           prostokat.getPosition().y<zabka.get_prostokat().getPosition().y &&
           prostokat.getPosition().y + prostokat.getSize().y>zabka.get_prostokat().getPosition().y)

            return true;

        if(prostokat.getPosition().x<=zabka.get_prostokat().getPosition().x &&
           prostokat.getPosition().x + prostokat.getSize().x>=zabka.get_prostokat().getPosition().x &&
           prostokat.getPosition().y<zabka.get_prostokat().getPosition().y+ zabka.get_prostokat().getSize().y&&
           prostokat.getPosition().y + prostokat.getSize().y>=zabka.get_prostokat().getPosition().y+ zabka.get_prostokat().getSize().y)
            return true;

        if(prostokat.getPosition().x<=zabka.get_prostokat().getPosition().x + zabka.get_prostokat().getSize().x&&
           prostokat.getPosition().x + prostokat.getSize().x>=zabka.get_prostokat().getPosition().x + zabka.get_prostokat().getSize().x&&
           prostokat.getPosition().y<zabka.get_prostokat().getPosition().y &&
           prostokat.getPosition().y + prostokat.getSize().y>zabka.get_prostokat().getPosition().y)
            return true;

        if(prostokat.getPosition().x<=zabka.get_prostokat().getPosition().x + zabka.get_prostokat().getSize().x&&
           prostokat.getPosition().x + prostokat.getSize().x>=zabka.get_prostokat().getPosition().x + zabka.get_prostokat().getSize().x&&
           prostokat.getPosition().y<zabka.get_prostokat().getPosition().y+ zabka.get_prostokat().getSize().y&&
           prostokat.getPosition().y + prostokat.getSize().y>zabka.get_prostokat().getPosition().y+ zabka.get_prostokat().getSize().y)
            return true;
        return false;
    }
 void Przeszkoda::set_predkosc(double predkosc_)
 {
     predkosc=predkosc_;
 }
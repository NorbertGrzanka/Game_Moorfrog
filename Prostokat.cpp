
#include "Prostokat.h"

Prostokat::Prostokat(  sf::RenderWindow & okno, sf::Vector2f pozycja, sf::Vector2f rozmiar,string nazwa_tekstury):okno(okno)

{
    if( !tekstura.loadFromFile( nazwa_tekstury ) )
        cerr << "Nie można załadować grafiki\n";
    std::cout<<nazwa_tekstury;
    prostokat.setPosition(pozycja);

    prostokat.setTexture(&tekstura);
    prostokat.setSize(rozmiar);
}

void Prostokat::ruch()
    {
        prostokat.move(predkosc,0);
    }

void Prostokat::rysuj()
    {
        okno.draw(prostokat);
    }

sf::Vector2f Prostokat::getRozmiar()
{
    return prostokat.getSize();
}

sf::Vector2f Prostokat::setPosition(double x, double y)
{
    prostokat.setPosition(x,y);
    return {};
}

sf::Vector2f Prostokat::getPosition()
{
    return prostokat.getPosition();
}
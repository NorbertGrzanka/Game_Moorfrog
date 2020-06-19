#include "zaba.h"

zaba::zaba(sf::RenderWindow &okno, sf::Vector2f pozycja, sf::Vector2f rozmiar):okno(okno)
{
    for(int i=1; i<=7; i++)

        tekstura[i-1].loadFromFile("f"+to_string(i)+".png"); //do tablicy wczytaujemy kolejne sprity ruchu
    prostokat.setPosition(pozycja);
    prostokat.setSize(rozmiar);

}

void zaba::ruch()
{
    static int i=0;
    prostokat.setTexture(&tekstura[i]);
    okno.draw(prostokat);
    i++;
    if(i==7)
        i=0;
}

void zaba::lewo()
{
    prostokat.move(-10,0);
}

void zaba::prawo()
{
    prostokat.move(10,0);
}

void zaba::gora()
{
    prostokat.move(0, -50);
}

sf::RectangleShape zaba::get_prostokat()
{
    return prostokat;
}
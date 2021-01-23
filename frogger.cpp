#include <SFML/Graphics.hpp>

int main()
{
    //obfects
    sf::RenderWindow window(sf::VideoMode(450, 450), "SFML works!");
    sf::RectangleShape start_bar;
    sf::RectangleShape middle_bar;
    sf::RectangleShape finish_bar;
    start_bar.setSize(sf::Vector2f(450.0,50.0));
    start_bar.setPosition(sf::Vector2f(0.0f,400.0f));
    middle_bar.setSize(sf::Vector2f(450.0,50.0));
    middle_bar.setPosition(sf::Vector2f(0.0f,200.0f));
    finish_bar.setSize(sf::Vector2f(450.0,50.0));
    finish_bar.setPosition(sf::Vector2f(0.0f,0.0f));

    //functions
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;            
            default:
                break;
            }
        }
        
        //update the game
        window.clear();
        window.draw(start_bar);
        window.draw(middle_bar);
        window.draw(finish_bar);
        window.display();
    }

    return 0;
}

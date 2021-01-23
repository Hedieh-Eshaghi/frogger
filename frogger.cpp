#include <SFML/Graphics.hpp>

int main()
{
    //obfects
    sf::RenderWindow window(sf::VideoMode(450, 450), "SFML works!");
    sf::RectangleShape start_bar;
    sf::RectangleShape middle_bar;
    sf::RectangleShape finish_bar;
    sf::RectangleShape truck1;
    sf::RectangleShape truck2;
    sf::RectangleShape truck3;
    start_bar.setSize(sf::Vector2f(450.0,50.0));
    start_bar.setPosition(sf::Vector2f(0.0f,400.0f));
    middle_bar.setSize(sf::Vector2f(450.0,50.0));
    middle_bar.setPosition(sf::Vector2f(0.0f,200.0f));
    finish_bar.setSize(sf::Vector2f(450.0,50.0));
    finish_bar.setPosition(sf::Vector2f(0.0f,0.0f));
    truck1.setSize(sf::Vector2f(120,50));
    truck1.setFillColor(sf::Color::Red);
    truck1.setPosition(sf::Vector2f(0.0,250.0));
    truck2.setSize(sf::Vector2f(120,50));
    truck2.setFillColor(sf::Color::Red);
    truck2.setPosition(sf::Vector2f(450.0,300.0));
    truck3.setSize(sf::Vector2f(120,50));
    truck3.setFillColor(sf::Color::Red);
    truck3.setPosition(sf::Vector2f(0.0,350.0));

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
        truck1.move(0.01,0.0);
        truck2.move(-0.02,0.0);
        truck3.move(0.05,0.0);
        if (truck1.getPosition().x>window.getSize().x)
        {
            truck1.setPosition(sf::Vector2f(-120.0f,250.0f));
        }
        if (truck2.getPosition().x<-120)
        {
            truck2.setPosition(sf::Vector2f(450.0f,300.0f));
        }  
        if (truck3.getPosition().x>window.getSize().x)
        {
            truck3.setPosition(sf::Vector2f(-120.0f,350.0f));
        }             
        //update the game
        window.clear();
        window.draw(start_bar);
        window.draw(middle_bar);
        window.draw(finish_bar);
        window.draw(truck1);
        window.draw(truck2);
        window.draw(truck3);
        window.display();
    }

    return 0;
}

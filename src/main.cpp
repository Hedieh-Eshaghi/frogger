#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Manager
{
public:
    RectangleShape Shape;
    void CreatSprite(string const &FileName, float X, float Y);
};
void Manager::CreatSprite(string const &FileName, float X, float Y)
{
    static int count = 0;
    static Texture texture[11];
    texture[count].loadFromFile(FileName);
    Shape.setSize(Vector2f(X, Y));
    Shape.setTexture(&texture[count]);
    Sprite sprite;
    sprite.setTexture(texture[count]);
    count++;
}
int main()
{
    RenderWindow window(VideoMode(800, 450), "Frogger");
    RectangleShape start_bar;
    RectangleShape middle_bar;
    RectangleShape finish_bar;
    start_bar.setSize(Vector2f(800.0, 50.0));
    start_bar.setPosition(Vector2f(0.0f, 400.0f));
    middle_bar.setSize(Vector2f(800.0, 50.0));
    middle_bar.setPosition(Vector2f(0.0f, 200.0f));
    finish_bar.setSize(Vector2f(800.0, 50.0));
    finish_bar.setPosition(Vector2f(0.0f, 0.0f));
    Manager frog;
    frog.CreatSprite("Asset/Image/Frog.png", 25.0, 25.0);
    frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - frog.Shape.getSize().y));

    Manager car1, car2, car3, car4, truck;
    car1.CreatSprite("Asset/Image/Car1.png", 25.0, 25.0);
    car1.Shape.setPosition(Vector2f(800.0, 250.0));
    car2.CreatSprite("Asset/Image/Car2.png", 40.0, 25.0);
    car2.Shape.setPosition(Vector2f(0.0, 275.0));
    car3.CreatSprite("Asset/Image/Car3.png", 25.0, 25.0);
    car3.Shape.setPosition(Vector2f(800.0, 300.0));
    car4.CreatSprite("Asset/Image/Car4.png", 40.0, 25.0);
    car4.Shape.setPosition(Vector2f(0.0, 325.0));
    truck.CreatSprite("Asset/Image/Truck.png", 40.0, 25.0);
    truck.Shape.setPosition(Vector2f(800.0, 350.0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyReleased:
                if (Keyboard::Key::Left == event.key.code)
                {
                    frog.Shape.move(-20, 0);
                }
                if (Keyboard::Key::Right == event.key.code)
                {
                    frog.Shape.move(20, 0);
                }
                if (Keyboard::Key::Up == event.key.code)
                {
                    frog.Shape.move(0, -50);
                }
                if (Keyboard::Key::Down == event.key.code)
                {
                    frog.Shape.move(0, 50);
                }
            }
        }
        car1.Shape.move(-0.05, 0.0);
        car2.Shape.move(0.02, 0.0);
        car3.Shape.move(-0.05, 0.0);
        car4.Shape.move(0.02, 0.0);
        truck.Shape.move(-0.05, 0.0);
        if (car1.Shape.getPosition().x > window.getSize().x)
        {
            car1.Shape.setPosition(Vector2f(800.0f, 250.0f));
        }
        if (car2.Shape.getPosition().x < -200)
        {
            car2.Shape.setPosition(Vector2f(0.0f, 275.0f));
        }
        if (car3.Shape.getPosition().x > window.getSize().x)
        {
            car3.Shape.setPosition(Vector2f(800.0f, 300.0f));
        }
        if (car4.Shape.getPosition().x < -200)
        {
            car4.Shape.setPosition(Vector2f(0.0f, 325.0f));
        }
        if (truck.Shape.getPosition().x > window.getSize().x)
        {
            truck.Shape.setPosition(Vector2f(800.0f, 350.0f));
        }
        //accident
        if (frog.Shape.getGlobalBounds().intersects(car1.Shape.getGlobalBounds()))
        {
            window.close();
        }
        if (frog.Shape.getGlobalBounds().intersects(car2.Shape.getGlobalBounds()))
        {
            window.close();
        }
        if (frog.Shape.getGlobalBounds().intersects(car3.Shape.getGlobalBounds()))
        {
            window.close();
        }
        if (frog.Shape.getGlobalBounds().intersects(car4.Shape.getGlobalBounds()))
        {
            window.close();
        }
        if (frog.Shape.getGlobalBounds().intersects(truck.Shape.getGlobalBounds()))
        {
            window.close();
        }
        //update the game
        window.clear();
        window.draw(start_bar);
        window.draw(middle_bar);
        window.draw(finish_bar);
        window.draw(frog.Shape);
        window.draw(car1.Shape);
        window.draw(car2.Shape);
        window.draw(car3.Shape);
        window.draw(car4.Shape);
        window.draw(truck.Shape);
        window.display();
    }

    return 0;
}

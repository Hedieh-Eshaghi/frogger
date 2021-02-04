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
    static Texture texture[12];
    texture[count].loadFromFile(FileName);
    Shape.setSize(Vector2f(X, Y));
    Shape.setTexture(&texture[count]);
    Sprite sprite;
    sprite.setTexture(texture[count]);
    count++;
}
int main()
{
    RenderWindow window(VideoMode(700, 650), "Frogger");
    Manager background;
    background.CreatSprite("../Asset/Image/Background.png", 700.0, 650.0);

    Manager frog;
    frog.CreatSprite("../Asset/Image/FrogUp.png", 50.0, 50.0);
    frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - frog.Shape.getSize().y));

    Manager car1, car2, car3, car4, truck;
    car1.CreatSprite("../Asset/Image/Car1.png", 70.0, 50.0);
    car1.Shape.setPosition(Vector2f(700.0, 350.0));
    car2.CreatSprite("../Asset/Image/Car2.png", 80.0, 50.0);
    car2.Shape.setPosition(Vector2f(700.0, 400.0));
    car3.CreatSprite("../Asset/Image/Car3.png", 80.0, 50.0);
    car3.Shape.setPosition(Vector2f(0.0, 450.0));
    car4.CreatSprite("../Asset/Image/Car4.png", 70.0, 50.0);
    car4.Shape.setPosition(Vector2f(0.0, 500.0));
    truck.CreatSprite("../Asset/Image/Truck.png", 130.0, 50.0);
    truck.Shape.setPosition(Vector2f(700.0, 550.0));

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
                if (Keyboard::Key::Left == event.key.code && frog.Shape.getPosition().x > 0)
                {
                    frog.Shape.move(-25, 0);
                    frog.CreatSprite("../Asset/Image/FrogLeft.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Right == event.key.code && frog.Shape.getPosition().x+frog.Shape.getSize().x < window.getSize().x)
                {
                    frog.Shape.move(25, 0);
                    frog.CreatSprite("../Asset/Image/FrogRight.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Up == event.key.code && frog.Shape.getPosition().y > 0)
                {
                    frog.Shape.move(0, -50);
                    frog.CreatSprite("../Asset/Image/FrogUp.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Down == event.key.code && frog.Shape.getPosition().y+frog.Shape.getSize().y < window.getSize().y)
                {
                    frog.Shape.move(0, 50);
                    frog.CreatSprite("../Asset/Image/FrogDown.png", 50.0, 50.0);
                }
            }
        }
        car1.Shape.move(-0.05, 0.0);
        car2.Shape.move(-0.02, 0.0);
        car3.Shape.move(0.05, 0.0);
        car4.Shape.move(0.02, 0.0);
        truck.Shape.move(-0.05, 0.0);
        if (car1.Shape.getPosition().x < -70)
        {
            car1.Shape.setPosition(Vector2f(770.0f, 350.0f));
        }
        if (car2.Shape.getPosition().x < -80)
        {
            car2.Shape.setPosition(Vector2f(780.0f, 400.0f));
        }
        if (car3.Shape.getPosition().x > 700)
        {
            car3.Shape.setPosition(Vector2f(-80.0f, 450.0f));
        }
        if (car4.Shape.getPosition().x > 700)
        {
            car4.Shape.setPosition(Vector2f(-70.0f, 500.0f));
        }
        if (truck.Shape.getPosition().x < -130)
        {
            truck.Shape.setPosition(Vector2f(730.0f, 550.0f));
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
        window.draw(background.Shape);
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

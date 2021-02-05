#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Manager
{
public:
    RectangleShape Shape;
    void CreatSprite(string const &FileName, float X, float Y);
    void Loop(Manager *manager, float X, float Y);
    void Accident(RenderWindow &window, Manager frog, Manager manager);
};
void Manager::CreatSprite(string const &FileName, float X, float Y)
{
    static int count = 0;
    static Texture texture[40];
    texture[count].loadFromFile(FileName);
    Shape.setSize(Vector2f(X, Y));
    Shape.setTexture(&texture[count]);
    Sprite sprite;
    sprite.setTexture(texture[count]);
    count++;
}
void Manager::Loop(Manager *manager, float X, float Y)
{
    if (manager->Shape.getPosition().x > 700 || manager->Shape.getPosition().x < 0)
    {
        manager->Shape.setPosition(Vector2f(X, Y));
    }
}
void Manager::Accident(RenderWindow &window, Manager frog, Manager manager)
{
    if (frog.Shape.getGlobalBounds().intersects(manager.Shape.getGlobalBounds()))
    {
        window.close();
    }
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
    car1.Shape.setPosition(Vector2f(700.0, 550.0));
    car2.CreatSprite("../Asset/Image/Car2.png", 70.0, 50.0);
    car2.Shape.setPosition(Vector2f(0.0, 500.0));
    car3.CreatSprite("../Asset/Image/Car3.png", 80.0, 50.0);
    car3.Shape.setPosition(Vector2f(700.0, 450.0));
    car4.CreatSprite("../Asset/Image/Car4.png", 80.0, 50.0);
    car4.Shape.setPosition(Vector2f(0.0, 400.0));
    truck.CreatSprite("../Asset/Image/Truck.png", 130.0, 50.0);
    truck.Shape.setPosition(Vector2f(700.0, 350.0));

    Manager wood1, wood2, wood3, wood4, wood5;
    wood1.CreatSprite("../Asset/Image/Wood.png", 70.0, 50.0);
    wood1.Shape.setPosition(Vector2f(700.0, 250.0));
    wood2.CreatSprite("../Asset/Image/Wood.png", 60.0, 50.0);
    wood2.Shape.setPosition(Vector2f(0.0, 200.0));
    wood3.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood3.Shape.setPosition(Vector2f(00.0, 150.0));
    wood4.CreatSprite("../Asset/Image/Wood.png", 60.0, 50.0);
    wood4.Shape.setPosition(Vector2f(700.0, 100.0));
    wood5.CreatSprite("../Asset/Image/Wood.png", 70.0, 50.0);
    wood5.Shape.setPosition(Vector2f(0.0, 50.0));

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
        car1.Shape.move(-5.0, 0.0);
        car2.Shape.move(2.0, 0.0);
        car3.Shape.move(-5.0, 0.0);
        car4.Shape.move(2.0, 0.0);
        truck.Shape.move(-5.0, 0.0);
        wood1.Shape.move(-5.0, 0.0);
        wood2.Shape.move(2.0, 0.0);
        wood3.Shape.move(5.0, 0.0);
        wood4.Shape.move(-2.0, 0.0);
        wood5.Shape.move(5.0, 0.0);
        Manager *ptr[10];
        ptr[0] = &car1;
        car1.Loop(ptr[0], 700, 550);
        ptr[1] = &car2;
        car2.Loop(ptr[1], 0, 500);
        ptr[2] = &car3;
        car3.Loop(ptr[2], 700, 450);
        ptr[3] = &car4;
        car4.Loop(ptr[3], 0, 400);
        ptr[4] = &truck;
        truck.Loop(ptr[4], 700, 350);
        ptr[5] = &wood1;
        wood1.Loop(ptr[5], 700, 250);
        ptr[6] = &wood2;
        wood2.Loop(ptr[6], 0, 200);
        ptr[7] = &wood3;
        wood3.Loop(ptr[7], 0, 150);
        ptr[8] = &wood4;
        wood4.Loop(ptr[8], 700, 100);
        ptr[9] = &wood5;
        wood5.Loop(ptr[9], 0, 50);

        //accident
        car1.Accident(window, frog, car1);
        car2.Accident(window, frog, car2);
        car3.Accident(window, frog, car3);
        car4.Accident(window, frog, car4);
        truck.Accident(window, frog, truck);
        wood1.Accident(window, frog, wood1);
        wood2.Accident(window, frog, wood2);
        wood3.Accident(window, frog, wood3);
        wood4.Accident(window, frog, wood4);
        wood5.Accident(window, frog, wood5);

        //update the game
        window.clear();
        window.draw(background.Shape);
        window.draw(frog.Shape);
        window.draw(car1.Shape);
        window.draw(car2.Shape);
        window.draw(car3.Shape);
        window.draw(car4.Shape);
        window.draw(truck.Shape);
        window.draw(wood1.Shape);
        window.draw(wood2.Shape);
        window.draw(wood3.Shape);
        window.draw(wood4.Shape);
        window.draw(wood5.Shape);
        window.display();
    }

    return 0;
}
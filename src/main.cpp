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
    void Accident(RenderWindow &window, Manager frog, Manager cars[], int n_cars);
    int Drown(RenderWindow &window, Manager frog, Manager woods[], int n_woods);
    void Move(float v_x, float v_y);
};
void Manager::Move(float v_x, float v_y)
{
    Shape.move(v_x, v_y);
}
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
void Manager::Accident(RenderWindow &window, Manager frog, Manager cars[], int n_cars)
{
    for (int i = 0; i < n_cars; i++)
    {
        if (frog.Shape.getGlobalBounds().intersects(cars[i].Shape.getGlobalBounds()))
        {
            window.close();
        }
    }
}
int Manager::Drown(RenderWindow &window, Manager frog, Manager woods[], int n_woods)
{
    int s=0;
    for (int i = 0; i < n_woods; i++)
    {  
        if (woods[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x+1, frog.Shape.getPosition().y+1))
        {
            if (woods[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x+49, frog.Shape.getPosition().y+49))
            {
                return i;
                s++;
            }
        }
    }
    if (s==0 && frog.Shape.getPosition().y<300 && frog.Shape.getPosition().y>=50) 
    {
        window.close();
    }  
    return -1;
}

int main()
{
    RenderWindow window(VideoMode(700, 700), "Frogger");
    Manager background;
    background.CreatSprite("../Asset/Image/Background.png", 700.0, 650.0);

    Manager frog;
    frog.CreatSprite("../Asset/Image/FrogUp.png", 50.0, 50.0);
    frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y-50 - frog.Shape.getSize().y));

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
    wood1.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood1.Shape.setPosition(Vector2f(700.0, 250.0));
    wood2.CreatSprite("../Asset/Image/Wood.png", 120.0, 50.0);
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
        float velocity_cars[] = {-0.5,0.2,-0.5,0.2,-0.5};
        float velocity_woods[] = {-0.1,0.1,0.5,-0.2,0.5};
        car1.Move(velocity_cars[0], 0.0);
        car2.Move(velocity_cars[1], 0.0);
        car3.Move(velocity_cars[2], 0.0);
        car4.Move(velocity_cars[3], 0.0);
        truck.Move(velocity_cars[4], 0.0);
        wood1.Move(velocity_woods[0], 0.0);
        wood2.Move(velocity_woods[1], 0.0);
        wood3.Move(velocity_woods[2], 0.0);
        wood4.Move(velocity_woods[3], 0.0);
        wood5.Move(velocity_woods[4], 0.0);
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

        //accident and drown
        int n_cars = 5;
        Manager cars[]={car1,car2,car3,car4,truck};
        frog.Accident(window,frog,cars,n_cars);
        int n_woods = 5;
        Manager woods[]={wood1,wood2,wood3,wood4,wood5};
        int wood_number = -1;
        wood_number = frog.Drown(window,frog,woods,n_woods);
        if (wood_number>-1) frog.Shape.move(velocity_woods[wood_number],0.0);
        

        //update the game
        window.clear();
        window.draw(background.Shape);
        for (int i = 0; i < n_cars; i++) window.draw(cars[i].Shape);
        for (int i = 0; i < n_woods; i++) window.draw(woods[i].Shape);
        window.draw(frog.Shape);
        window.display();
    }

    return 0;
}
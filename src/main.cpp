#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int heart = 3;
class Manager
{
public:
    RectangleShape Shape;
    void CreatSprite(string const &FileName, float X, float Y);
    int Accident(RenderWindow &window, Manager frog, Manager cars[], int n_cars);
    int Drown(RenderWindow &window, Manager frog, Manager woods[], int n_woods);
    void Move(float v_x, float v_y);
    int CheckHome(RenderWindow &window, Manager frog, Manager homes[], int n_homes);
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
int Manager::Accident(RenderWindow &window, Manager frog, Manager cars[], int n_cars)
{
    for (int i = 0; i < n_cars; i++)
    {
        if (frog.Shape.getGlobalBounds().intersects(cars[i].Shape.getGlobalBounds()))
        {
            heart--;
            return -2;
        }
    }
    return -1;
}
int Manager::Drown(RenderWindow &window, Manager frog, Manager woods[], int n_woods)
{
    for (int i = 0; i < n_woods; i++)
    {
        if (woods[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x + 1, frog.Shape.getPosition().y + 1))
        {
            if (woods[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x + 49, frog.Shape.getPosition().y + 49))
            {
                return i;
            }
        }
    }
    if (frog.Shape.getPosition().y < 300 && frog.Shape.getPosition().y >= 50)
    {
        heart--;
        return -2;
    }
    return -1;
}
void Manager::Move(float v_x, float v_y)
{
    Shape.move(v_x, v_y);
    if (v_x > 0 && Shape.getPosition().x > 700)
    {
        Shape.setPosition(Vector2f(-Shape.getSize().x, Shape.getPosition().y));
    }
    else if (v_x < 0 && Shape.getPosition().x < -Shape.getSize().x)
    {
        Shape.setPosition(Vector2f(700 + Shape.getSize().x, Shape.getPosition().y));
    }
}
int Manager::CheckHome(RenderWindow &window, Manager frog, Manager homes[], int n_homes)
{
    for (int i = 0; i < n_homes; i++)
    {
        if (homes[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x + 1, frog.Shape.getPosition().y + 1))
        {
            if (homes[i].Shape.getGlobalBounds().contains(frog.Shape.getPosition().x + 49, frog.Shape.getPosition().y + 49))
            {
                return i;
            }
        }
    }
    if (frog.Shape.getPosition().y < 50 && frog.Shape.getPosition().y >= 0)
    {
        heart--;
        return -2;
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
    frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
    Listener::setGlobalVolume(100.f);
    Sound sound;
    SoundBuffer soundbuffer;
    soundbuffer.loadFromFile("../Asset/Sound/sound-frogger-plunk.wav");
    sound.setBuffer(soundbuffer);

    Manager car1, car2, car3, car4, truck, car5, car6, car7, car8, car9, truck1;
    car1.CreatSprite("../Asset/Image/Car1.png", 70.0, 50.0);
    car1.Shape.setPosition(Vector2f(300.0, 550.0));
    car2.CreatSprite("../Asset/Image/Car2.png", 70.0, 50.0);
    car2.Shape.setPosition(Vector2f(200.0, 500.0));
    car3.CreatSprite("../Asset/Image/Car3.png", 80.0, 50.0);
    car3.Shape.setPosition(Vector2f(400.0, 450.0));
    car4.CreatSprite("../Asset/Image/Car4.png", 80.0, 50.0);
    car4.Shape.setPosition(Vector2f(0.0, 400.0));
    truck.CreatSprite("../Asset/Image/Truck.png", 130.0, 50.0);
    truck.Shape.setPosition(Vector2f(500.0, 350.0));
    car5.CreatSprite("../Asset/Image/Car1.png", 70.0, 50.0);
    car5.Shape.setPosition(Vector2f(0.0, 550.0));
    car6.CreatSprite("../Asset/Image/Car2.png", 70.0, 50.0);
    car6.Shape.setPosition(Vector2f(500.0, 500.0));
    car7.CreatSprite("../Asset/Image/Car3.png", 80.0, 50.0);
    car7.Shape.setPosition(Vector2f(100.0, 450.0));
    car8.CreatSprite("../Asset/Image/Car4.png", 80.0, 50.0);
    car8.Shape.setPosition(Vector2f(300.0, 400.0));
    truck1.CreatSprite("../Asset/Image/Truck.png", 130.0, 50.0);
    truck1.Shape.setPosition(Vector2f(200.0, 350.0));

    Manager wood1, wood2, wood3, wood4, wood5, wood6, wood7, wood8, wood9, wood10;
    wood1.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood1.Shape.setPosition(Vector2f(300.0, 250.0));
    wood2.CreatSprite("../Asset/Image/Wood.png", 120.0, 50.0);
    wood2.Shape.setPosition(Vector2f(200.0, 200.0));
    wood3.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood3.Shape.setPosition(Vector2f(400.0, 150.0));
    wood4.CreatSprite("../Asset/Image/Wood.png", 130.0, 50.0);
    wood4.Shape.setPosition(Vector2f(0.0, 100.0));
    wood5.CreatSprite("../Asset/Image/Wood.png", 140.0, 50.0);
    wood5.Shape.setPosition(Vector2f(500.0, 50.0));
    wood6.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood6.Shape.setPosition(Vector2f(0.0, 250.0));
    wood7.CreatSprite("../Asset/Image/Wood.png", 120.0, 50.0);
    wood7.Shape.setPosition(Vector2f(500.0, 200.0));
    wood8.CreatSprite("../Asset/Image/Wood.png", 150.0, 50.0);
    wood8.Shape.setPosition(Vector2f(100.0, 150.0));
    wood9.CreatSprite("../Asset/Image/Wood.png", 130.0, 50.0);
    wood9.Shape.setPosition(Vector2f(300.0, 100.0));
    wood10.CreatSprite("../Asset/Image/Wood.png", 140.0, 50.0);
    wood10.Shape.setPosition(Vector2f(200.0, 50.0));

    Manager Home1, Home2, Home3, Home4, Home5;
    Home1.CreatSprite("../Asset/Image/Home.png", 70.0, 50.0);
    Home1.Shape.setPosition(Vector2f(15.0, 0.0));
    Home2.CreatSprite("../Asset/Image/Home.png", 70.0, 50.0);
    Home2.Shape.setPosition(Vector2f(165.0, 0.0));
    Home3.CreatSprite("../Asset/Image/Home.png", 70.0, 50.0);
    Home3.Shape.setPosition(Vector2f(315.0, 0.0));
    Home4.CreatSprite("../Asset/Image/Home.png", 70.0, 50.0);
    Home4.Shape.setPosition(Vector2f(465.0, 0.0));
    Home5.CreatSprite("../Asset/Image/Home.png", 70.0, 50.0);
    Home5.Shape.setPosition(Vector2f(615.0, 0.0));

    Manager Heart;
    Heart.CreatSprite("../Asset/Image/Heart3.png", 50.0, 50.0);
    Heart.Shape.setPosition(Vector2f(window.getSize().x - Heart.Shape.getSize().x, window.getSize().y - Heart.Shape.getSize().y));

    RectangleShape TimeBar;
    TimeBar.setSize(Vector2f(200.0f, 15.0f));
    TimeBar.setPosition(Vector2f(60.0f, 670.0f));
    TimeBar.setFillColor(Color::White);

    Font font;
    font.loadFromFile("../Asset/Font/COOPBL.TTF");
    Text time("TIME", font);
    time.setFillColor(Color::Red);
    time.setPosition(Vector2f(0.0f, 665.0f));
    time.setCharacterSize(20);
    RectangleShape BlackBar;
    BlackBar.setSize(Vector2f(200.0f, 15.0f));
    BlackBar.setPosition(Vector2f(260.0f, 670.0f));
    BlackBar.setFillColor(Color::Black);
    Time elapsedTime, deltaTime;
    Clock clock;
    while (window.isOpen())
    {
        Event event;
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
                    sound.play();
                    frog.Shape.move(-25, 0);
                    frog.CreatSprite("../Asset/Image/FrogLeft.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Right == event.key.code && frog.Shape.getPosition().x+frog.Shape.getSize().x < window.getSize().x)
                {
                    sound.play();
                    frog.Shape.move(25, 0);
                    frog.CreatSprite("../Asset/Image/FrogRight.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Up == event.key.code && frog.Shape.getPosition().y > 0)
                {
                    sound.play();
                    frog.Shape.move(0, -50);
                    frog.CreatSprite("../Asset/Image/FrogUp.png", 50.0, 50.0);
                }
                if (Keyboard::Key::Down == event.key.code && frog.Shape.getPosition().y+frog.Shape.getSize().y < window.getSize().y)
                {
                    sound.play();
                    frog.Shape.move(0, 50);
                    frog.CreatSprite("../Asset/Image/FrogDown.png", 50.0, 50.0);
                }
            }
        }
        float velocity_cars[] = {-0.1, 0.1, -0.2, 0.2, -0.1};
        float velocity_woods[] = {0.1, -0.1, 0.2, -0.2, 0.1, 0.1, -0.1, 0.2, -0.2, 0.1};
        car1.Move(velocity_cars[0], 0.0);
        car2.Move(velocity_cars[1], 0.0);
        car3.Move(velocity_cars[2], 0.0);
        car4.Move(velocity_cars[3], 0.0);
        truck.Move(velocity_cars[4], 0.0);
        car5.Move(velocity_cars[0], 0.0);
        car6.Move(velocity_cars[1], 0.0);
        car7.Move(velocity_cars[2], 0.0);
        car8.Move(velocity_cars[3], 0.0);
        truck1.Move(velocity_cars[4], 0.0);
        wood1.Move(velocity_woods[0], 0.0);
        wood2.Move(velocity_woods[1], 0.0);
        wood3.Move(velocity_woods[2], 0.0);
        wood4.Move(velocity_woods[3], 0.0);
        wood5.Move(velocity_woods[4], 0.0);
        wood6.Move(velocity_woods[0], 0.0);
        wood7.Move(velocity_woods[1], 0.0);
        wood8.Move(velocity_woods[2], 0.0);
        wood9.Move(velocity_woods[3], 0.0);
        wood10.Move(velocity_woods[4], 0.0);
        //Time
        int change_heart = 0;
        deltaTime = clock.restart();
        elapsedTime += deltaTime;
        float AsSeconds = elapsedTime.asSeconds();
        BlackBar.setPosition(Vector2f(260.0f - 5 * AsSeconds, 670.0f));
        if (elapsedTime > seconds(40))
        {
            frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
            elapsedTime = seconds(0);
            change_heart++;
            heart--;
        }
        //accident, drown and home
        int n_cars = 10;
        Manager cars[] = {car1, car2, car3, car4, truck, car5, car6, car7, car8, car9, truck1};
        int f_a = frog.Accident(window, frog, cars, n_cars);
        if (f_a == -2)
        {
            frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
            elapsedTime = seconds(0);
            change_heart++;
        }
        int n_woods = 10;
        Manager woods[] = {wood1, wood2, wood3, wood4, wood5, wood6, wood7, wood8, wood9, wood10};
        int wood_number = -1;
        wood_number = frog.Drown(window, frog, woods, n_woods);
        if (wood_number == -2)
        {
            frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
            elapsedTime = seconds(0);
            clock.restart();
            change_heart++;
        }
        if (wood_number > -1)
            frog.Shape.move(velocity_woods[wood_number], 0.0);
        int n_homes = 5;
        Manager homes[] = {Home1, Home2, Home3, Home4, Home5};
        int home_number = -1;
        home_number = frog.CheckHome(window, frog, homes, n_homes);
        if (home_number == -2)
        {
            frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
            elapsedTime = seconds(0);
            change_heart++;
        }
        int count[5] = {0};
        if (home_number > -1)
        {
            frog.Shape.setPosition(Vector2f(frog.Shape.getPosition().x, window.getSize().y - 50 - frog.Shape.getSize().y));
            elapsedTime = seconds(0);
            if (home_number == 0)
            {
                Home1.CreatSprite("../Asset/Image/FrogWin.png", 70.0, 50.0);
                count[0]++;
            }
            else if (home_number == 1)
            {
                Home2.CreatSprite("../Asset/Image/FrogWin.png", 70.0, 50.0);
                count[1]++;
            }
            else if (home_number == 2)
            {
                Home3.CreatSprite("../Asset/Image/FrogWin.png", 70.0, 50.0);
                count[2]++;
            }
            else if (home_number == 3)
            {
                Home4.CreatSprite("../Asset/Image/FrogWin.png", 70.0, 50.0);
                count[3]++;
            }
            else if (home_number == 4)
            {
                Home5.CreatSprite("../Asset/Image/FrogWin.png", 70.0, 50.0);
                count[4]++;
            }
        }
        if (count[0] != 0 && count[1] != 0 && count[2] != 0 && count[3] != 0 && count[4] != 0)
        {
            Text Win("Win", font);
            Win.setFillColor(Color::Green);
            Win.setPosition(Vector2f((window.getPosition().x) / 2, (window.getSize().y) / 2));
            Win.setCharacterSize(100);
            window.clear();
            window.draw(Win);
            window.display();
            sleep(seconds(6));
            window.close();
        }
        if (heart < 1)
        {
            Text GameOver("GameOver!", font);
            GameOver.setFillColor(Color::Red);
            GameOver.setPosition(Vector2f((window.getPosition().x) / 2, (window.getSize().y) / 2));
            GameOver.setCharacterSize(100);
            window.clear();
            window.draw(GameOver);
            window.display();
            sleep(seconds(6));
            window.close();
        }
        if (change_heart > 0)
        {
            if (heart == 3)
                Heart.CreatSprite("../Asset/Image/Heart3.png", 50.0, 50.0);
            else if (heart == 2)
                Heart.CreatSprite("../Asset/Image/Heart2.png", 50.0, 50.0);
            else if (heart == 1)
                Heart.CreatSprite("../Asset/Image/Heart1.png", 50.0, 50.0);
        }

        
        
        //update the game
        window.clear();
        window.draw(background.Shape);
        for (int i = 0; i < n_cars; i++)
            window.draw(cars[i].Shape);
        for (int i = 0; i < n_woods; i++)
            window.draw(woods[i].Shape);
        window.draw(frog.Shape);
        for (int i = 0; i < n_homes; i++)
            window.draw(homes[i].Shape);
        window.draw(Heart.Shape);
        window.draw(TimeBar);
        window.draw(BlackBar);
        window.draw(time);
        window.display();
    }
    return 0;
}
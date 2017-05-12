#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Fighters!",sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Event event;
    sf::Music music;
    if(!music.openFromFile("Saints Row The Third.wav"))
    {
        return -1;
    }
    music.play();
    music.setVolume(40);
    music.setLoop(true);
    if(!texture.loadFromFile("plane.png"))
    {
        std::cout<<"error!";
        return 0;
    }
    sprite.setTexture(texture);
    sprite.setPosition(650,600);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                 window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}


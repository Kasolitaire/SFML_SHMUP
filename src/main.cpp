#include <SFML/Graphics.hpp>
#include <iostream>;
#include "AssetManager.h";
#include "Game.h";

using namespace sf;
int main()
{
    
    Game game;
    
   /* sf::RenderWindow window(sf::VideoMode(320, 240), "SFML works!");
    
    Texture& texture = AssetManager::GetTexture("assets\\far-mountains.png");
    texture.setRepeated(true);
    
    Sprite sprite(texture);
    sprite.setPosition(0, 0);
    sprite.setTextureRect(IntRect(0, 0, 640, 240));
    
    Texture& texture2 = AssetManager::GetTexture("assets\\trees.png");
    texture2.setRepeated(true);

    Sprite sprite2(texture2);
    sprite2.setPosition(0, 0);
    sprite2.setTextureRect(IntRect(0, 0, 640, 240));

    
   
    Clock clock;
    Time timeElapsed;
    Time deltaTime;


    while (window.isOpen())
    {
        timeElapsed += clock.getElapsedTime();
        deltaTime = clock.getElapsedTime();
        clock.restart();
        sprite.move(Vector2f(-100 * deltaTime.asSeconds(), 0));
        sprite2.move(Vector2f(-150 * deltaTime.asSeconds(), 0));
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << sprite.getGlobalBounds().left << std::endl;
        if (sprite.getGlobalBounds().left <= -320)
            sprite.setPosition(0, 0);
        if (sprite2.getGlobalBounds().left <= -240)
            sprite2.setPosition(0, 0);

        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
      
        window.display();
    }

    return 0;*/
}
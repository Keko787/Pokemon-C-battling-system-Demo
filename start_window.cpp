//
// Created by Paulo Drefahl on 11/27/2022.
//

// Demonstrate sprite drawing in SFML

#include "pokemonConfig.h"

int main() {
    stageStart(); // only need to use the function because the rest of the function calls are inside
}

void stageStart ()
{
    /// initialization and assigning, starting sfml window

    // mouse coords and checkpoints
    Mouse mouse{};
    // initialization and assigning, starting sfml window

    //Window config
    sf::RenderWindow renderStart(sf::VideoMode(1200, 800),
                                 "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");

    //Event Variables
    sf::Event event{};

    //Text Config
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/PKMNRBYGSC.ttf"))
    {
        std::cout << "font error";
    }
    text.setFont(font);  //font
    text.setString("Select  Pokemon...");
    text.setCharacterSize(29); // in pixels, not points!
    text.setPosition(402, 645);  //pos
    text.setFillColor(sf::Color::Black);  // color

    // Images, Sprites
    sf::Texture mainMenuImg;
    mainMenuImg.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/Poke_Menu_WIP.png");
    sf::Sprite sprite(mainMenuImg);

    ///process
    while (renderStart.isOpen())
    {
        while (renderStart.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                if (event.type == sf::Event::MouseButtonPressed)
                    renderStart.close();
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mouse.pos1X = event.mouseButton.x; // set up mouse x coord
                    mouse.pos1Y = event.mouseButton.y; // set up mouse y coord

                    // start button
                    if (mouse.selectStart()) // mouse clicks on selectStart
                    {
                        std::cout << "Start game" << std::endl;
                        renderStart.close(); //closes window

                        stageSelect(); // goes to the next window and stage
                    }

                    // exit button
                    if (mouse.selectExit()) // mouse click on selectExit
                    {
                        std::cout << "Exit game" << std::endl;
                        renderStart.close(); //closes window and ends the prgm
                    }
                }
            }
            renderStart.clear();
            renderStart.draw(sprite);
            renderStart.display();
        }
    }
}
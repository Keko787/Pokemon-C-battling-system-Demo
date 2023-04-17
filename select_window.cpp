//
// Created by kskos on 3/29/2023.
//

#include "pokemonConfig.h"

void stageSelect(){
    /// initialization and assigning, starting sfml window

    // mouse coords and checkpoints
    Mouse mouse{};

    // pokemon index
    int pokemon = 0;

    //Event Variable
    sf::Event event1{};

    //Text Config
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/PKMNRBYGSC.ttf"))
    {
        std::cout << "font error";
    }
    text.setFont(font);  // font
    text.setString("Select  Pokemon...");  // str
    text.setCharacterSize(29); // in pixels, not points!
    text.setPosition(402, 645);  // pos
    text.setFillColor(sf::Color::Black);  // color

    // Images, Sprites
    sf::Texture pokemonSelectionImg;
    pokemonSelectionImg.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/Poke_Select_3.png");
    sf::Sprite sprite2(pokemonSelectionImg);

    //Window config
    sf::RenderWindow renderSelection(sf::VideoMode(1200, 800),
                                     "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");

    ///process
    while (renderSelection.isOpen())
    {
        while (renderSelection.pollEvent(event1))
        {
            if (event1.type == sf::Event::EventType::Closed)
            {
                renderSelection.close();
            }
            if (event1.type == sf::Event::MouseButtonPressed)
            {
                if (event1.mouseButton.button == sf::Mouse::Left)
                {
                    mouse.pos2X = event1.mouseButton.x;  // mouse coord x for clicking
                    mouse.pos2Y = event1.mouseButton.y;  // mouse coord y for clicking

                    ///selection checkpoints
                    // charmander button
                    if (mouse.selectCharm())
                    {
                        pokemon = 0; // this value will also decide on the pokemon being set to initialize in battle window
                        text.setString("Charmander Selected.");
                    }

                    // bulbasuar button
                    if (mouse.selectBulb())
                    {
                        pokemon = 1;
                        text.setString("Bulbasaur Selected.");
                    }

                    // squirtle button
                    if (mouse.selectSquir())
                    {
                        pokemon = 2;
                        text.setString("Squirtle Selected.");
                    }

                    // start battle button
                    if (mouse.selectGoBattle())
                    {
                        std::cout << "Battle Started" << std::endl;
                        renderSelection.close();  //closes the window
                        stageBattle(pokemon);  // opens next window, next stage, and brings the choice of the player's pkmn
                        // to the next stage to bring out the right pokemon
                    }
                }
            }

            renderSelection.clear();
            renderSelection.draw(sprite2);
            renderSelection.draw(text);
            renderSelection.display();
        }
    }
}
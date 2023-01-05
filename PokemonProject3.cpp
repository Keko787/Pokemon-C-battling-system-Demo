//
// Created by Paulo Drefahl on 11/27/2022.
//

// Demonstrate sprite drawing in SFML

#include "pokemonConfig.h"


void renderBattle(int pokemon);
void UpdateHP(int Attack, int &pikachu_hp);

int main() {
    // mouse coords and checkpoints
    Mouse mouse;
// initialization and assigning, starting sfml window
    int pokemon;


    //Window config
    sf::RenderWindow renderWindow(sf::VideoMode(1200, 800),
                                  "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");

    //Event Variables
    sf::Event event;
    sf::Event event1;

    //Text Config
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/PKMNRBYGSC.ttf")) {
        std::cout << "font error";
    }
    text.setFont(font);
    text.setString("Select  Pokemon...");
    text.setCharacterSize(29); // in pixels, not points!
    text.setPosition(402, 645);
    text.setFillColor(sf::Color::Black);

// Images, Sprites
    sf::Texture mainMenuImg;
    sf::Texture pokemonSelectionImg;
    pokemonSelectionImg.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/Poke_Select_3.png");
    mainMenuImg.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/Poke_Menu_WIP.png");
    sf::Sprite sprite(mainMenuImg);
    sf::Sprite sprite2(pokemonSelectionImg);


    while (renderWindow.isOpen())
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mouse.pos1X = event.mouseButton.x;
                    mouse.pos1Y = event.mouseButton.y;

                    //start button
                    if (mouse.start())
                    {
                        std::cout << "Start game" << std::endl;
                        renderWindow.close();

                        sf::RenderWindow renderSelection(sf::VideoMode(1200, 800),
                                                         "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");
                        while (renderSelection.isOpen())
                        {
                            while (renderSelection.pollEvent(event1))
                            {
                                if (event1.type == sf::Event::EventType::Closed)
                                    renderSelection.close();

                                if (event1.type == sf::Event::MouseButtonPressed)
                                {
                                    if (event1.mouseButton.button == sf::Mouse::Left)
                                    {
                                        mouse.pos2X = event1.mouseButton.x;
                                        mouse.pos2Y = event1.mouseButton.y;

                                        //selection checkpoints
                                        if (mouse.select1())
                                        {
                                            pokemon = 0; // this value will also decide on the pokemon being set to initialize
                                            text.setString("Charmander  Selected.");
                                        }

                                        if (mouse.select2())
                                        {
                                            pokemon = 1;
                                            text.setString("Bulbasaur  Selected.");
                                        }

                                        if (mouse.select3())
                                        {
                                            pokemon = 2;
                                            text.setString("Squirtle  Selected.");
                                        }
                                        if (mouse.goBattle())
                                        {
                                            std::cout << "Battle Started" << std::endl;
                                            renderSelection.close();
                                            renderBattle(pokemon);
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

                    if (mouse.exit())
                    {
                        std::cout << "Exit game" << std::endl;
                        renderWindow.close();
                    }

                }
            }
            renderWindow.clear();
            renderWindow.draw(sprite);
            renderWindow.display();
        }
    }
}

void renderBattle(int pokemon)
{
    // initialization and assigning, starting sfml window

    Mouse mouse;
    Pokemon charmander("Charmander", Fire, 50, 6, 3,3);
    Pokemon squirtle("squirtle", Water, 50, 6, 5,3);
    Pokemon bulbasuar("bulbasuar", Grass, 50, 5, 3,3);
    Pokemon pikachu("pikachu", Electric, 50, 5, 3,5);
    Pokemon *party1;

    if(pokemon == 0)
    {
        party1 = &charmander;
    }
    else if(pokemon == 1)
    {
        party1 = &bulbasuar;
    }
    else if(pokemon ==2)
    {
        party1 = &squirtle;
    }


    Pokemon &opp = pikachu;

    Moves command;
    Moves * moveSetE;
    Moves moveSet2;
    bool oppSelected;
    bool isDone;
    int random;


    //
    bool Poke1IsAlive = true;
    bool PokeCPUIsAlive = true;
    int pokemon_hp = 50, player_hp = 50;
    int Tackle = 1, ElemAttack = 3;
    int sum;



    sf::RenderWindow renderBattleScreen(sf::VideoMode(1200, 800),
                                        "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");
    sf::Font font;
    if (!font.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/PKMNRBYGSC.ttf"))
    {
        std::cout << "font error";
    }
    sf::Event eventBattle;

    sf::Texture BattleBackground;

    // select box
    sf::Text text2;
    text2.setFont(font);
    text2.setString("Select  Attack...");
    text2.setCharacterSize(24); // in pixels, not points!
    text2.setPosition(120, 630);
    text2.setFillColor(sf::Color::Black);

    // opponent box
    sf::Text hp_pokemon;
    hp_pokemon.setFont(font);
    hp_pokemon.setString(std::to_string(opp.hpNow));
    hp_pokemon.setCharacterSize(20); // in pixels, not points!
    hp_pokemon.setPosition(325, 140);
    hp_pokemon.setFillColor(sf::Color::Black);

    sf::Text hp_pokemon_const;
    hp_pokemon_const.setFont(font);
    hp_pokemon_const.setString("50");
    hp_pokemon_const.setCharacterSize(20); // in pixels, not points!
    hp_pokemon_const.setPosition(420, 140);
    hp_pokemon_const.setFillColor(sf::Color::Black);

    // player box
    sf::Text hp_player;
    hp_player.setFont(font);
    hp_player.setString(std::to_string(party1->hpNow));
    hp_player.setCharacterSize(20); // in pixels, not points!
    hp_player.setPosition(900, 475);
    hp_player.setFillColor(sf::Color::Black);

    sf::Text hp_player_const;
    hp_player_const.setFont(font);
    hp_player_const.setString("50");
    hp_player_const.setCharacterSize(20); // in pixels, not points!
    hp_player_const.setPosition(980, 475);
    hp_player_const.setFillColor(sf::Color::Black);

    switch (pokemon)
    {
        case 0:
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/char_battle_1frame.png");
            break;
        case 1:
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/bulba_battle_1frame.png");
            break;
        case 2:
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/squir_battle_1frame.png");
            break;
    }

    sf::Sprite sprite3(BattleBackground);


    while (renderBattleScreen.isOpen())
    {

        while (renderBattleScreen.pollEvent(eventBattle))
        {
            if (eventBattle.type == sf::Event::EventType::Closed)
                renderBattleScreen.close();
        }
        if (eventBattle.type == sf::Event::EventType::Closed)
        {
            renderBattleScreen.close();
        }
        if (eventBattle.type == sf::Event::MouseButtonPressed)
        {
            if (eventBattle.mouseButton.button == sf::Mouse::Left)
            {
                mouse.pos3X = eventBattle.mouseButton.x;
                mouse.pos3Y = eventBattle.mouseButton.y;

                //battle loop
                // selection

                if (mouse.selectTackle())
                {

                    //disable mouse
                    eventBattle.mouseButton.x = 0; // disables mouse durring loop to prevent it overlooping
                    eventBattle.mouseButton.y = 0;

                    //move
                    command.tackle(*party1, opp);

                    //text
                    hp_pokemon.setString(std::to_string(opp.hpNow));
                    text2.setString("My Pokemon Executed"
                                    "\nTackle...");

                    //cpu's turn

                    //cpu descision maker
                    random = rand() % 99;
                    if (random <= 50) {
                        //move
                        command.electroShock(opp, *party1);

                        //text
                        hp_player.setString(std::to_string(party1->hpNow));

                    }
                        //goes for other one
                    else
                    {
                        //move
                        command.tackle(opp, *party1);

                        //text
                        hp_player.setString(std::to_string(party1->hpNow));

                    }


                    //cpuTurn(opp, *party1, text2, hp_player);
/*
                    if (party1->hpNow <= 0)
                    {
                        party1->hpNow = 0;
                        text2.setString("Game Over. Pikachu wins!");

                    }
                    else if (opp.hpNow <= 0)
                    {
                        opp.hpNow = 0;
                        text2.setString("Game Over.  Player 1 wins!");
                    }*/
                }

                if (mouse.selectElement())
                {
                    //disable mouse
                    eventBattle.mouseButton.x = 0; // disables mouse durring loop to prevent it overlooping
                    eventBattle.mouseButton.y = 0;

                    //move
                    if(pokemon == 0)
                    {
                        command.ember(*party1, opp);
                    }
                    else if(pokemon == 1)
                    {
                        command.vineWhip(*party1, opp);
                    }
                    else if(pokemon == 2)
                    {
                        command.bubbleBeam(*party1, opp);
                    }

                    //text
                    hp_pokemon.setString(std::to_string(opp.hpNow));
                    text2.setString(" My Pokemon Executed"
                                    "\nElementary attack...");

                    //cpu's turn
                    //cpuTurn(opp, *party1, text2, hp_player);
                    //cpu descision maker
                    random = rand() % 99;
                    if (random <= 50)
                    {
                        //move
                        command.electroShock(opp, *party1);

                        //text
                        hp_player.setString(std::to_string(party1->hpNow));

                    }
                        //goes for other one
                    else
                    {
                        //move
                        command.tackle(opp, *party1);

                        //text
                        hp_player.setString(std::to_string(party1->hpNow));


                    }

                    //


                }

                if (mouse.selectItems())
                {
                    std::cout << "items";
                    text2.setString("Your bag is empty!!\nDefeat more enemies\nto collect items.");
                }
                if (mouse.selectRun())
                {
                    std::cout << "run";
                    text2.setString("Attempt fail! \nYour Pokemon is not\nfast enough!");
                }
                if (party1->hpNow <= 0)
                {
                    party1->hpNow = 0;
                    text2.setString("Game Over. Pikachu wins!");
                    hp_player.setString(std::to_string(0));
                    //renderBattleScreen.close();
                }
                else if (opp.hpNow <= 0)
                {
                    opp.hpNow = 0;
                    text2.setString("Game Over.  Player 1 wins!");
                    hp_pokemon.setString(std::to_string(0));
                    //renderBattleScreen.close();
                }
            }
        }

        renderBattleScreen.clear();
        renderBattleScreen.draw(sprite3);
        renderBattleScreen.draw(hp_player);
        renderBattleScreen.draw(hp_player_const);
        renderBattleScreen.draw(hp_pokemon);
        renderBattleScreen.draw(hp_pokemon_const);
        renderBattleScreen.draw(text2);
        renderBattleScreen.display();

    }
}
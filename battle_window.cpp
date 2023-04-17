//
// Created by kskos on 3/29/2023.
//
#include "pokemonConfig.h"

void stageBattle(int pokemon)
{
    /// initialization and assigning, starting sfml window

    // initializing the mouse obj
    Mouse mouse{};

    //itilizing the pokemon and their values with a constructor from pkmn class
    Pokemon charmander("Charmander", Fire, 50, 6, 3,3);
    Pokemon squirtle("Squirtle", Water, 50, 6, 4,3);
    Pokemon bulbasuar("Bulbasuar", Grass, 50, 5, 3,3);
    Pokemon pikachu("Pikachu", Electric, 50, 5, 2,5);
    Pokemon *party1;

    // party assignment (ptr party1 will assign its memory to an initilized pkmn so that each move command doesnt need to be
    // rewritten) acting like a party system for battle
    if(pokemon == 0)
    {
        party1 = &charmander;
    }
    else if(pokemon == 1)
    {
        party1 = &bulbasuar;
    }
    else //squirtle is default in the listings to prevent the party1 from not being init
    {
        party1 = &squirtle;
    }

    //assigning the opponent's party ptr to pikachu because pikachu is always the opponent
    Pokemon &opp = pikachu;

    // init moves command and random
    Moves command;
    int random;
    //Moves * moveSetE;
    //Moves moveSet2;
    //bool oppSelected;
    //bool isDone;


    //render window
    sf::RenderWindow renderBattleScreen(sf::VideoMode(1200, 800),
                                        "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");
    //font
    sf::Font font;
    if (!font.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/PKMNRBYGSC.ttf"))
    {
        std::cout << "font error";
    }

    //render event and background
    sf::Event eventBattle{};
    sf::Texture BattleBackground;

    ///Text config

    // select text box
    sf::Text text2;
    text2.setFont(font); //font
    text2.setString("Select  Attack...");  //str
    text2.setCharacterSize(24); // in pixels, not points!
    text2.setPosition(120, 630); // pos
    text2.setFillColor(sf::Color::Black); // color

    // opponent text box
    // opponent current health
    sf::Text hp_pokemon;
    hp_pokemon.setFont(font);  // font
    hp_pokemon.setString(std::to_string(opp.hpNow));  // displays current health
    hp_pokemon.setCharacterSize(20); // size in pixels, not points!
    hp_pokemon.setPosition(325, 140); // pos of str
    hp_pokemon.setFillColor(sf::Color::Black);  // color

    // opponent total health
    sf::Text hp_pokemon_const;
    hp_pokemon_const.setFont(font);  // font
    hp_pokemon_const.setString(opp.health()); // total health pts
    hp_pokemon_const.setCharacterSize(20); // in pixels, not points!
    hp_pokemon_const.setPosition(420, 140);  // pos of str
    hp_pokemon_const.setFillColor(sf::Color::Black);  // color

    // pokemon text box
    // pokemon current health
    sf::Text hp_player;
    hp_player.setFont(font);  //font
    hp_player.setString(std::to_string(party1->hpNow));  // displays current health
    hp_player.setCharacterSize(20); // in pixels, not points!
    hp_player.setPosition(900, 475);  //pos
    hp_player.setFillColor(sf::Color::Black);  //color

    // pokemon total health
    sf::Text hp_player_const;
    hp_player_const.setFont(font); // font
    hp_player_const.setString(party1->health()); // displays total health pts
    hp_player_const.setCharacterSize(20); // in pixels, not points!
    hp_player_const.setPosition(980, 475);  // pos
    hp_player_const.setFillColor(sf::Color::Black);  // color

    //different images based on the pkmn selection
    switch(pokemon)
    {
        case 0:  // charmander
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/char_battle_1frame.png");
            break;
        case 1:  // bulbasuar
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/bulba_battle_1frame.png");
            break;
        default:  // squirtle
            BattleBackground.loadFromFile("C:/Users/kskos/CLionProjects/PokemonBlueCpp/squir_battle_1frame.png");
            break;
    }

    //sprite texture
    sf::Sprite sprite3(BattleBackground);

    ///process
    while (renderBattleScreen.isOpen())
    {
        while (renderBattleScreen.pollEvent(eventBattle))
        {
            if (eventBattle.type == sf::Event::EventType::Closed)
            {
                renderBattleScreen.close();
            }
        }
        if (eventBattle.type == sf::Event::EventType::Closed)
        {
            renderBattleScreen.close();
        }
        if (eventBattle.type == sf::Event::MouseButtonPressed)
        {
            if (eventBattle.mouseButton.button == sf::Mouse::Left)
            {
                mouse.pos3X = eventBattle.mouseButton.x;  // mouse coord x for clicking
                mouse.pos3Y = eventBattle.mouseButton.y;  // mouse coord y for clicking

                ///battle loop selection

                //select tackle
                if (mouse.selectTackle() && (party1->hpNow > 0 && opp.hpNow > 0))  // will allow to click if the pkmn arent dead or won
                {
                    ///trnr turn

                    //disable mouse
                    eventBattle.mouseButton.x = 0; // disables mouse x durring loop to prevent it overlooping
                    eventBattle.mouseButton.y = 0; // disables mouse y

                    //move // move for all pokemon choices
                    command.tackle(*party1, opp);

                    //text change
                    hp_pokemon.setString(std::to_string(opp.hpNow));
                    text2.setString(party1->retName() + " Executed \nTackle...");

                    ///cpu's turn

                    //cpu descision maker
                    random = rand() % 99;
                    if (random <= 50) //element // chances of picking element
                    {
                        //move
                        command.electroShock(opp, *party1);

                        //text
                        hp_player.setString(std::to_string(party1->hpNow));
                    }
                    else // tackle
                    {
                        //move
                        command.tackle(opp, *party1);

                        //text change
                        hp_player.setString(std::to_string(party1->hpNow));
                    }
                }

                //select element attack
                if (mouse.selectElement() && (party1->hpNow > 0 && opp.hpNow > 0)) // will allow to click if the pkmn arent dead or won
                {
                    ///trnr turn

                    //disable mouse
                    eventBattle.mouseButton.x = 0; // disables mouse x durring loop to prevent it overlooping
                    eventBattle.mouseButton.y = 0; // ditto for mouse y

                    //move based on what pokemon was picked
                    if(pokemon == 0) //charmander
                    {
                        command.ember(*party1, opp);
                    }
                    else if(pokemon == 1) // bulbasuar
                    {
                        command.vineWhip(*party1, opp);
                    }
                    else // squirtle
                    {
                        command.bubbleBeam(*party1, opp);
                    }

                    //text change
                    hp_pokemon.setString(std::to_string(opp.hpNow));
                    text2.setString(party1->retName() + " Executed \nElement...");

                    ///cpu's turn

                    //cpu descision maker
                    random = rand() % 99;
                    if (random <= 50) // element // chances of picking element
                    {
                        //move
                        command.electroShock(opp, *party1);

                        //text change
                        hp_player.setString(std::to_string(party1->hpNow));
                    }
                    else //tackle
                    {
                        //move
                        command.tackle(opp, *party1);

                        //text change
                        hp_player.setString(std::to_string(party1->hpNow));
                    }
                }

                /// other options in selection

                // items button
                if (mouse.selectItems())
                {
                    std::cout << "items";
                    text2.setString("Your bag is empty!!\nDefeat more enemies\nto collect items.");
                }

                // run button
                if (mouse.selectRun())
                {
                    std::cout << "run";
                    text2.setString("Attempt fail! \nYour Pokemon is not\nfast enough!");
                }

                /// Win conditions

                // opponent wins
                if (party1->hpNow <= 0)
                {
                    party1->hpNow = 0;
                    text2.setString("Game Over. " + opp.retName() + "  wins!"); // says oppenent's pkmn name
                    hp_player.setString(std::to_string(0));
                    //renderBattleScreen.;
                }

                // player wins
                if (opp.hpNow <= 0)
                {
                    opp.hpNow = 0;
                    text2.setString("Game Over. " + party1->retName() + "  wins!"); // says player's pkmn name
                    hp_pokemon.setString(std::to_string(0)); // makes sure the str is set to 0
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

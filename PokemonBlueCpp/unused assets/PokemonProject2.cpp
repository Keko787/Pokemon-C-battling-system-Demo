//
// Created by Paulo Drefahl on 9/7/2022.
//

// Demonstrate sprite drawing in SFML
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"
#include "pokemonConfig.h"
#include "cstdlib"

void renderBattle(int pokemon);
void UpdateHP(int Attack, int &pikachu_hp);

int main() {
    //Variables
    int mousePosX, mousePosY;
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
    if (!font.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/PKMNRBYGSC.ttf")) {
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
    pokemonSelectionImg.loadFromFile("");
    mainMenuImg.loadFromFile("");
    sf::Sprite sprite(mainMenuImg);
    sf::Sprite sprite2(pokemonSelectionImg);


    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mousePosX = event.mouseButton.x;
                    mousePosY = event.mouseButton.y;

                    if (mousePosX > 209 && mousePosX < 411 && mousePosY < 678 && mousePosY > 640) {
                        std::cout << "Start game" << std::endl;
                        renderWindow.close();


                        sf::RenderWindow renderSelection(sf::VideoMode(1200, 800),
                                                         "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio");
                        while (renderSelection.isOpen()) {
                            while (renderSelection.pollEvent(event1)) {
                                if (event1.type == sf::Event::EventType::Closed)
                                    renderSelection.close();

                                if (event1.type == sf::Event::MouseButtonPressed) {
                                    if (event1.mouseButton.button == sf::Mouse::Left) {
                                        int mousePos1X = event1.mouseButton.x;
                                        int mousePos1Y = event1.mouseButton.y;

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 113 && mousePos1Y < 181) {
                                            pokemon = 0;
                                            text.setString("Charmander  Selected.");
                                        }

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 279 && mousePos1Y < 339) {
                                            pokemon = 1;
                                            text.setString("Bulbasaur  Selected.");
                                        }

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 437 && mousePos1Y < 499) {
                                            pokemon = 2;
                                            //Pokemon Squirtle()
                                            text.setString("Squirtle  Selected.");
                                        }
                                        if (mousePos1X > 952 && mousePos1X < 1148 && mousePos1Y > 638 && mousePos1Y < 690) {
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

                    if (mousePosX > 513 && mousePosX < 659 && mousePosY < 678 && mousePosY > 640) {
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

void renderBattle(int pokemon) {
    bool Poke1IsAlive = true;
    bool PokeCPUIsAlive = true;
    int pokemon_hp = 50, player_hp = 50;
    int Tackle = 1, ElemAttack = 3;
    int sum;

    sf::RenderWindow renderBattleScreen(sf::VideoMode(1200, 800),
                                        "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio");
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/Poke_Menu_WIP.png")) {
        std::cout << "font error";
    }
    sf::Event eventBattle;

    sf::Texture BattleBackground;

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Select  Attack...");
    text2.setCharacterSize(24); // in pixels, not points!
    text2.setPosition(70, 630);
    text2.setFillColor(sf::Color::Black);

    sf::Text hp_pokemon;
    hp_pokemon.setFont(font);
    hp_pokemon.setString(std::to_string(pokemon_hp));
    hp_pokemon.setCharacterSize(20); // in pixels, not points!
    hp_pokemon.setPosition(365, 162);
    hp_pokemon.setFillColor(sf::Color::Black);

    sf::Text hp_pokemon_const;
    hp_pokemon_const.setFont(font);
    hp_pokemon_const.setString("50");
    hp_pokemon_const.setCharacterSize(20); // in pixels, not points!
    hp_pokemon_const.setPosition(430, 162);
    hp_pokemon_const.setFillColor(sf::Color::Black);


    sf::Text hp_player;
    hp_player.setFont(font);
    hp_player.setString(std::to_string(player_hp));
    hp_player.setCharacterSize(20); // in pixels, not points!
    hp_player.setPosition(980, 475);
    hp_player.setFillColor(sf::Color::Black);

    sf::Text hp_player_const;
    hp_player_const.setFont(font);
    hp_player_const.setString("50");
    hp_player_const.setCharacterSize(20); // in pixels, not points!
    hp_player_const.setPosition(1052, 475);
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


    while (renderBattleScreen.isOpen()) {

        while (renderBattleScreen.pollEvent(eventBattle)) {
            if (eventBattle.type == sf::Event::EventType::Closed)
                renderBattleScreen.close();
        }
        if (eventBattle.type == sf::Event::EventType::Closed) {
            renderBattleScreen.close();
        }
        if (eventBattle.type == sf::Event::MouseButtonPressed) {


            if (eventBattle.mouseButton.button == sf::Mouse::Left) {
                int mousePos2X = eventBattle.mouseButton.x;
                int mousePos2Y = eventBattle.mouseButton.y;

                if (mousePos2X > 783 && mousePos2X < 919 && mousePos2Y > 608 && mousePos2Y < 639) {
                    int random;
                    random = rand() % 99;
                    if (random >= 85) {
                        pokemon_hp -= Tackle;
                    }
                    hp_pokemon.setString(std::to_string(pokemon_hp));
                    text2.setString("Pokemon Executed"
                                    "\nTackle...");

                    random = rand() % 99;
                    if (random > 60) {
                        if (random >= 90) {
                            player_hp -= Tackle;
                        }
                        hp_player.setString(std::to_string(player_hp));
                        text2.setString("Pokemon Executed"
                                        "\nTackle...");
                    } else {
                        random = rand() % 99;
                        if (random >= 97) {
                            player_hp -= ElemAttack;
                        }
                        hp_player.setString(std::to_string(player_hp));
                        text2.setString("Pokemon Executed"
                                        "\nElementary attack...");
                    }
                    if (player_hp <= 0){
                        text2.setString("Game Over. Pikachu wins!");
                    }
                    else if (pokemon_hp <= 0){
                        text2.setString("Game Over.  Player 1 wins!");
                    }
                }
                if (mousePos2X > 786 && mousePos2X < 998 && mousePos2Y > 683 && mousePos2Y < 740) {
                        int random;
                        random = rand() % 99;
                        if (random >= 95) {
                            pokemon_hp -= ElemAttack;
                        }
                        hp_pokemon.setString(std::to_string(pokemon_hp));
                        text2.setString("Pokemon Executed"
                                        "\nElementary attack...");

                    random = rand() % 99;
                    if (random > 60) {
                        if (random >= 90) {
                            player_hp -= Tackle;
                        }
                        hp_player.setString(std::to_string(player_hp));
                        text2.setString("Pokemon Executed"
                                        "\nTackle...");
                    } else {
                        random = rand() % 99;
                        if (random >= 97) {
                            player_hp -= ElemAttack;
                        }
                        hp_player.setString(std::to_string(player_hp));
                        text2.setString("Pokemon Executed"
                                        "\nElementary attack...");
                    }
                    if (player_hp <= 0){
                        text2.setString("Game Over. Pikachu wins!");
                    }
                    else if (pokemon_hp <= 0){
                        text2.setString("Game Over.  Player 1 wins!");
                    }
                }
                if (mousePos2X > 1044 && mousePos2X < 1161 && mousePos2Y > 616 && mousePos2Y < 638) {
                    std::cout << "items";
                    text2.setString("Your bag is empty!!\nDefeat more enemies to collect items.");
                }
                if (mousePos2X > 1062 && mousePos2X < 1135 && mousePos2Y > 707 && mousePos2Y < 725) {
                    std::cout << "run";
                    text2.setString("Attempt fail! \nYour Pokemon is not fast enough!");
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


//
// Created by kskos on 10/25/2022.
//

#ifndef POKEMONBLUECPP_POKEMONCONFIG_H
#define POKEMONBLUECPP_POKEMONCONFIG_H
/******************************************************************************************************************/
///libraries
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"
#include <cstdlib>
#include <utility>

/// stage functions
void stageStart();
void stageSelect();
void stageBattle(int pokemon);

//testing debug
//void UpdateHP(int Attack, int &pikachu_hp);

/// mouse
class Mouse{
public:
    //mouse cords
    //int dll = 0;
    int pos1X, pos1Y;
    int pos2X, pos2Y;
    int pos3X, pos3Y;

    ///check flags for mouse click

    bool selectStart() const
    {
        return pos1X > 209 && pos1X < 411 && pos1Y < 678 && pos1Y > 640;
    }

    bool selectExit() const
    {
        return pos1X > 513 && pos1X < 659 && pos1Y < 678 && pos1Y > 640;
    }

    bool selectCharm() const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 113 && pos2Y < 181;
    }
    bool selectBulb() const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 279 && pos2Y < 339;
    }

    bool selectSquir() const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 437 && pos2Y < 499;
    }

    bool selectGoBattle() const
    {
        return pos2X > 952 && pos2X < 1148 && pos2Y > 638 && pos2Y < 690;
    }

    bool selectTackle() const
    {
        return pos3X > 680 && pos3X < 803 && pos3Y > 634 && pos3Y < 656;
    }

    bool selectElement() const
    {
        return pos3X > 680 && pos3X < 879 && pos3Y > 694 && pos3Y < 740;
    }

    bool selectItems() const
    {
        return pos3X > 966 && pos3X < 1071 && pos3Y > 634 && pos3Y < 653;
    }

    bool selectRun() const
    {
        return pos3X > 966 && pos3X < 1037 && pos3Y > 694 && pos3Y < 714;
    }
};

/// pokemon
// (each pokemon set the to a dex value, each dex is a class of the pokemon)
enum { Grass = 1, Water = 2, Fire = 3, Electric = 4};

//pokemon stats and calls
class Pokemon {
    std::string name;
    int type1;
    int hp ;
    int spd;
    int atk;
    int def;
public:
    int hpNow;

    Pokemon(){}

    Pokemon(std::string name1,int type, int hpo, int atck, int defe, int sped)
    {
        this->type1 = type;
        this->hp = hpo;
        this->hpNow = hp;
        this->spd = sped;
        this->atk = atck;
        this->def = defe;
        this->name = std::move(name1);
    }

    Pokemon(Pokemon *pPokemon) {}
    // when brought into the moves class, each function will have to be assigned to a variable

    int type()
    {
        return type1;
    }

    std::string health()
    {
        return std::to_string(hp);
    }

    int attack()
    {
        return atk;
    }

    int defense()
    {
        return def;
    }

    int speed()
    {
        return spd;
    }

    std::string retName()
    {
        return name;
    }

    /*bool isdead()
    {
        if(hpNow <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }*/
};


///moves
class Moves {
    //int use;
    //int limit; //int totalHealth;
public:
    void tackle(Pokemon attack, Pokemon &defend);
    void vineWhip(Pokemon attack, Pokemon &defend);
    void ember(Pokemon attack, Pokemon &defend);
    void bubbleBeam(Pokemon attack, Pokemon &defend);
    void electroShock(Pokemon attack, Pokemon &defend);
};


/****************************************************************************************************************/
#endif //POKEMONBLUECPP_POKEMONCONFIG_H
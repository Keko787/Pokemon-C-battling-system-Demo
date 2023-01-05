//
// Created by kskos on 10/25/2022.
//

#ifndef POKEMONBLUECPP_POKEMONCONFIG_H
#define POKEMONBLUECPP_POKEMONCONFIG_H
/******************************************************************************************************************/
//libraries
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"
#include <cstdlib>

// mouse pos
class Mouse{
public:
    //mouse cords
    //int dll = 0;
    int pos1X, pos1Y;
    int pos2X, pos2Y;
    int pos3X, pos3Y;

    //loop check
    /*bool selectOver()
    {
        bool selection;
        selection = select1() || select2() || select3();
        return selection;
    }*/

    /*bool turnOver()
    {

    }*/

    //check flags

    bool start() const
    {
        return pos1X > 209 && pos1X < 411 && pos1Y < 678 && pos1Y > 640;
    }

    bool exit() const
    {
        return pos1X > 513 && pos1X < 659 && pos1Y < 678 && pos1Y > 640;
    }

    bool select1 () const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 113 && pos2Y < 181;
    }
    bool select2() const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 279 && pos2Y < 339;
    }

    bool select3() const
    {
        return pos2X > 927 && pos2X < 1163 && pos2Y > 437 && pos2Y < 499;
    }

    bool goBattle() const
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



// pokemon (each pokemon set the to a dex value, each dex is a class of the pokemon) (pokemon is it's own class)

enum { Grass = 1, Water = 2, Fire = 3, Electric = 4};


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
        this->name = name1;
    }

    Pokemon(Pokemon *pPokemon) {}

    // when brought into the moves class, each function will have to be assigned to a variable

    int type()
    {
        return type1;
    }

    int health()
    {
        return hp;
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

    bool isdead()
    {
        if(hpNow <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


};

class Moves {

    //int use;
    //int limit; //int totalHealth;


public:

    void tackle(Pokemon attack, Pokemon &defend)
    {
        //initilize stat
        int power;
        int negate;
        int * currentHealth;
        int random;


        // assign all stats
        currentHealth = & defend.hpNow;
        negate = defend.defense();
        power = attack.attack();

        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random <= 99)
        {
            // power boost
            power *= 1;


            //final math+negate
            *currentHealth = *currentHealth - power + negate ;
        }

    }

    void vineWhip(Pokemon attack, Pokemon &defend)
    {
        //initilize stat
        int power;
        int negate;
        int * currentHealth;
        int random;

        // assign all stats
        currentHealth = & defend.hpNow;;
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random <= 75)
        {
            // power boost
            power *= 2;

            // typing buff or debuff
            if (defend.type() == Water)
            {
                power *= 2;
            }
            else if (defend.type() == Fire)
            {
                power /= 2;
            }

            //final math
            *currentHealth = *currentHealth - power + negate;
        }

    }

    int ember(Pokemon attack, Pokemon &defend)
    {
        //initilize stat
        int power;
        int negate;
        int * currentHealth;
        int random;

        // assign all stats
        currentHealth = & defend.hpNow;
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random <= 75)
        {
            // power boost
            power *= 2;

            // typing buff or debuff
            if (defend.type() == Grass)
            {
                power *= 2;
            }
            else if (defend.type() == Water)
            {
                power /= 2;
            }

            //final math
            *currentHealth = *currentHealth - power + negate;
        }

    }

    int bubbleBeam(Pokemon attack, Pokemon &defend)
    {
        // hour count of fixing bubblebeam: 3

        //initilize stat
        int power;
        int negate;
        int * currentHealth;
        int random;

        // assign all stats
        currentHealth = & defend.hpNow;;
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random <= 75)
        {
            // power boost
            power *= 2;

            // typing buff or debuff
            if (defend.type() == Fire)
            {
                power *= 2;
            }
            else if (defend.type() == Grass)
            {
                power /= 2;
            }

            //final math
            *currentHealth = *currentHealth - power + negate;
        }

    }


    void electroShock(Pokemon attack, Pokemon &defend)
    {
        //initilize stat
        int power;
        int negate;
        int * currentHealth;
        int random;

        // assign all stats
        currentHealth = & defend.hpNow;;
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random <= 75)
        {
            // power boost
            power *= 2;

            // typing buff or debuff
            if (defend.type() == Water)
            {
                power *= 2;
            }
            else if (defend.type() == Grass)
            {
                power /= 2;
            }

            //final math
            std::cout << power << std::endl;
            *currentHealth = *currentHealth - power + negate;
        }

    }
};


/*void cpuTurn(Pokemon & cpu, Pokemon & player, sf::Text text2, sf::Text hp_player)
{
    Moves command;
    bool oppSelected = false;
    int random;




    //cpu descision maker
    random = rand() % 99;
    if (random > 1)
    {
        //move
        command.tackle(cpu, player);

        //text
        hp_player.setString(std::to_string(player.hpNow));
        text2.setString("Pokemon Executed"
                        "\nTackle...");
    }
        //goes for other one
    else
    {
        //move
        command.electroShock(cpu, player);

        //text
        hp_player.setString(std::to_string(player.hpNow));
        text2.setString("Pokemon Executed"
                        "\nElementary attack...");

    }

}*/


//void charbattle

//class battle{};


/****************************************************************************************************************/
#endif //POKEMONBLUECPP_POKEMONCONFIG_H
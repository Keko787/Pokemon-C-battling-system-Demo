//
// Created by Kevin Kostage on 3/29/2023.
//

/// NOTE: STARS MEAN TEST CODE FOR UPDATE

///class, functions, defs
#include "pokemonConfig.h"

/// tackle

void Moves::tackle(Pokemon attack, Pokemon &defend)
{
    /**
     * desc: the common move all the pokemon have and is the most consistent move, it uses ptr to change the values of
     * defending Pokemon at the end.
     * param: attack (Pokemon): represent the attacking Pokemon's copied values when calculate the final dmg calc.
     * param: &defend (Pokemon): represent the defending Pokemon's direct values when calculate the final dmg calc.
     * return: n/a due to the use of ptr
     */

    //initialize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;  // only stat that isn't being copied but transferred is the defends current health
    negate = defend.defense();
    power = attack.attack();

    //*move use counter and use limiter*

    // accuracy check
    random = rand() % 99;
    if (random <= 99) // guaranteed
    {
        // power boost
        power *= 1; //no change

        // no type buff/de-buff

        //final math
        *currentHealth = *currentHealth - power + negate ;
    }
}

/// elements

void Moves::vineWhip(Pokemon attack, Pokemon &defend)
{
    /**
     * desc: an element move for grass types (specifically bulbasaur), it does more damage, but more likely to miss, it
     * uses ptr to change the values of defending Pokemon at the end.
     * param: attack (Pokemon): represent the attacking Pokemon's copied values when calculate the final dmg calc.
     * param: &defend (Pokemon): represent the defending Pokemon's direct values when calculate the final dmg calc.
     * return: n/a due to the use of ptr
     */

    //initialize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = &defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();

    //*move use counter and use limiter*
    //*if(use > limit)*

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  // value: chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or de-buff
        if (defend.type() == Water) {
            power *= 2;  // buff
        }
        if (defend.type() == Fire) {
            power /= 2;  // de-buff
        }

        //final math // the function doesn't return the current health because it is already been changed
        // since it's attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }

    // *else {*
    // *print it missed*
   //}
}

void Moves::ember(Pokemon attack, Pokemon &defend)
{
    /**
     * desc: an element move for fire types (specifically charmander), it does more damage, but more likely to miss, it
     * uses ptr to change the values of defending Pokemon at the end.
     * param: attack (Pokemon): represent the attacking Pokemon's copied values when calculate the final dmg calc.
     * param: &defend (Pokemon): represent the defending Pokemon's direct values when calculate the final dmg calc.
     * return: n/a due to the use of ptr
     */

    //initialize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;
    negate = defend.defense();
    power = attack.attack();

    //*move use counter and use limiter*
    //*if(use > limit)*

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  // value: chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or de-buff
        if (defend.type() == Grass)
        {
            power *= 2; // buff
        }
        if (defend.type() == Water)
        {
            power /= 2; // de-buff
        }

        // final math // the function doesn't return the current health because it is already been changed
        // since It's attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}

void Moves::bubbleBeam(Pokemon attack, Pokemon &defend)
{
    /**
     * desc: an element move for water types (specifically squirtle), it does more damage, but more likely to miss, it
     * uses ptr to change the values of defending Pokemon at the end.
     * param: attack (Pokemon): represent the attacking Pokemon's copied values when calculate the final dmg calc.
     * param: &defend (Pokemon): represent the defending Pokemon's direct values when calculate the final dmg calc.
     * return: n/a due to the use of ptr
     */

    //initialize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();

    //*move use counter and use limiter*
    //*if(use > limit)*

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  // value: chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or de-buff
        if (defend.type() == Fire) // buff
        {
            power *= 2;  //buff
        }
        if (defend.type() == Grass) // de-buff
        {
            power /= 2;  //de-buff
        }

        //final math // the function doesn't return the current health because it is already been changed
        // since It's attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}


void Moves::electroShock(Pokemon attack, Pokemon &defend)
{
    /**
     * desc: an element move for electric types (specifically pikachu), it does more damage, but more likely to miss, it
     * uses ptr to change the values of defending Pokemon at the end. This is for the opponent's move.
     * param: attack (Pokemon): represent the attacking Pokemon's copied values when calculate the final dmg calc.
     * param: &defend (Pokemon): represent the defending Pokemon's direct values when calculate the final dmg calc.
     * return: n/a due to the use of ptr
     */

    //initialize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = &defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();

    //*move use counter and use limiter*
    //*if(use > limit)*

    // accuracy check
    random = rand() % 99;
    if (random <= 99) // value: chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or de-buff
        if (defend.type() == Water)
        {
            power *= 2; // buff
        }
        if (defend.type() == Grass)
        {
            power /= 1;  // de-buff // keep at until balance solution found
        }

        //final math // the function doesn't return the current health because it is already been changed
        // since It's attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}

/*void cpuTurn(Pokemon & cpu, Pokemon & player, sf::Text text2, sf::Text hp_player)**
{
    Moves command;
    bool oppSelected = false;
    int random;

    //cpu decision maker
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

//**loop check***
/*bool selectOver()***
{
    bool selection;
    selection = selectCharm() || selectBulb() || selectSquir();
    return selection;
}**/

/*bool turnOver()***
{

}****/
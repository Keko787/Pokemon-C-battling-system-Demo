//
// Created by kskos on 3/29/2023.
//
#include "pokemonConfig.h"

/// tackle

void Moves::tackle(Pokemon attack, Pokemon &defend)
{
    //initilize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;  // only stat that isnt being coppied but transfered is the defend's current health
    negate = defend.defense();
    power = attack.attack();

    //move use counter and use limiter

    // accuracy check
    random = rand() % 99;
    if (random <= 99) // guaranteed
    {
        // power boost
        power *= 1; //no change

        // no type buff/debuff

        //final math
        *currentHealth = *currentHealth - power + negate ;
    }
}


/// element

void Moves::vineWhip(Pokemon attack, Pokemon &defend) {
    //initilize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = &defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();
    //move use counter and use limiter

    //if(use > limit)

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  //chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or debuff
        if (defend.type() == Water) {
            power *= 2;  // buff
        }
        if (defend.type() == Fire) {
            power /= 2;  // debuff
        }

        //final math // the function doesnt returns the current health because it is already been changed
        // since its attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
    // else {
    // print it missed
   //}
}

void Moves::ember(Pokemon attack, Pokemon &defend)
{
    //initilize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;
    negate = defend.defense();
    power = attack.attack();
    //move use counter and use limiter

    //if(use > limit)

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  //chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or debuff
        if (defend.type() == Grass)
        {
            power *= 2; // buff
        }
        if (defend.type() == Water)
        {
            power /= 2; // debuff
        }

        // final math // the function doesnt returns the current health because it is already been changed
        // since its attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}

void Moves::bubbleBeam(Pokemon attack, Pokemon &defend)
{
    //initilize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = & defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();
    //move use counter and use limiter

    //if(use > limit)

    // accuracy check
    random = rand() % 99;
    if (random <= 99)  //chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or debuff
        if (defend.type() == Fire) // buff
        {
            power *= 2;  //buff
        }
        if (defend.type() == Grass) // debuff
        {
            power /= 2;  //debuff
        }

        //final math // the function doesnt returns the current health because it is already been changed
        // since its attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}


void Moves::electroShock(Pokemon attack, Pokemon &defend)
{
    //initilize stat
    int power;
    int negate;
    int *currentHealth;
    int random;

    // assign all stats
    currentHealth = &defend.hpNow;;
    negate = defend.defense();
    power = attack.attack();
    //move use counter and use limiter

    //if(use > limit)

    // accuracy check
    random = rand() % 99;
    if (random <= 99) //chances of hitting
    {
        // power boost
        power *= 2;

        // typing buff or debuff
        if (defend.type() == Water)
        {
            power *= 2; // buff
        }
        if (defend.type() == Grass)
        {
            power /= 1;  // debuff // keep at until balance solution found
        }

        //final math // the function doesnt returns the current health because it is already been changed
        // since its attached to ptr
        *currentHealth = *currentHealth - power + negate;
    }
}

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

//loop check
/*bool selectOver()
{
    bool selection;
    selection = selectCharm() || selectBulb() || selectSquir();
    return selection;
}*/

/*bool turnOver()
{

}*/
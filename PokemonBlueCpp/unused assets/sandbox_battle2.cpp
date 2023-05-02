#include <iostream>
#include<cstdlib>

using namespace std;

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
    //int limit;
    int power;
    int negate;
    int * currentHealth;
    //int totalHealth;
    int random;

public:

    void tackle(Pokemon &attack, Pokemon &defend)
    {
        // assign all stats
        negate = defend.defense();
        power = attack.attack();

        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random >= 95)
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
                power -= 20;
            }

            //final math
            defend.hpNow = defend.hpNow - power + negate;
        }

    }

    int vineWhip(Pokemon &attack, Pokemon &defend)
    {
        // assign all stats
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random >= 95)
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
                power -= 20;
            }

            //final math
            defend.hpNow = defend.hpNow - power + negate;
        }

    }

    void ember(Pokemon &attack, Pokemon &defend)
    {
        // assign all stats

        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random >= 95)
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
                power -= 20;
            }

            //final math
            defend.hpNow = defend.hpNow - power + negate;
        }

    }

    void bubbleBeam(Pokemon &attack, Pokemon &defend)
    {
        // assign all stats
        negate = defend.defense();
        power = attack.attack();
        //move use counter and use limiter

        //if(use > limit)

        // accuracy check
        random = rand() % 99;
        if (random >= 30)
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
                power -= 20;
            }

            //final math
            defend.hpNow = defend.hpNow - power + negate;
        }
    }
};

//class battle{

int main()
{
    Pokemon squirtle("squirtle",Water, 150, 50, 50, 25);
    Pokemon pikachu("pikachu",Electric, 1000, 37, 15, 45);

    //Moves command;
    Pokemon &player = squirtle;
    Pokemon &opponent = pikachu;

    Moves command;
    //Moves * moveSetE;

    //moveSetE->bubbleBeam(player, opponent);

    //moveSetE;

    std::cout << pikachu.hpNow << std::endl;
    std::cout << opponent.hpNow << std::endl;

    command.bubbleBeam(player,opponent);

    std::cout << pikachu.hpNow << std::endl;
    std::cout << opponent.hpNow << std::endl;

    command.bubbleBeam(player,opponent);

    std::cout << opponent.hpNow << std::endl;

    command.bubbleBeam(player,opponent);

    std::cout << opponent.hpNow << std::endl;

    return 0;

}
/*
void cpuTurn(Pokemon & cpu, Pokemon & player)
{
    Moves command;
    bool oppSelected = false;
    int random;


    while(!oppSelected)
    {
        //cpu descision maker
        random = rand() % 99;
        if (random > 60)
        {
            //move
            command.tackle(cpu, player);

            //text
            cout << "i did tackle" << endl;

            //end condition
            oppSelected = true;
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

            //end condition
            oppSelected = true;
        }

    }
}*/

/*
    while(party1.isdead() || opp.isdead())
    {
        // reseting mouse
        mouse.pos3X = eventBattle.mouseButton.x;
        mouse.pos3Y = eventBattle.mouseButton.y;

        //player's turn
        while(!isDone)
        {
            if (mouse.selectTackle())
            {
                isDone = false;
            }
            if (mouse.selectElement())
            {
                isDone = false;
            }
        }
        //turning off mouse after turn
        mouse.pos3X = 0;
        mouse.pos3Y = 0;

        //cpu turn
        while(oppSelected)
        {
            random = rand() % 99;
            if (random > 60)
            {

                hp_player.setString(std::to_string(player_hp));
                text2.setString("Pokemon Executed"
                                "\nTackle...");
            }

            else
            {
                random = rand() % 99;
                if (random >= 97)
                {
                    player_hp -= ElemAttack;
                }
                hp_player.setString(std::to_string(player_hp));
                text2.setString("Pokemon Executed"
                                "\nElementary attack...");
            }

        }

    }
    if(party1.isdead())
    {

    }
    else if(opp.isdead())
    {

    }

    return 0;
}

void battle(Pokemon &player, Pokemon &opponent)
{
    Moves command;
    bool playerTurn = true;

    //while(playerTurn)
    {
       //if()
       {

       }
       //if()
       {

       }
    }
*/
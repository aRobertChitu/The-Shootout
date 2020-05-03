#include<iostream>
#include "Agent.h"
using namespace std;

Agent::Agent( int x, int y, int armour, int weapon ){
        this -> agentX = x;
        this -> agentY = y;
        this -> agentARM = armour;
        this -> agentScore = weapon * 10 + armour; /// formula pentru a crea un agent cu arma si armura.
}

int Agent::getAgentLocationX() {

        return agentX;
}

int Agent::getAgentLocationY() {
        return agentY;
}

int Agent::getAgentScore() {
        return agentScore;
}

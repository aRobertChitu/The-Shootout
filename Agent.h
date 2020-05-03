#include <iostream>
using namespace std;

class Agent{

 int agentX;
 int agentY;
 int agentARM;
 int agentScore;

public:
    Agent( int, int, int, int );
    int getAgentLocationX();
    int getAgentLocationY();
    int getAgentScore();
};

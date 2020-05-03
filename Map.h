#include <iostream>
using namespace std;

class Map{

    int mapSize;
    int num=0;

    int next;
    int flag;

    int fire1=0;
    int fire2=3;

    int agentQx;
    int agentQy;
    int agentWx;
    int agentWy;
    int agentZx;
    int agentZy;
    int agentQarm;
    int agentWarm;
    int agentZarm;
    int a1;
    int a2;
    int a3;

    vector<vector<int> > matrixAgent;

public:
    Map ( int );
    void showMap();
    void searchPlayers();
    void addAgent( int, int, int);
    int showLocation( int, int );


    void Agent1Play();
    void Agent2Play();
    void Agent3Play();

    void play();

};

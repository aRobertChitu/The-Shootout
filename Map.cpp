#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <algorithm>
#include "Map.h"
using namespace std;
///HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);  acest lucru era folosit pentru culori
Map::Map(int mapSize)  /// constructor creare harta
{
    this -> mapSize = mapSize;
     for (int i = 0; i < mapSize+3; i++)
        {
            vector <int> v1;
            for (int j = 0; j < mapSize+3; j++)
            {
                v1.push_back( num );
            }
            matrixAgent.push_back( v1 );
        }
}    /// harta a fost construita pe baza unui vector de vectori alocati dinamic (din stl)


void Map::showMap() {
    for (int i = 0; i < mapSize; i++ ) {
        for (int j = 0; j < mapSize; j++ )
        {
            if( matrixAgent[i][j] == 0 )
            cout << matrixAgent[i][j] << "0 ";
            else
            {
///                SetConsoleTextAttribute( color, 1 );
                cout << matrixAgent[i][j] << " ";
///               SetConsoleTextAttribute( color, 15 );
            }
        }
        cout << endl;
    }

}
void Map::searchPlayers() {                     ///  caut cati playeri de pe harta si retin pozitile lor si informatiile despre ei
    for (int i = 0; i < mapSize; i++ ) {
        for (int j = 0; j < mapSize; j++ )
        {
            if ( matrixAgent[i][j] == 0 )
                continue;
            else
            {
                if ( matrixAgent[i][j] / 10 == 1 )
                {
                    agentQx = i;
                    agentQy = j;
                    a1 = matrixAgent[i][j];
                }
                else if ( matrixAgent[i][j] / 10 == 2)
                {
                    agentWx = i;
                    agentWy = j;
                    a2 = matrixAgent[i][j];
                }
                else
                {
                    agentZx = i;
                    agentZy = j;
                    a3 = matrixAgent[i][j];
                }
            }
        }
    }

}

void Map::addAgent ( int xPos, int yPos, int Value ) {  ///  folosita pentru a adauga agenti pe harta

    matrixAgent[xPos][yPos] = Value;

}

int Map::showLocation( int i, int j ) /// folosita pentru a returna valoarea de la o pozitie i,j
{
    return matrixAgent[i][j];
}

/// Agent1 Play, Agent2 Play, Agent3Play functioneaza identic, am sa comentez doar una.
/// Aceste metode decid ce se intampla cu anumiti agenti decid cand se misca, cand ataca sic and stau pe loc. precum si directia in care se misca si pe cine anume ataca.

void Map:: Agent1Play() {
    if( agentQx != 26 && agentQy != 26 ) {  /// intructiunea if are ca rol plasarea agentului inafar hartii pentru momentul in care moare
    cin >> next;
    flag = 0;
    for (int i = 0; i < mapSize; i++ )
        {
            for (int j = 0; j < mapSize; j++ )
            {
                if ( ( i <= ( agentQx + 3 ) && i >= ( agentQx - 3 ) ) && ( j <= ( agentQy + 3 ) && j >= ( agentQy - 3 ) ) ) /// aceasta este aria de vizibilitate (3 casute in roice directie
                {
                    if( showLocation( i, j ) != 0 && showLocation( agentQx, agentQy)!= showLocation(i, j) )  /// verific daca se afla vreun agent in aria de vizibilitate
                       {

                        flag = 1;
                        if( showLocation(i, j) == matrixAgent[agentWx][agentWy] )
                        {
                            a2 -= 2;
                            matrixAgent[ agentWx ][ agentWy ] -= 2;
                            if( ( matrixAgent[ agentWx ][ agentWy ] % 10 == 0 ) || ( matrixAgent[ agentWx ][ agentWy ] % 10 == 9) ) /// verific daca omor un agent
                            {
                                matrixAgent[ agentWx ][ agentWy ] = 0;
                                a2 = 0;
                                agentWx = 26;
                                agentWy = 26;
                            }
                        }
                        else
                        {
                            a3 -= 2;
                            matrixAgent[ agentZx ][ agentZy ] -= 2;
                            if ( ( matrixAgent[ agentZx ][ agentZy ] % 10 == 0 ) || ( matrixAgent[ agentZx ][ agentZy ]%10==9)) /// verific daca omor un agent si il elimin
                            {
                                matrixAgent[ agentZx ][ agentZy ]=0;
                                a3 = 0;
                                agentZx = 26;
                                agentZy = 26;
                            }

                        }
                        break;   /// break-ul il folsoesc pentru a nu ataca  2 agenti ina ceeasi tura.
                        }
                }


            }
        }
    if ( flag == 0)   /// cazul in care nu este nimeni in aria de vizibilitate
        {
            if (agentQy + 2 <= 24)  /// merg catre dreapta daca pot
            {
                matrixAgent[ agentQx ][ agentQy ] = 0;
                agentQy += 2;
                matrixAgent[ agentQx ][ agentQy ] = a1;

            }
            else if( agentQx -2 >=0)  /// altfel, merg in sus
            {
                matrixAgent[ agentQx ][ agentQy ] = 0;
                agentQx -= 2;
                matrixAgent[ agentQx ][ agentQy ] = a1;
            }

        }
      showMap(); /// afisez schimbarea facuta.
}

}
void Map::Agent2Play()
{
     if( agentWx != 26 && agentWy != 26 ){
  cin >> next;
      // agent 2 move
    flag = 0;
    for (int i = 0; i < mapSize; i++ )
        {
            for (int j = 0; j < mapSize; j++ )
            {
                if ( ( i <= ( agentWx + 3 ) && i >= ( agentWx - 3 ) ) && ( j <=( agentWy + 3 ) && j >= ( agentWy - 3 ) ) )
                {
                    if(showLocation(i,j) != 0 && matrixAgent[ agentWx ][ agentWy ] != showLocation(i,j))
                    {
                        flag = 1;
                        if(showLocation(i,j) == matrixAgent[ agentQx ][ agentQy ])
                        {
                            fire1 ++;
                            a1 -= fire1;
                            matrixAgent[ agentQx ][ agentQy ] -= fire1;
                            if( ( matrixAgent[ agentQx ][ agentQy ] % 10 == 0 ) || ( ( matrixAgent[ agentQx ][ agentQy ] / 10 ) != ( ( matrixAgent[ agentQx ][ agentQy ] + fire1 ) / 10 ) ) )
                            {
                                matrixAgent[ agentQx ][ agentQy ] = 0;
                                a1 = 0;
                                agentQx = 26;
                                agentQy = 26;
                            }
                        }
                        else
                        {
                            fire1 ++;
                            a3 -= fire1;
                            matrixAgent[ agentZx ][ agentZy ] -= fire1;
                            if( ( matrixAgent[ agentZx ][ agentZy ] % 10 == 0 ) || ( ( matrixAgent[ agentZx ][ agentZy ] / 10 ) != ( ( matrixAgent[ agentZx ][ agentZy ] + fire1 ) / 10 ) ) )
                            {
                                matrixAgent[ agentZx ][ agentZy ] = 0;
                                a3 = 0;
                                agentZx = 26;
                                agentZy = 26;
                            }

                        }
                        break;
                        }
                }


            }
        }
                if ( flag == 0)
                {
                    fire1 = 0;
                    if ( agentWy + 2 <= 24)
                    {
                        matrixAgent [ agentWx ][ agentWy ] = 0;
                        agentWy += 2;
                        matrixAgent [ agentWx ][ agentWy ] = a2;

                    }
                    else if( agentWx -2 >=0)
                    {
                        matrixAgent[ agentWx ][ agentWy ] = 0;
                        agentWx -= 2;
                        matrixAgent [ agentWx ][ agentWy ] = a2;
                    }

                }
        showMap();
}
}
void Map::Agent3Play()
{
if( agentZx != 26 && agentZy != 26 ) {
  cin >> next;
        // agent 3 move
    flag = 0;
    for (int i = 0; i < 25; i++ )
        {
            for (int j = 0; j < 25; j++ )
            {
                if ( ( i <= ( agentZx + 3 ) && i >= ( agentZx - 3 ) ) && ( j <= ( agentZy + 3 ) && j >= ( agentZy - 3 ) ) )
                {
                    if ( showLocation( i, j ) != 0 && matrixAgent[ agentZx ][ agentZy ] != showLocation( i, j ) )
                        {
                        flag = 1;
                        if (showLocation( i, j) == matrixAgent[ agentWx ][ agentWy ] )
                        {
                            a2 -= fire2;
                            matrixAgent [ agentWx ][ agentWy ] -= fire2;
                            if ( ( matrixAgent[ agentWx ][ agentWy ] % 10 == 0 ) || ( ( matrixAgent[ agentWx ][ agentWy ] / 10 ) != ( ( matrixAgent[ agentWx ][ agentWy ] + fire2 ) / 10 ) ) )
                            {
                                matrixAgent[ agentWx ] [ agentWy ] = 0;
                                a2 = 0;
                                agentWx = 26;
                                agentWy = 26;
                            }
                            if ( fire2 != 1 )
                                fire2 --;
                        }
                        else
                        {
                            a1 -= fire2 ;
                            matrixAgent[ agentQx ][ agentQy ] -= fire2;
                            if ( ( matrixAgent [ agentQx ] [ agentQy ] % 10 == 0 ) || ( ( matrixAgent[ agentQx ][ agentQy ] / 10) != ( ( matrixAgent[ agentQx ][ agentQy ] + fire2 ) / 10 ) ) )
                            {
                                matrixAgent[ agentQx ][ agentQy ] = 0;
                                a1 = 0;
                                agentQx = 26;
                                agentQy = 26;
                            }
                            if( fire2 != 1 )
                                fire2 --;

                        }
                        break;

                        }
                }


            }
        }
        if ( flag == 0 )
                {
                    fire2 = 3;
                    if ( agentZy + 2 <= 24 )
                    {
                        matrixAgent[ agentZx ][ agentZy ] = 0;
                        agentZy += 2;
                        matrixAgent[ agentZx ][ agentZy ] = a3;

                    }
                    else if( agentZx -2 >= 0 )
                    {
                        matrixAgent[ agentZx ][ agentZy ] = 0;
                        agentZx -= 2 ;
                        matrixAgent [ agentZx ][ agentZy ] = a3;
                    }

                }
    showMap();

}
}

void Map::play() /// in aceasta functie las agentii sa se joace, la final fac o verificare pentru a determina momentul in care mai exista un singur agent.
{
while(true)
    {
            Agent1Play();
            Agent2Play();
            Agent3Play();


           int contor=0;
            for (int i = 0; i < 25; i++ ) {
        for (int j = 0; j < 25; j++ )
        {
            if ( showLocation(i, j) != 0 )
                contor ++;
        }
        }

        if(contor==1)
        {
            cout << "Meci Terminat" ;
            break;
        }
    }
}


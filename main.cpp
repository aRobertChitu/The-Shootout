#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <algorithm>
#include "Agent.h"
#include "Map.h"
using namespace std;


int main()
{
    Map matrixAgent(25);

     Agent Agent1( 7, 12, 9 ,1 ); /// adaugam un agent la pozitia [7][12] cu armura 9 si cu arma de tip 1
     Agent Agent2( 9, 15, 4, 2 ); /// adaugam un agent la pozitia [9][15] cu armura 4 si cu arma de tip 2
     Agent Agent3( 3, 22, 7, 3);  /// adaugam un agent la pozitia [3][22] cu armura 3 si cu arma de tip 3
    matrixAgent.addAgent( Agent1.getAgentLocationX(), Agent1.getAgentLocationY(), Agent1.getAgentScore() ); ///adaugam primul agent
    matrixAgent.addAgent( Agent2.getAgentLocationX(), Agent2.getAgentLocationY(), Agent2.getAgentScore() ); ///adaugam al 2-lea agent
    matrixAgent.addAgent( Agent3.getAgentLocationX(), Agent3.getAgentLocationY(), Agent3.getAgentScore() ); /// adaugam al 3-lea agent

matrixAgent.showMap(); /// afisam cum arata harta intial
matrixAgent.searchPlayers(); ///cautam numarul de playeri de pe harta
matrixAgent.play(); /// Algoritmul pentru jocul in sine.

    return 0;
}

/// Fiecare agent este reprezentat pe harta printr-un numar de 2 cifre, cifra zeilor reprezinta arma pe care o foloseste iar cifra unitatilor reprezinta armura acestuia.
/// In acest joc toti agentii se misca catre dreapta pana cand ajung la marginea hartii, dupa se misca in sus. Cand nu se mai pot misca acestia stau pe loc .
/// In momentul in care 2 agenti se intalnesc, acestia incep sa se bata.
/// Un agent moare atunci cand armura acestuia este  <=0
/// Arma de tip 1 provoaca un numar de daune de exact 2 unitati.
/// Arma de tip 2 provoaca un numar de daune in continua crestere: Prima oara cand ataca cu aceasta provoaca 1 unitati daune, a doua oara 2 unitati... etc
/// Arma de tip 3 provoaca un numar de daune in continua scadere pana la 1: Porneste de la 3 unitati la primul atac, si ajunge la minim o unitate la cel de-al 3-lea atac.
/// Pe harta exista doar 3 agenti, fiecare avand arme diferite, ordinea de mutare a acestora este: Agentul cu arma tip 1, Agentul cu arma tip 2, Agentul cu arma rip 3... si dupa se reia de la primul.
/// Jocul se termian cand ramane un singur agent.
/// Pentru a se afisa urmatoare mutare, se va introduce de la tastatura o cifra oarecare


/// In timp ce faceam acest joc, am folosit windows.h pentru a colora agentii si harta pentru a fi vizibili usor insa nu stiam ca nu este cross-platform. credeam ca are legatura cu fereastra de afisare nu cu sistemuld e operare.
/// Asadar, pentru a nu exista probleme, am sa pun partea care coloreaza codul intr-un comentariu, insa acest lucru va face programul destul de greu de urmarit.
/// Am incercat o multime de alte metode de a scrie colorat insa nimic nu a mers, imi cer scuze, stiu ca este greu de urmarit programul fara :(

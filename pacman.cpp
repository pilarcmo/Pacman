#include "pacman.h"

Pacman::Pacman(){
    //Posicion aleatoria entre margenes [0 ROW, COL]
    int X=rand()%ROW;
    int Y=rand()%COL;
    //Comprobamos si es válida y si no cambiamos la posición:
    while(Juego::isBlocked(X,Y)==true){
        int aux1 =-1 + rand()%2, aux2=-1+rand()%2;
        X=X+aux1;
        Y=Y+aux2;
    }
    posPM.first=X;
    posPM.second=Y;
}

//int Pacman::chequeaVida(pair<int,int> pospm, pair <int,int> posf){
//    if(posf==pospm){Juego::restaVida();}
//    return vidas;
//}

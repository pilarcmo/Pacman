#include "pacman.h"

Pacman::Pacman(){
    posPM=Juego::randomStart();
}

int Pacman::chequeaVida(pair<int,int> pospm, pair <int,int> posf){
    if(posf==pospm){Juego::restaVida();}
    return vidas;
}

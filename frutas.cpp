#include "frutas.h"

Frutas::Frutas()
{
    posFr=Juego::randomStart();
}

int Frutas::existeFruta(pair<int, int> posPM){
    if(posPM.first==posFr.first && posPM.second==posFr.second){
        //Si la posicion del PM y de la fruta es igual se suman 10 puntos.
        Juego::marcadorUp10();
        posFr=Juego::randomStart();
    }
    return puntuacion;
}

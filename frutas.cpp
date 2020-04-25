#include "frutas.h"

Frutas::Frutas()
{
    int posX=rand()%ROW;
    int posY=rand()%COL;

    //Comprobamos si es válida y si no cambiamos la posición:
    while(Juego::isBlocked(posX,posY)==true){
        int aux1 =-1 + rand()%2, aux2=-1+rand()%2;
        posX=posX+aux1;
        posY=posY+aux2;
    }
    posFr.first=posX;
    posFr.second=posY;

}

int Frutas::existeFruta(pair<int, int> posPM){
    if(posPM.first==posFr.first && posPM.second==posFr.second){
        //Si la posición del PM y de la fruta es igual se suman 10 puntos.
        Juego::marcadorUp10();

        //Cambiamos la posición de la fruta a una nueva aleatoria (poner esta funcion de generar posicion aparte?):
        int posX=rand()%ROW;
        int posY=rand()%COL;
        //Comprobamos si es válida y si no cambiamos la posición:
        while(Juego::isBlocked(posX,posY)==true){
            int aux1 =-1 + rand()%2, aux2=-1+rand()%2;
            posX=posX+aux1;
            posY=posY+aux2;
        }
        posFr.first=posX;
        posFr.second=posY;
    }
    return puntuacion;
}

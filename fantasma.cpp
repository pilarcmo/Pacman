#include "fantasma.h"

Fantasma::Fantasma(){
    //Posicion aleatoria entre margenes [0 ROW, 0 COL]
    int posX=rand()%ROW;
    int posY=rand()%COL;

    //Comprobamos si es válida y si no cambiamos la posición:
    while(Juego::isBlocked(posX,posY)==true){
        int aux1 =-1 + rand()%2, aux2=-1+rand()%2;
        posX=posX+aux1;
        posY=posY+aux2;
    }
    posF.first=posX;
    posF.second=posY;
}
